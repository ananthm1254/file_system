#include "file_utils.h"
#include "file_names.h"
#include "defs.h"
#include<stdlib.h>
#include<string.h>

static char gFileNames[BLOCK_MAX_CNT][PAGE_MAX_CNT][256]; 

uint32_t FileEntryInit(void)
{
    //gFileEntry = (uint8_t *)malloc(FILE_SIZE * sizeof(uint8_t));
    return SUCCESS;
}