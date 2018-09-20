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
	-I$(INCLUDE_PATH)
#TODO: make LDFLAGS used in programs makefiles
LDFLAGS=-lncurses

OBJECT_FILES=$(SOURCES:$(SRC_PATH)/%.cpp=$(BUILD_PATH)/%.o)

all: $(OBJECT_FILES)
out:
	@echo $(OBJECT_FILES)
$(BUILD_PATH)/%.o:$(SRC_PATH)/%.cpp
	@echo "Compiling file: $@"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@find ./ -type f \( -name '*~' \) -delete
	@find $(BUILD_PATH) -type f \( -name '*.o' \) -delete
install:
	sudo apt-get install libncurses5-dev libncursesw5-dev
