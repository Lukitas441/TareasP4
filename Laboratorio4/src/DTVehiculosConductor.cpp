#include "../include/DTVehiculosConductor.h"
#include <string>
#include <vector>
DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const {
    return matricula;
}

std::string DTVehiculosConductor::getModelo() const {
    return modelo;
}

int DTVehiculosConductor::getCapacidad() const {
    return capacidad;
}


