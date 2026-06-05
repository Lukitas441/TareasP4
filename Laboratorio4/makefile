CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS  :=

SRC_DIR  := src
OBJ_DIR  := obj
BIN      := app

SRCS     := $(wildcard $(SRC_DIR)/*.cpp)
OBJS     := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean rebuild

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(BIN)

rebuild: clean all