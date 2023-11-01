# Compiler
CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS := -lyatf

# Directories
BUILD_DIR := build
INC_DIR := include
SRC_DIR := src
TEST_DIR := tests

# Object files and test files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.cc))
TEST_FILES := $(patsubst $(TEST_DIR)/%.cc,$(BUILD_DIR)/%,$(wildcard $(TEST_DIR)/*.cc))

.PHONY: all check clean

all: $(OBJ_FILES) $(TEST_FILES)

# Compile test files
$(BUILD_DIR)/%: $(TEST_DIR)/%.cc $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INC_DIR) $^ -o $@

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Run test files
check: $(OBJ_FILES) $(TEST_FILES)
	@for test in $(TEST_FILES); do ./$$test; done

clean:
	rm -rf $(BUILD_DIR)