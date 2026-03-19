#include "headers/Experiencia.h"

// Constructores y destructores
Experiencia::Experiencia(){
};

Experiencia::~Experiencia(){
};

Experiencia::Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha){
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
    // lo de lucas: this->turistas = std::list<std::string>();
};

// Getters
std::string Experiencia::getCodigoReserva(){
    return this->codigoReserva;
};

std::string Experiencia::getDescripcion(){
    return this->descripcion;
};

int Experiencia::getPrecioBase(){
    return this->precioBase;
};

DTFecha Experiencia::getFecha(){
    return this->fecha;
};

DTExp Experiencia::getDT(){
    return DTExp(this->codigoReserva, this->turistas, this->descripcion, this->fecha);
}

// Setters
void Experiencia::setCodigoReserva(std::string codigoReserva){
    this->codigoReserva = codigoReserva;
};

void Experiencia::setDescripcion(std::string descripcion){
    this->descripcion = descripcion;
};

void Experiencia::setPrecioBase(int precioBase){
    this->precioBase = precioBase;
};

void Experiencia::setFecha(DTFecha fecha){
    this->fecha = fecha;
};

// dudoso el seter de DT, no se si es necesario, pero lo hago igual.
void Experiencia::setDT(DTExp dt){ 
    this->codigoReserva = dt.getCodigoReserva();
    this->turistas = dt.getTurista();
    this->descripcion = dt.getDescripcion();
    this->fecha = dt.getFecha();
};

// Funciones
float Experiencia::calcularCosto(){ // Implementa Guille
       virtual float calcularCosto() = 0;
};
