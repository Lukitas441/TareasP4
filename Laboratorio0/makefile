# Nombre del ejecutable final
TARGET = principal

# El compilador a usar
CXX = g++

# Banderas (flags) para el compilador (estándar C++17 y mostrar advertencias)
CXXFLAGS = -std=c++17 -Wall

# Carpetas con código fuente
SRCDIRS = . clases datatypes

# Detecta todos los .cpp en las carpetas indicadas y genera objetos (.o)
SRC = $(wildcard $(addsuffix /*.cpp, $(SRCDIRS)))
OBJ = $(patsubst %.cpp, %.o, $(SRC))

.PHONY: all clean

# Regla principal: compila todos los .o y genera el ejecutable
all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(CXXFLAGS) $^ -o $@

# Regla para compilar cada .cpp a .o (sirve con rutas en subcarpetas)
%.o: %.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
clean:
    rm -f $(TARGET) $(OBJ)