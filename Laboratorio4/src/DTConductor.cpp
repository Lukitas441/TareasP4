#include "../include/DTConductor.h"
//NUESTRO CREADO
DTConductor::DTConductor(std::string nombre, float calificacionPromedio) {
    this->nombre = nombre;
    this->calificacionPromedio = calificacionPromedio;
};

std::string DTConductor::getNombre() {
    return this->nombre;
};

float DTConductor::getCalificacionPromedio() {
    return this->calificacionPromedio;
};



