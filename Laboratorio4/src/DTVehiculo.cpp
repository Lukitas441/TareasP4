#include "../include/DTVehiculo.h"
//NUESTRO CREADO

DTVehiculo::DTVehiculo(std::string marca, std::string modelo){
    this->marca = marca;
    this->modelo = modelo; 
};

std::string DTVehiculo::getMarca(){
    return this->marca;
};

std::string DTVehiculo::getModelo(){
    return this->modelo;
};