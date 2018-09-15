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
	-I$(INCLUDE_PATH) \
	-I$(RPI_ROBOT_INCLUDE_PATH)
LDFLAGS= 

OBJECT_FILES=$(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

OBJS=$(OBJECT_FILES) $(wildcard $(RPI_ROBOT_BUILD_PATH)/*)

TARGET=bin/robot_program

all: clean $(TARGET)
$(TARGET): $(OBJECT_FILES)
	@echo "Compiling target"
	@$(CC) -o $@ $(OBJS)
$(BUILD_PATH)/%.o:$(SRC_PATH)/%.cpp
	@echo "Compiling file: $<"
	@$(CC) $(CFLAGS) -c $< -o $@
run:
	@./$(TARGET)
clean:
	@find ./ -type f \( -name '*~' \) -delete
	@rm -fr $(BUILD_PATH)/*
install:
