INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
CC = gcc
CFLAGS = -I$(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: hw_reshape hw_test hw_time

hw_test: test_matmul.c $(OBJ_FILES) $(DEPS)
	$(CC) -o hw_test test_matmul.c $(OBJ_FILES) $(CFLAGS)

hw_reshape: test_reshape.c $(OBJ_FILES) $(DEPS)
	$(CC) -o hw_reshape test_reshape.c $(OBJ_FILES) $(CFLAGS)

hw_time: time_matmul.c $(OBJ_FILES) $(DEPS)
	$(CC) -o hw_time time_matmul.c $(OBJ_FILES) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f hw_test hw_time hw_reshape $(OBJ_DIR)/*.o
