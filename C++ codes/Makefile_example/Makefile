INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
CC = g++
CFLAGS = -I$(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.hpp)
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: hello_make hello_make_again

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

hello_make: $(OBJ_FILES) $(DEPS)
	$(CC) -o hello_make $(OBJ_FILES) $(CFLAGS)

hello_make_again: $(OBJ_FILES) $(DEPS)
	$(CC) -o hello_make_again $(OBJ_FILES) $(CFLAGS)

clean:
	rm -f hello_make $(OBJ_FILES)
