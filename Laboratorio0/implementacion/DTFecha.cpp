#include "DTFecha.h"


// Constructores y destructores
DTFecha::DTFecha(){
    this->dia = 1;
    this->mes = 1;
    this->anio = 1;
};

DTFecha::~DTFecha(){
};

DTFecha::DTFecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

// Getters
int DTFecha::getdia(){
    return this->dia; 
};

int DTFecha::getmes(){
    return this->mes;
};

int DTFecha::getanio(){
    return this->anio;
};