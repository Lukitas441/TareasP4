#include "headers/Alojamiento.h"
#include <iostream>
#include "Alojamiento.h"

// Constructores y destructores
Alojamiento::Alojamiento(){
};

Alojamiento::~Alojamiento(){
};

Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, enum TipoRegimen tipoRegimen, int cantNoches) : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->hotel = hotel;
    this->regimen = tipoRegimen;
    this->cantNoches = cantNoches;
};

// Getters
std::string Alojamiento::getHotel(){
    return this->hotel;
};

TipoRegimen Alojamiento::getRegimen(){
    return this->regimen;
};

int Alojamiento::getCantNoches(){
    return this->cantNoches;
};

// Setters
void Alojamiento::setHotel(std::string hotel){
    this->hotel = hotel;
};

void Alojamiento::setRegimen(TipoRegimen regimen){
    this->regimen = regimen;
};

void Alojamiento::setCantNoches(int cantNoches){
    this->cantNoches = cantNoches;
};

 float Alojamiento::calcularCosto(){ // Implementa Guille
    return 0.0;
};