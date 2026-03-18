#include "Experiencia.h"
#include "EventoCultural.h"
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

std::string EventoCultural::getUsoCupon(){
    return this->usoCupon;
};

// Setters
std::string EventoCultural::setUbicacion(std::string ubicacion){
    this->ubicacion = ubicacion;
};

bool EventoCultural::setUsoCupon(bool usoCupon){
    this->usoCupon = usoCupon;
};

// Funciones
virtual float EventoCultural::calcularCosto(){ // Implementa Guille
    return 0.0;
};