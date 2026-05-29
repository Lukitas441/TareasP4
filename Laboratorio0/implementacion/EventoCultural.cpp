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

// calcular costo de un evento cultural es: "la operación retorna el precio base multiplicado por la cantidad de turistas participantes y se resta 5 unidades por cada turista si se utiliza cupón de descuento."
float EventoCultural::calcularCosto(){ // Implementa Guille

    float costo = this->getPrecioBase() * this->getTuristas().size(); // aca el error era no tener un getter de turista implementado en EXPERIENCIA y usar .lengh en un lista de string donde lo correcto es .size()

    if (this->getUsoCupon() == true){ // aca getUsoCupon es una funcion entonces termina con ()

        costo -= 5* this->getTuristas().size();
    }
    return costo;
};
