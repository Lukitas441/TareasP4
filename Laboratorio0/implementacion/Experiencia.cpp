#include "headers/Experiencia.h"

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

