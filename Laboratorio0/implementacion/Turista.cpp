#include "headers/Turista.h"
#include "headers/Experiencia.h"

// Constructores y destructores
Turista::Turista(){
};

Turista::~Turista(){
    this->experiencias.clear(); // Limpiar la lista de experiencias del turista
    delete this;
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
std::list<Experiencia*> Turista::getExperiencias(){
    return this->experiencias;
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

void Turista::setExperiencias(Experiencia* experiencia){
    this->experiencias.push_back(experiencia);
};

// Funciones
std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::list<Experiencia*> Turista::listarExperiencias(DTFecha desde, float min, float max){
    std::list<Experiencia*>::iterator it = this->experiencias.begin();
    std::list<Experiencia*> experienciasFiltradas;
    
    while (it != this->experiencias.end()) {
        if((*it)->getFecha() > desde && (*it)->calcularCosto() >= min && (*it)->calcularCosto() <= max){
            experienciasFiltradas.push_back((*it));
        }
        it++;
    }
    return experienciasFiltradas;
};

void Turista::EliminarExperiencia(Experiencia* experiencia){
    this->experiencias.remove(experiencia);
};