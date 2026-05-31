#ifndef DTVEHICULO_H
#define DTVEHICULO_H

#include <string>

//NUESTRO CREADO
class DTVehiculo {
private:
    std::string marca; 
    std::string modelo;

public:
    DTVehiculo(std::string marca, std::string modelo);
    std::string getMarca();
    std::string getModelo();
};

#endif