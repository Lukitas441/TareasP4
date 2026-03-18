#include <iostream>
#include <list>
#include "headers/DTExp.h"

// Constructores y destructores
DTExp::DTExp(){
};

DTExp::~DTExp(){
};

DTExp::DTExp(std::string codigoReserva, std::list<std::string> Turista, std::string descripcion, DTFecha fecha){
    this->codigoReserva = codigoReserva;
    this->Turista = Turista;
    this->descripcion = descripcion;
    this->fecha = fecha;
}

// Getters
std::string DTExp::getCodigoReserva(){
    return this->codigoReserva;
};
std::list<std::string> DTExp::getTurista(){
    return this->Turista;
};
std::string DTExp::getDescripcion(){
    return this->descripcion;
};
DTFecha DTExp::getFecha(){
    return this->fecha;
};

std::ostream& operator<<(std::ostream& os, DTExp dtExp) {
    os << dtExp.codigoReserva << "->" << dtExp.descripcion << "(" << dtExp.fecha.getDia() << "/" << dtExp.fecha.getMes() << "/" << dtExp.fecha.getAnio() << ")/"; 
    for (const auto& turista : dtExp.Turista) {
        os << turista << ",";
    }
    os << std::endl;
    return os;
}
    