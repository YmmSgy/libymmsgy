# subdirectory paths
HDR_DIR := ../include
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

# targets and prerequisites
SRC := $(wildcard $(SRC_DIR)/*.c)
EXE := $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.exe)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# compiler flags
CPPFLAGS := -I$(HDR_DIR) -MMD -MP
CFLAGS := -Wall -Werror
LDFLAGS := 
LDLIBS := ../bin/*.a

.PHONY: all clean

all: $(EXE)

$(BIN_DIR)/%.exe: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CC) $(LDFLAGS) $< $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
