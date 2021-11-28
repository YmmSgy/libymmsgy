# subdirectory paths
HDR_DIR := include
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TEST_DIR := test

# targets and prerequisites
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIB := $(BIN_DIR)/libymmsgy.a

# compiler flags
CPPFLAGS := -I$(HDR_DIR) -MMD -MP
CFLAGS := -Wall -Werror
LDFLAGS := 
LDLIBS := 

.PHONY: all lib test clean

all: test

lib: $(LIB)

test: $(LIB)
	$(MAKE) -C $(TEST_DIR)

$(LIB): $(OBJ) | $(BIN_DIR)
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
