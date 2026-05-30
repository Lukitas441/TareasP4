#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
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
std::set<Pasajero*> Reserva::getPasajeros() {
    return pasajeros;
}
std::set<DTUsuarioViaje*> Reserva::getPasajerosReserva() {
    std::set<DTUsuarioViaje*> pasajerosReserva;
    std::set<Pasajero*>::iterator it;
    for (it = pasajeros.begin(); it != pasajeros.end(); ++it) {
        DTUsuarioViaje* dtUsuarioViaje = new DTUsuarioViaje((*it)->getNickname(), Pasajero);
        pasajerosReserva.insert(dtUsuarioViaje);
    }
    return pasajerosReserva;
}