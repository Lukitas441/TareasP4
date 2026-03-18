#include "headers/Alojamiento.h"
Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, enum TipoRegimen tipoRegimen, int cantNoches) : Experiencia(codigoReserva, descripcion, precioBase, fecha) {
    this->hotel = hotel;
    this->regimen = tipoRegimen;
    this->cantNoches = cantNoches;
}

Alojamiento::~Alojamiento() {
};

std::string Alojamiento::getHotel() {
    return this->hotel;
}

TipoRegimen Alojamiento::getRegimen() {
    return this->regimen;
}

int Alojamiento::getCantNoches() {
    return this->cantNoches;
}

float Alojamiento::calcularCosto() {
    //TODO: Implementar el cálculo del costo para Alojamiento
    return 0.0;
}