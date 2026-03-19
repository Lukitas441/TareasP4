#include "headers/Experiencia.h"
#include "headers/EventoCultural.h"
#include <iostream>

// Constructores y destructores
EventoCultural::EventoCultural(){
};

EventoCultural::~EventoCultural(){
};

EventoCultural::EventoCultural(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string ubicacion, bool usoCupon) : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->ubicacion = ubicacion;
    this->usoCupon = usoCupon;
};

// Getters
std::string EventoCultural::getUbicacion(){
    return this->ubicacion;
};

bool EventoCultural::getUsoCupon(){
    return this->usoCupon;
};

// Setters
void EventoCultural::setUbicacion(std::string ubicacion){
    this->ubicacion = ubicacion;
};

void EventoCultural::setUsoCupon(bool usoCupon){
    this->usoCupon = usoCupon;
};

// Funciones
float EventoCultural::calcularCosto(){ // Implementa Guille
        float costo = this->getPrecioBase() * this->getTuristas.length;
    if (this->getUsoCupon == true){
        costo -= 5* this->getTuristas.length;
    }
    return costo;
};
