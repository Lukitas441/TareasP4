#include "headers/Turista.h"

// Constructores y destructores
Turista::Turista(){
};

Turista::~Turista(){
};

Turista::Turista(std::string ci, std::string nombre, std::string email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
};

// Getters
std::string Turista::getCI(){
    return this->ci;
};

std::string Turista::getNombre(){
    return this->nombre;
};

std::string Turista::getEmail(){
    return this->email;
};

// Setters
void Turista::setCI(std::string ci){
    this->ci = ci;
};

void Turista::setNombre(std::string nombre){
    this->nombre = nombre;
};

void Turista::setEmail(std::string email){
    this->email = email;
};

// Funciones
std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::list<std::string> Turista::listarExperiencias(DTFecha desde, float min, float max){
    return std::list<std::string>();
};
// Lo hace Santiago
