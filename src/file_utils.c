#include "file_utils.h"
#include "file_names.h"
#include "defs.h"
#include<stdlib.h>
#include<string.h>

static char gFileNames[BLOCK_MAX_CNT][PAGE_MAX_CNT][256]; 

static uint32_t IsAddressValid(Address_t address)
{
    if((address.block_address < BLOCK_MAX_CNT) && 
       (address.page_address < PAGE_MAX_CNT))
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }

}

uint32_t FileEntryInit(void)
{
    //gFileEntry = (uint8_t *)malloc(FILE_SIZE * sizeof(uint8_t));
    return SUCCESS;
}


uint32_t FileErase(EraseMsg_t *eraseMsg)
{
    FILE* fptr;
    Address_t address = eraseMsg->address;
    uint8_t FileEntry[FILE_SIZE];

    if(IsAddressValid(eraseMsg->address) != SUCCESS)
    {
        return FAILURE;
    }

    // Open corresponding file
    fptr = fopen(gFileNames[address.block_address][address.page_address], "w");
    ASSERT(fptr);

    // Set file entry to zero
    memset(&FileEntry, 0, FILE_SIZE);

    //Write the zero entry to file
    fwrite(&FileEntry, FILE_SIZE, 1, fptr);

    fclose(fptr);

    return SUCCESS;
}


uint32_t FileWrite(WriteMsg_t *writeMsg)
{
    FILE* fptr;
    Address_t address = writeMsg->address;
    uint8_t FileEntry[FILE_SIZE];

    ASSERT(address.block_address < BLOCK_MAX_CNT);  // Check block address validity
    ASSERT(address.page_address < PAGE_MAX_CNT);    // Check page address validity

    // Open corresponding file
    fptr = fopen(gFileNames[address.block_address][address.page_address], "w");
    ASSERT(fptr);

    // Copy buffer memory data into local file entry
    memcpy(&FileEntry, writeMsg->buffPtr, FILE_SIZE);

    //Write the entry to file
    fwrite(&FileEntry, FILE_SIZE, 1, fptr);

    fclose(fptr);

    return SUCCESS;
}