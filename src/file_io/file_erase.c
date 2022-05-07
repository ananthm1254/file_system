#include "file_io_utils.h"
#include "file_io_defs.h"
#include "defs.h"
#include "file_names.h"

uint32_t FileErase(EraseMsg_t *eraseMsg)
{
    FILE* fptr;
    Address_t address = eraseMsg->address;
    uint8_t FileEntry[FILE_SIZE];

    if (!IsAddressValid(address.block_address, address.page_address))
    {
        return FAILURE;
    }

    // Open corresponding file
    fptr = file_open_write(gFileNames[address.block_address][address.page_address]);
    ASSERT(fptr);

    // Set file entry to zero
    memset(&FileEntry, 0, FILE_SIZE);

    //Write the zero entry to file
    file_write(&FileEntry[0], fptr, FILE_SIZE);

    file_close(fptr);

    return SUCCESS;
}
