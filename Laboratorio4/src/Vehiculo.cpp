#include "Vehiculo.h"
#include "Viaje.h"
#include "Conductor.h"
#include "DTDetalleVehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor* conductor) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = conductor;

    conductor->getVehiculos().push_back(this);
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

void Vehiculo::addViaje(Viaje* viaje) {
    this->viajes.insert(viaje);
};

void Vehiculo::insertarConductor(Conductor* conductor) {
    this->conductor = conductor;
    conductor->getVehiculos().push_back(this);
};

std::list<DTListarViaje> Vehiculo::getDTViajes(){
    std::list<DTListarViaje> dtViajes;
    for (const auto& viaje : viajes) {
            DTListarViaje dtViaje(viaje->getCodigo(), viaje->getFecha(), viaje->getOrigen(), viaje->getDestino(), conductor->getNickname());
        dtViajes.push_back(dtViaje);
    }
    return dtViajes;
};

DTVehiculo Vehiculo::getInfoVehiculo(){
        DTVehiculo dtv(this->marca, this->modelo);
        return dtv;
};

DTConductor Vehiculo::getInfoConductor(){
    DTConductor dtc(this->conductor->getNombre(), this->conductor->calificacionPromedio());
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

DTVehiculosConductor Vehiculo::getDTVehiculoConductor() {
    DTVehiculosConductor dtvc(this->matricula, this->modelo, this->capacidad);
    return dtvc;
};

void Vehiculo::asociarViaje(Viaje viaje) {
    this->viajes.insert(&viaje);
};
