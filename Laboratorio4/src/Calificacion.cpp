#include "Calificacion.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Viaje.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* usuarioCalificador, Reserva* reserva) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificador = usuarioCalificador;
    this->reserva = reserva;
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


