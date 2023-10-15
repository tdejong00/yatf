# Version
MAJOR := 0
MINOR := 1

# Target
PROJECT_NAME := yatf
LIB_NAME := lib$(PROJECT_NAME)
TARGET := $(LIB_NAME).so
VERSIONED_TARGET := $(TARGET).$(MAJOR).$(MINOR)

# Compiler
CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -std=c++17
LDFLAGS := -shared -Wl,-emain,-soname,$(TARGET)

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
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BIN_DIR)/%.o,$(SRC_FILES))

.PHONY: all install uninstall clean

all: $(LIB_DIR)/$(VERSIONED_TARGET)

# Compile library
$(LIB_DIR)/$(VERSIONED_TARGET): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_FILES)

# Compile source files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

install:
	install -d $(LIB_INSTALL_DIR)
	install -m 755 $(LIB_DIR)/$(VERSIONED_TARGET) $(LIB_INSTALL_DIR)
	ldconfig
	install -d $(INC_INSTALL_DIR)
	cp -r $(INC_DIR)/* $(INC_INSTALL_DIR)

uninstall:
	rm $(LIB_INSTALL_DIR)/$(LIB_NAME).*
	rm -r $(INC_INSTALL_DIR)

clean:
	rm -rf $(BIN_DIR) $(LIB_DIR)