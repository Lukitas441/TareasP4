#include "Classes/Experiencia.h"

Experiencia::Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha)
{
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
};

Experiencia::~Experiencia() {
};

std::string Experiencia::getCodigoReserva()
{
    return this->codigoReserva;
};

std::string Experiencia::getDescripcion()
{
    return this->descripcion;
};

int Experiencia::getPrecioBase()
{
    return this->precioBase;
};

DTFecha Experiencia::getFecha()
{
    return this->fecha;
};

DTExp Experiencia::getDT()
{
    DTExp dtExp(this->codigoReserva, this->turistas, this->descripcion, this->fecha);

    return dtExp;
}


float Experiencia::calcularCosto()
{
    return 0.0;
};

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