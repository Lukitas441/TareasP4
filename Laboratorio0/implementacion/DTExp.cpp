#include "headers/DTExp.h"

// Constructores y destructores
DTExp::DTExp(){
};

DTExp::~DTExp(){

};

DTExp::DTExp(std::string codigoReserva, std::set<std::string> Turistas, std::string descripcion, DTFecha fecha){
    this->codigoReserva = codigoReserva;
    this->turistas = Turistas;
    this->descripcion = descripcion;
    this->fecha = fecha;
};

// Getters
std::string DTExp::getCodigoReserva(){
    return this->codigoReserva;
};
std::set<std::string> DTExp::getTuristas(){
    return this->turistas;
};
std::string DTExp::getDescripcion(){
    return this->descripcion;
};
DTFecha DTExp::getFecha(){
    return this->fecha;
};

std::ostream& operator<<(std::ostream& os, DTExp dtExp) {
   
    os << dtExp.codigoReserva << "->" << dtExp.descripcion << "(" << dtExp.fecha.getDia() << "/" << dtExp.fecha.getMes() << "/" << dtExp.fecha.getAnio() << ")/"; // si va el /
    std::set<std::string>::const_iterator it = dtExp.turistas.begin();
    
    while (it != dtExp.turistas.end()) {
        os << *it;
        ++it;
        if (it != dtExp.turistas.end()) {
            os << ",";
        }
    }
    os << std::endl;
    return os;
};