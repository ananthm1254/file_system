#include "CppUTest/TestHarness.h"

extern "C" {
  #include "file_names.h"
  #include "cmd_handler.h"
  #include "file_utils.h"
  #include "defs.h"
}

TEST_GROUP(TestFileErase) {
  void setup() {
  }

  void teardown() {
  }
};

TEST(TestFileErase, TestEraseSuccess) {

  Address_t address;
  CmdMsg_t cmdMsg;
  address.block_address = 0;
  address.page_address = 0;
  cmdMsg.eraseMsg.address = address;

  CHECK_EQUAL(FileCmdHandler(FILE_ERASE, &cmdMsg), SUCCESS);
}

TEST(TestFileErase, TestEraseInvalidAddress) {

  Address_t address;
  CmdMsg_t cmdMsg;
  address.block_address = 4;
  address.page_address = 0;
  cmdMsg.eraseMsg.address = address;

  CHECK_EQUAL(FileCmdHandler(FILE_ERASE, &cmdMsg), FAILURE);
}