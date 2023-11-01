# Version
MAJOR := 0
MINOR := 1

# Target
PROJECT_NAME := yatf
LIB_NAME := lib$(PROJECT_NAME)
TARGET := $(LIB_NAME).so
VERSIONED_TARGET := $(TARGET).$(MAJOR).$(MINOR)

# Directories
BUILD_DIR := build
INC_DIR := include
SRC_DIR := src

# Compiler
COMPILER := g++
CPP_VERSION := -std=c++11
CFLAGS := -Wall -Wextra -Wpedantic $(CPP_VERSION)
LDFLAGS := -shared -Wl,-emain,-soname,$(TARGET)

# Linter
LINTER := clang-tidy
LFLAGS := -config='' -header-filter=$(INC_DIR)/ -- $(CPP_VERSION) -I$(INC_DIR)

# Install directories
ifeq ($(PREFIX),)
    PREFIX := /usr/local
endif
LIB_INSTALL_DIR = $(DESTDIR)$(PREFIX)/lib
INC_INSTALL_DIR = $(DESTDIR)$(PREFIX)/include/$(PROJECT_NAME)

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRC_FILES))

.PHONY: default install uninstall lint clean

default: $(BUILD_DIR)/$(VERSIONED_TARGET)

# Compile library
$(BUILD_DIR)/$(VERSIONED_TARGET): $(OBJ_FILES)
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ_FILES)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	$(COMPILER) $(CFLAGS) -I$(INC_DIR) -fPIC -c $< -o $@

# Install library
install:
	install -d $(LIB_INSTALL_DIR)
	install -m 755 $(BUILD_DIR)/$(VERSIONED_TARGET) $(LIB_INSTALL_DIR)
	ldconfig
	install -d $(INC_INSTALL_DIR)
	cp -r $(INC_DIR)/* $(INC_INSTALL_DIR)

# Uninstall library
uninstall:
	rm $(LIB_INSTALL_DIR)/$(LIB_NAME).*
	rm -r $(INC_INSTALL_DIR)

# Run linter
lint: $(BUILD_DIR)/$(VERSIONED_TARGET)
	$(LINTER) $(SRC_FILES) $(LFLAGS)

# Clean object files
clean:
	rm -rf $(BUILD_DIR)