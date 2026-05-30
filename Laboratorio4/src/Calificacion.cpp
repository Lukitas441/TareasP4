#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

Calificacion::~Calificacion() {}

int Calificacion::getPuntaje() {
    return puntaje;
}
DTFecha Calificacion::getFecha() {
    return fecha;
}
Usuario* Calificacion::getUsuarioCalificador() {
    return usuarioCalificador;
}
Reserva* Calificacion::getReserva() {
    return reserva;
}
Viaje* Calificacion::getCaliViaje() {
    if (reserva != nullptr) {
        return reserva->getViaje();
    }
    return nullptr; // Si no hay reserva asociada, retorna nullptr
}