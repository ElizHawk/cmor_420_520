INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
CC = gcc
CFLAGS = -I$(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c test_matmul.c time_matmul.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

hw: $(OBJ_FILES) $(DEPS)
	$(CC) -o hw $(OBJ_FILES) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f hw $(OBJ_DIR)/*.o
