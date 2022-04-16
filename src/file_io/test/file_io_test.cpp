#include "gtest/gtest.h"

extern "C" {
  #include "file_names.h"
  #include "cmd_handler.h"
  #include "file_utils.h"
  #include "defs.h"
}


TEST(TestFileRead, TestReadSuccess)
{
    ReadMsg_t readMsg;
    readMsg.address.block_address = 0;
    readMsg.address.page_address = 0;
    readMsg.buffPtr = NULL;

    ASSERT_EQ(FileRead(&readMsg), SUCCESS);
}


TEST(TestFileWrite, TestWriteSuccess)
{
    WriteMsg_t writeMsg;
    uint8_t entryArray[FILE_SIZE] = {0x0A, 0xF1};
    writeMsg.address.block_address = 0;
    writeMsg.address.page_address = 0;
    writeMsg.buffPtr = &entryArray[0];

    ASSERT_EQ(FileWrite(&writeMsg), SUCCESS);
}

TEST(TestFileWrite, TestWriteNullEntry)
{
    WriteMsg_t writeMsg;
    writeMsg.address.block_address = 0;
    writeMsg.address.page_address = 0;
    writeMsg.buffPtr = NULL;

    ASSERT_EQ(FileWrite(&writeMsg), FAILURE);
}


TEST(TestFileErase, TestEraseSuccess) 
{
    EraseMsg_t eraseMsg;
    eraseMsg.address.block_address = 0;
    eraseMsg.address.page_address = 0;
    eraseMsg.respQId = 0;

    ASSERT_EQ(FileErase(&eraseMsg), SUCCESS);
}

TEST(TestFileErase, TestEraseInvalidAddress) 
{
    EraseMsg_t eraseMsg;
    eraseMsg.address.block_address = 4;
    eraseMsg.address.page_address = 0;
    eraseMsg.respQId = 0;

    ASSERT_EQ(FileErase(&eraseMsg), FAILURE);
}