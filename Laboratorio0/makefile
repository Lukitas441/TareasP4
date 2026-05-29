
CXX = g++
CXXFLAGS = -std=c++98 -Wall -I. -Iheaders

SRC_ROOT := .
SRC_DIR := implementacion

MAIN_SRC := $(SRC_ROOT)/main.cpp
MAIN_OBJ := $(SRC_ROOT)/main.o

APP_SRCS := \
$(SRC_DIR)/DTFecha.cpp \
$(SRC_DIR)/DTExp.cpp \
$(SRC_DIR)/Experiencia.cpp \
$(SRC_DIR)/Alojamiento.cpp \
$(SRC_DIR)/EventoCultural.cpp \
$(SRC_DIR)/TourGuiado.cpp \
$(SRC_DIR)/Turista.cpp

APP_OBJS := $(APP_SRCS:.cpp=.o)

TARGET := main

.INTERMEDIATE: $(MAIN_OBJ) $(APP_OBJS)

.PHONY: all clean rebuild

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(APP_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	 rm -f $(TARGET) $(MAIN_OBJ) $(APP_OBJS)

rebuild: clean all
