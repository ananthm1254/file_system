#include "file_io_utils.h"
#include "file_io_defs.h"
#include "defs.h"
#include "file_names.h"
#include<string.h>

uint32_t FileRead(ReadMsg_t *readMsg)
{
    FILE* fptr;
    Address_t address = readMsg->address;
    uint8_t FileEntry[FILE_READ_CHUNK];

    readMsg->buffPtr = (uint8_t *)malloc(FILE_READ_CHUNK);

    if (!IsAddressValid(address.block_address, address.page_address))
    {
        return FAILURE;
    }

    // Open corresponding file
    fptr = file_open_read(gFileNames[address.block_address][address.page_address]);
    ASSERT(fptr);

    // Set cursor to offset 
    file_seek(fptr, address.offset*FILE_READ_CHUNK);

    //Read the entry from the file
    file_read(&FileEntry[0], fptr, FILE_READ_CHUNK);

    // Copy data from local entry into buffer memory
    memcpy(readMsg->buffPtr, &FileEntry, FILE_READ_CHUNK);
    
    if(readMsg->buffPtr == NULL)
    {
        return FAILURE;
    }

    file_close(fptr);

    return SUCCESS;
}