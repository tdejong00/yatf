# Target
TARGET := yatf

# Version
MAJOR := 0
MINOR := 1
PATCH := 0
VERSION_FLAGS := -DMAJOR=$(MAJOR) -DMINOR=$(MINOR) -DPATCH=$(PATCH)

# Compiler
CC := g++
CFLAGS := -Wall -Wextra -std=c++17

# Directories
BUILD_DIR := .build
INC_DIR := include
SRC_DIR := src

# Install directory
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
INSTALL_DIR = $(DESTDIR)$(PREFIX)/bin

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(filter-out $(SRC_DIR)/main.cc,$(SRC_FILES)))

.PHONY: install uninstall check clean

# Compile target
$(BUILD_DIR)/$(TARGET): $(SRC_DIR)/main.cc $(OBJ_FILES) 
	$(CC) $(CFLAGS) -I$(INC_DIR) $(VERSION_FLAGS) $< -o $@ $(OBJ_FILES)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

install:
	install $(BUILD_DIR)/$(TARGET) $(INSTALL_DIR)

uninstall:
	rm $(INSTALL_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)