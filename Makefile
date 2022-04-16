TARGET = libfilesystem.so
TARGET_TEST = debug_test
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(SRC_DIRS)/file_io/file_erase.c
SRCS += $(SRC_DIRS)/file_io/file_read.c
SRCS += $(SRC_DIRS)/file_io/file_write.c
SRCS += $(SRC_DIRS)/cmd_handler.c
SRCS += $(SRC_DIRS)/file_utils.c
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))


CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -g -fPIC

LDFLAGS = -shared

.PHONY: test
.PHONY: run-test

GTEST_FLAGS := /usr/src/gtest/src/gtest_main.cc /usr/src/gtest/src/gtest-all.cc -I /usr/include -I /usr/src/gtest -L /usr/local/lib -lpthread
GTEST_SCRS := $(SRC_DIRS)/file_io/test/file_io_test.cpp
GTEST_DEPS := $(TARGET:%=$(BUILD_DIR)/%)

test: build $(BUILD_DIR)/$(TARGET_TEST)
run-test: test
	@echo Running GTests $(TARGET_TEST)
	@$(BUILD_DIR)/$(TARGET_TEST)

$(BUILD_DIR)/$(TARGET_TEST): $(GTEST_SCRS)
	@echo $(TARGET_TEST) : $<
	@$(CXX) $< -o $@ $(GTEST_FLAGS) $(GTEST_DEPS) $(INC_FLAGS)

.PHONY: build

build: $(BUILD_DIR)/$(TARGET) 

$(BUILD_DIR)/$(TARGET): $(OBJS)
	@echo Library created at $@
	@$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	@$(MKDIR_P) $(dir $@)
	@echo $(TARGET) : $<
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	@echo Removing $(BUILD_DIR)
	@$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p