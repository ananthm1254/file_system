#pragma once
#include "defs.h"
#include "file_utils.h"
#include "file_io_defs.h"

typedef enum _FileOp_t {
    FILE_INIT,
    FILE_ERASE,
    FILE_WRITE,
    FILE_READ,
    FILE_OP_CNT
} FileOp_t;

typedef enum _FileResp_t {
    FILE_OP_SUCCESS,
    FILE_OP_INVALID_ADDRESS,
    FILE_OP_,
    FILE_OP_ERROR,
    FILE_OP_FAILURE,
    FILE_OP_RESP_CNT
} FileResp_t;

typedef union _CmdMsg_t
{
    EraseMsg_t eraseMsg;
} CmdMsg_t;


uint32_t FileCmdHandler(FileOp_t cmd, CmdMsg_t *cmdMsg);