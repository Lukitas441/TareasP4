#include "Turista.h"


Turista::Turista(std::string ci, std::string nombre, std::string email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
};

Turista::~Turista(){        // Destructor
};

std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::list<std::string> Turista::listarExperiencias(DTFecha desde, float min, float max){
    return std::list<std::string>();
};
