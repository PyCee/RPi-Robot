SRC_PATH=./src
BUILD_PATH=./build
BIN_PATH=./bin
INCLUDE_PATH=./include

SOURCES=$(shell find $(SRC_PATH) -type f -name '*.cpp' )

CC=g++
CFLAGS=-g -std=c++17 \
	-Wall \
	-Wfloat-equal \
	-Wundef \
	-Wshadow \
	-Wpointer-arith \
	-Wcast-qual \
	-Wcast-align \
	-Wunreachable-code \
	-I$(INCLUDE_PATH)
LDFLAGS=

OBJECT_FILES=$(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

all: clean $(OBJECT_FILES)
$(BUILD_PATH)/%.o:$(SRC_PATH)/%.cpp
	@echo "Compiling file: $<"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@find ./ -type f \( -name '*~' \) -delete
	@rm -fr $(BUILD_PATH)/*
install:
	sh setup-env.sh
