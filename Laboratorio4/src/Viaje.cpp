#include "../include/Viaje.h"
#include <string>
#include <set>


Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vechiculo ) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->reservas = std::set<Reserva*>();
    this->vechiculo = vechiculo;
};

Viaje::~Viaje() {};

int Viaje::getCodigo() {
   return codigo;
}

DTFecha Viaje::getFecha() {
    return fecha;
}

std::string Viaje::getOrigen() {
    return origen;
}

std::string Viaje::getDestino() {
    return destino;
}

int Viaje::getAsientosPublicados() {
   return asientosPublicados;
}

float Viaje::getPrecio() {
    return precio;
}

std::set<Reserva*> Viaje::getReservas() {
    return reservas;
}

Vehiculo* Viaje::getVehiculo() {
    return this->vechiculo;
}


DTListarViaje Viaje::getDatosViaje() {
    
    DTListarViaje dtlv(codigo, fecha, origen, destino, this->vechiculo->getConductor()->getNickname());
    return dtlv;
}

