# Version
MAJOR := 0
MINOR := 1

# Target
PROJECT_NAME := yatf
LIB_NAME := lib$(PROJECT_NAME).so

# Compiler
CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS := -l$(PROJECT_NAME)

# Directories
BIN_DIR := bin
LIB_DIR := lib
INC_DIR := include
SRC_DIR := src

# Install directories
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
LIB_INSTALL_DIR = $(DESTDIR)$(PREFIX)/lib
INC_INSTALL_DIR = $(DESTDIR)$(PREFIX)/include/$(PROJECT_NAME)

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BIN_DIR)/%.o,$(filter-out $(SRC_DIR)/main.cc,$(SRC_FILES)))

.PHONY: all install uninstall clean

all: $(LIB_DIR)/$(LIB_NAME) $(BIN_DIR)/$(PROJECT_NAME)

# Compile library
$(LIB_DIR)/$(LIB_NAME): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJ_FILES)

# Compile target
$(BIN_DIR)/$(PROJECT_NAME): $(SRC_DIR)/main.cc $(OBJ_FILES) 
	$(CC) $(CFLAGS) -I$(INC_DIR) $< -o $@ $(OBJ_FILES)

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

install:
	install -d $(LIB_INSTALL_DIR)
	install -m 755 $(LIB_DIR)/$(LIB_NAME) $(LIB_INSTALL_DIR)
	install -d $(INC_INSTALL_DIR)
	cp -r $(INC_DIR)/* $(INC_INSTALL_DIR)

uninstall:
	rm $(LIB_INSTALL_DIR)/$(LIB_NAME)
	rm -r $(INC_INSTALL_DIR)

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)