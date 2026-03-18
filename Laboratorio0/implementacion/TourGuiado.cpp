#include "Experiencia.h"
#include "TourGuiado.h"
#include <iostream>

// Constructores y destructores
TourGuiado::TourGuiado(){
};

TourGuiado::~TourGuiado(){
};

TourGuiado::TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string agencia, std::list<std::string> lugaresVisitados) : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->agencia = agencia;
    this->lugaresVisitados = lugaresVisitados;
};

// Getters
std::string TourGuiado::getAgencia(){
    return this->agencia;
};

std::list<std::string> TourGuiado::getLugaresVisitados(){
    return this->lugaresVisitados;
};

// Setters
std::string TourGuiado::setAgencia(std::string agencia){
    this->agencia = agencia;
};

std::list<std::string> TourGuiado::setLugaresVisitados(std::list<std::string> lugaresVisitados){
    this->lugaresVisitados = lugaresVisitados;    
}

// Funciones
virtual float TourGuiado::calcularCosto(){ // Implementa Guille
    return 0.0;
};