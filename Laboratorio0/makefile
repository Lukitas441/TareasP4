# Nombre del ejecutable final
TARGET = principal

# El compilador a usar
CXX = g++

# Banderas (flags) para el compilador (estándar C++98 y mostrar advertencias)
#-std=c++98 significa que el programa compilara usando el 98 coso
#-Wall significa que todos las advertencias saltaran
# -I significa que va a buscar todos los archivos de la capeta actual
# -IClasses significa que va a buscar todos los archivos de la carpeta Classes
# -IDataType misma cosa pero en la carpeta DataType

#*********************TODO*****************************
# Si el make no funca muy probablemente el problema es aca, faltara una carpeta o algo qsy 

CXXFLAGS = -std=c++98 -Wall -I. -Iimplementacion -Iheaders

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
