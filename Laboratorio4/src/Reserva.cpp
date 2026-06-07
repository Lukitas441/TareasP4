#include "Reserva.h"
#include "Viaje.h"
#include "Pasajero.h"

Reserva::Reserva(int asientosReservados,Pasajero * pasajero ,DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->pasajero = pasajero;
    this->fecha = fecha;
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
DTUsuarioViaje Reserva::getPasajeroReserva() {
    DTUsuarioViaje dtuv =  DTUsuarioViaje(pasajero->getNickname(), TipoUsuario::pasajero);
    return dtuv;
}