#include <iostream>
#include <list>
#include "headers/DTExp.h"




// DataType: Exp (Experiencia)
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

//Sobrecargar el operador de inserción de flujo (<<) en un objeto std::ostream.
//Esta sobrecarga debe permitir imprimir todos los datos del datatype DTExpe siguiendo el
//siguiente formato:
//codigoReserva->descripcion(fecha)/turista1,turista2,.,turistaN,


std::ostream& operator<<(std::ostream& os, DTExp dtExp) {
    os << dtExp.codigoReserva << "->" << dtExp.descripcion << "(" << dtExp.fecha.getdia() << "/" << dtExp.fecha.getmes() << "/" << dtExp.fecha.getaño() << ")/"; 
    for (const auto& turista : dtExp.Turista) {
        os << turista << ",";
    }
    os << std::endl;
    return os;

}
    