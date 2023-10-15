# Compiler
CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS := -lyatf

# Directories
BIN_DIR := bin
INC_DIR := include
SRC_DIR := src
TEST_DIR := test

# Sources
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BIN_DIR)/%.o,$(SRC_FILES))

# Tests
TEST_SRC_FILES := $(wildcard $(TEST_DIR)/*.cc)
TEST_FILES := $(patsubst $(TEST_DIR)/%.cc,$(BIN_DIR)/%,$(TEST_SRC_FILES))

.PHONY: all clean

all: $(TEST_FILES)

# Compile test files
$(BIN_DIR)/%: $(TEST_DIR)/%.cc $(OBJ_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(INC_DIR) $^ -o $@

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)