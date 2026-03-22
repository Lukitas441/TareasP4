#include "headers/Turista.h"
#include "headers/Experiencia.h"

// Constructores y destructores
Turista::Turista(){
};

Turista::~Turista(){
    std::set<Experiencia*>::iterator it = this->experiencias.begin();
    while (it != this->experiencias.end()) {
        (*it)->eliminarTurista(this); // Eliminar el turista de la lista de turistas de la experiencia
        if ((*it)->getTuristas().empty()) { // Si la experiencia no tiene más turistas, eliminarla
            throw std::invalid_argument("La experiencia " + (*it)->getCodigoReserva() + " no tiene más turistas.");
        }
        it++;
    }
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
std::set<Experiencia*> Turista::getExperiencias(){
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
    this->experiencias.insert(experiencia);
};

// Funciones
std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::set<Experiencia*> Turista::listarExperiencias(DTFecha desde, float min, float max){
    std::set<Experiencia*>::iterator it = this->experiencias.begin();
    std::set<Experiencia*> experienciasFiltradas;
    
    while (it != this->experiencias.end()) {
        if((*it)->getFecha() > desde && (*it)->calcularCosto() >= min && (*it)->calcularCosto() <= max){
            experienciasFiltradas.insert((*it));
        }
        it++;
    }
    return experienciasFiltradas;
};
// Lo iba a hacer Santiago

void Turista::EliminarExperiencia(Experiencia* experiencia){
    this->experiencias.erase(experiencia);
};