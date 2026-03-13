# Nombre del ejecutable final
TARGET = principal

# El compilador a usar
CXX = g++

# Banderas (flags) para el compilador (estándar C++17 y mostrar advertencias)
CXXFLAGS = -std=c++17 -Wall

# Regla principal: compila el archivo .cpp y genera el ejecutable
all:
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET)

#ATT: gemini