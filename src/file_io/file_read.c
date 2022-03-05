#include "file_io_utils.h"
#include "file_io_defs.h"
#include "defs.h"
#include "file_names.h"
#include<string.h>

uint32_t FileRead(ReadMsg_t *readMsg)
{
    FILE* fptr;
    Address_t address = readMsg->address;
    uint8_t FileEntry[FILE_SIZE];

    readMsg->buffPtr = (uint8_t *)malloc(FILE_SIZE);

    if (!IsAddressValid(address.block_address, address.page_address))
    {
        return FAILURE;
    }

    // Open corresponding file
    fptr = file_open(gFileNames[address.block_address][address.page_address]);
    ASSERT(fptr);

    //Read the entry from the file
    file_read(&FileEntry[0], fptr, FILE_SIZE);

    // Copy data from local entry into buffer memory
    memcpy(readMsg->buffPtr, &FileEntry, FILE_SIZE);
    
    if(readMsg->buffPtr == NULL)
    {
        return FAILURE;
    }

    file_close(fptr);

    return SUCCESS;
}