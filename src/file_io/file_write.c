#include "file_io_utils.h"
#include "file_io_defs.h"
#include "defs.h"
#include "file_names.h"
#include<string.h>

uint32_t FileWrite(WriteMsg_t *writeMsg)
{
    FILE* fptr;
    Address_t address = writeMsg->address;
    uint8_t FileEntry[FILE_SIZE];

    if (!IsAddressValid(address.block_address, address.page_address))
    {
        return FAILURE;
    }

    if(writeMsg->buffPtr == NULL)
    {
        return FAILURE;
    }

    // Open corresponding file
    fptr = file_open_write(gFileNames[address.block_address][address.page_address]);
    ASSERT(fptr);

    // Copy buffer memory data into local file entry
    memcpy(&FileEntry, writeMsg->buffPtr, FILE_SIZE);

    //Write the entry to file
    file_write(&FileEntry[0], fptr, FILE_SIZE);

    file_close(fptr);

    return SUCCESS;
}