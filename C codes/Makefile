INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
CC = gcc
CFLAGS = -I$(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) test_*.c time_*.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: hw

hw: $(OBJ_FILES) $(DEPS)
	$(CC) -o hw $(OBJ_FILES) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f hw $(OBJ_FILES)
