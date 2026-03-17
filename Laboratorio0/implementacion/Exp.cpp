#include <iostream>
#include <list>
#include "DTExp.h"




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