#include "Viaje.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include "Calificacion.h"
#include "Conductor.h"
#include "Pasajero.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo ) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->reservas = std::set<Reserva*>();
    this->vehiculo = vehiculo;
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
    return this->vehiculo;
}


DTListarViaje Viaje::getDatosViaje() {
    
    DTListarViaje dtlv(codigo, fecha, origen, destino, this->vehiculo->getConductor()->getNickname());
    return dtlv;
}

DTUsuarioViaje Viaje::getConductorViaje() {
    DTUsuarioViaje dtuv = this->vehiculo->getConductorVehiculo();
    return dtuv;
}

bool Viaje::viajeCoincide(DTFecha fecha, std::string origen, std::string destino) {
    if (this->fecha == fecha && this->origen == origen && this->destino == destino) {
        return true;
    }
    return false;
}

bool Viaje::asientosCheck(int asientos) {
    int asientosReservados = 0;
    for (const auto& reserva : reservas) {
        asientosReservados += reserva->getAsientos();
    }
    return (asientosReservados + asientos) <= asientosPublicados;
}

DTConsultaViaje Viaje::constructorDTConsultaViaje(int asientos) {
    DTVehiculo dtv =  this->vehiculo->getInfoVehiculo();
    DTConsultaViaje dtcv(this->codigo, dtv.getMarca(), dtv.getModelo(), this->vehiculo->getConductor()->getNombre(), this->vehiculo->getConductor()->calificacionPromedio(), this->precio * asientos); 
    return dtcv;
}

bool Viaje::findPasajero(std::string nickname) {
    for (const auto& reserva : reservas) {
        if (reserva->getPasajero()->getNickname() == nickname) {
            return true;
        }
    }
    return false;
}

DTUsuarioViaje  Viaje::getUsuarioRes(std::string nickname) {
    for (const auto& reserva : reservas) {
        if (reserva->getPasajero()->getNickname() == nickname) {
            return reserva->getPasajeroReserva();
        }
    }
    return DTUsuarioViaje("", TipoUsuario::pasajero);
}

void Viaje::addRese(Reserva* reserva) {
    this->reservas.insert(reserva);
}