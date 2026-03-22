#include "headers/Experiencia.h"
#include "headers/Turista.h"

// Constructores y destructores
Experiencia::Experiencia(){
};

Experiencia::~Experiencia(){
    std::set<Turista*>::iterator it = this->turistas.begin();
    while (it != this->turistas.end()) {
        (*it)->EliminarExperiencia(this); // Eliminar la experiencia de la lista de experiencias del turista
        it++;
    }

};

Experiencia::Experiencia(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha){
    this->codigoReserva = codigoReserva;
    this->descripcion = descripcion;
    this->precioBase = precioBase;
    this->fecha = fecha;
    this->turistas = std::set<Turista*>(); // Inicializo la lista de turistas como vacía
};

// Getters
std::set<Turista*> Experiencia::getTuristas(){
    return this->turistas;
};
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
    std::set<std::string> turistasCI;
    std::set<Turista*>::iterator it = this->turistas.begin();
    while (it != this->turistas.end()) {
        turistasCI.insert((*it)->getCI());
        it++;
    }

    return DTExp(this->codigoReserva, turistasCI, this->descripcion, this->fecha);
};

// Setters
void Experiencia::setCodigoReserva(std::string codigoReserva){
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
/*
void Experiencia::setDT(DTExp dt){ 
    this->codigoReserva = dt.getCodigoReserva();
    this->turistas = dt.getTurista();
    this->descripcion = dt.getDescripcion();
    this->fecha = dt.getFecha();
};
*/

// Funciones
float Experiencia::calcularCosto(){ // Implementa Guille
    return 0; // aca no va virtual porque no es una clase, ni se asigna valor porque:  no se inicializa? daba error antes
};

void Experiencia::agregarTurista(Turista *turista){
    this->turistas.insert(turista);
};

void Experiencia::eliminarTurista(Turista *turista){
    this->turistas.erase(turista); // Elimina el turista de la lista de turistas de la experiencia
};
