#include "../include/DTVehiculosConductor.h"
#include <string>
#include <vector>
DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad) {
    this->matricula = matricula;
    this->marca = marca;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const {
    return matricula;
}

std::string DTVehiculosConductor::getMarca() const {
    return marca;
}

int DTVehiculosConductor::getCapacidad() const {
    return capacidad;
}


