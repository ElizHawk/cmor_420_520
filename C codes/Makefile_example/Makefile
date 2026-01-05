INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
CC = gcc
CFLAGS = -I$(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: hello_make hello_make_again

hello_make: $(OBJ_FILES) $(DEPS)
	$(CC) -o hello_make $(OBJ_FILES) $(CFLAGS)

hello_make_again: $(OBJ_FILES) $(DEPS)
	$(CC) -o hello_make_again $(OBJ_FILES) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f hello_make $(OBJ_FILES)
