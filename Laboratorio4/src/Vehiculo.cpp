#include "../include/Vehiculo.h"
#include "../include/DTConductor.h"
#include "../include/DTListarViaje.h"
#include "../include/DTVehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}

Vehiculo::~Vehiculo() {}

std::string Vehiculo::getMatricula(){ 
    return matricula;
};

int Vehiculo::getCapacidad(){ 
    return capacidad; 
};

std::string Vehiculo::getMarca(){ 
    return marca; 
};

std::string Vehiculo::getModelo(){ 
    return modelo;
};

TipoVehiculo Vehiculo::getTipo(){ 
    return tipo; 
};

std::set<Viaje*> Vehiculo::getViajes(){ 
    return viajes; 
};

Conductor * Vehiculo::getConductor(){ 
    return conductor; 
};

std::set<DTListarViaje> Vehiculo::getDTViajes(){
    std::set<DTListarViaje> dtViajes;
    for (const auto& viaje : viajes) {
            DTListarViaje dtViaje(viaje->getCodigo(), viaje->getFecha(), viaje->getOrigen(), viaje->getDestino(), conductor->getNickname());
        dtViajes.insert(dtViaje);
    }
    return dtViajes;
};

DTVehiculo Vehiculo::getInfoVehiculo(){
        DTVehiculo dtv(this->marca, this->modelo);
        return dtv;
};

DTConductor Vehiculo::getInfoConductor(){
    DTConductor dtc(this->conductor->getNombre(), this->conductor->getCalificacionPromedio());
    return dtc;
};

DTUsuarioViaje Vehiculo::getConductorVehiculo(){
   return this->conductor->getDatosConductor();
};

bool Vehiculo::hayViajesConductor(DTFecha fecha) {
    return this->conductor->hayViajesFechaConductor(fecha);
};

bool Vehiculo::hayViajesFecha(DTFecha fecha) {
    for (const auto& viaje : viajes) {
        if (viaje->getFecha() == fecha) {
            return true;
        }
    }
    return false;
};
