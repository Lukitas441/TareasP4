#include <iostream>
#include <list>
#include "DataTypes.h"

// Metodos de los DataTypes

// DataType: Fecha
int DTFecha::getdia(){
    return this->Dia;
};
int DTFecha::getmes(){
    return this->Mes;
};
int DTFecha::getaño(){
    return this->Año;
};

//DataType: Exp (Experiencia)
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