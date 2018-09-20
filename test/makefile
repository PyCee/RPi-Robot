SRC_PATH=./src
BUILD_PATH=./build
BIN_PATH=./bin
INCLUDE_PATH=./include

SOURCES=$(shell find $(SRC_PATH) -type f -name '*.cpp' )

CC=g++
CFLAGS=-g -std=c++98 \
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
LDFLAGS= -lncurses

OBJECT_FILES=$(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

OBJS=$(OBJECT_FILES) $(wildcard $(RPI_ROBOT_BUILD_PATH)/**.o) \
	$(wildcard $(RPI_ROBOT_BUILD_PATH)/**/*.o)

TARGET=bin/robot_program

all: clean $(TARGET)
out:
	@echo $(OBJS)
$(TARGET): $(OBJECT_FILES)
	@echo "Compiling target"
	@$(CC) -o $@ $(OBJS) $(LDFLAGS)
$(BUILD_PATH)/%.o:$(SRC_PATH)/%.cpp
	@echo "Compiling file: $<"
	@$(CC) $(CFLAGS) -c $< -o $@
run:
	@./$(TARGET)
clean:
	@find ./ -type f \( -name '*~' \) -delete
	@rm -fr $(BUILD_PATH)/*
install:
