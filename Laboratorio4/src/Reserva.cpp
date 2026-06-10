#include "Reserva.h"
#include "Viaje.h"
#include "Pasajero.h"
#include "../include/manejador/ManejadorUsuarios.h"


Reserva::Reserva(int asientosReservados, Pasajero *pasajero, DTFecha fecha, Viaje *viaje) {
    this->asientosReservados = asientosReservados;
    this->pasajero = pasajero;
    this->fecha = fecha;
    this->viaje = viaje;
}

Reserva::~Reserva() {}

int Reserva::getAsientos() {
    return asientosReservados;
}
DTFecha Reserva::getFecha() {
    return fecha;
}
Viaje* Reserva::getViaje() {
    return viaje;
}
Pasajero* Reserva::getPasajero() {
    return  pasajero;
}
DTUsuarioViaje* Reserva::getPasajeroRes() {
    ManejadorUsuarios *mu = ManejadorUsuarios::getInstance();
    std::string nicknameCalificador = mu->getNicknameCalificador();
    if (nicknameCalificador !=  pasajero->getNickname()){
        return pasajero->getDatosPasajero();
    }
    return nullptr;
}