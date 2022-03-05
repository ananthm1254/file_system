#include "defs.h"
#include "file_utils.h"
#include "cmd_handler.h"
#include "file_io_defs.h"
#include <stdio.h>

uint32_t FileCmdHandler(FileOp_t cmd, CmdMsg_t *cmdMsg)
{
    uint32_t retVal = SUCCESS;
    switch (cmd)
    {
        case FILE_INIT:
        {
            if(FileEntryInit() != SUCCESS)
            {
                retVal = FAILURE;
            }

            break;
        }
        
        case FILE_ERASE:
        {
            EraseMsg_t eraseMsg = cmdMsg->eraseMsg;
            if(FileErase(&eraseMsg) != SUCCESS)
            {
                retVal = FAILURE;
            }

            break;
        }
/*
        case FILE_WRITE:
        {
            if(FileWrite() != SUCCESS)
            {
                retVal = FAILURE;
            }
            
            break;
        }

        case FILE_READ:
        {
            if(FileRead() != SUCCESS)
            {
                retVal = FAILURE;
            }
            
            break;
        }
 */       
        default:
            printf("Invalid Operation");
            break;
    }
    return retVal;
}