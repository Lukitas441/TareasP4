#include "headers/Experiencia.h"
#include "headers/TourGuiado.h"
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
void TourGuiado::setAgencia(std::string agencia){
    this->agencia = agencia;
};

void TourGuiado::setLugaresVisitados(std::list<std::string> lugaresVisitados){
    this->lugaresVisitados = lugaresVisitados;    
};

// Funciones
float TourGuiado::calcularCosto(){ // Implementa Guille
        float costo = (this->getPrecioBase() + 2) * this->getLugaresVisitados() * this->getTuristas.length;
    return costo;
};
