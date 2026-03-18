#include "headers/Alojamiento.h"
#include <iostream>

// Constructores y destructores
Alojamiento::Alojamiento(){
};

Alojamiento::~Alojamiento(){
};

Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, enum TipoRegimen tipoRegimen, int cantNoches) : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->hotel = hotel;
    this->regimen = tipoRegimen;
    this->cantNoches = cantNoches;
}

// Getters
std::string Alojamiento::getHotel(){
    return this->hotel;
}

TipoRegimen Alojamiento::getRegimen(){
    return this->regimen;
}

int Alojamiento::getCantNoches(){
    return this->cantNoches;
}

// Setters
std::string Alojamiento::setHotel(std::string hotel){
    this->hotel = hotel;
}

TipoRegimen Alojamiento::setRegimen(TipoRegimen regimen){
    this->regimen = regimen;
}

int Alojamiento::setCantNoches(int cantNoches){
    this->cantNoches = cantNoches;
}

virtual float Alojamiento::calcularCosto(){ // Implementa Guille
    return 0.0;
}