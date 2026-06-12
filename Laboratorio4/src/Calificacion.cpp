#include "Calificacion.h"
#include "Usuario.h"
#include "Viaje.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* usuarioCalificador, Viaje* viaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificador = usuarioCalificador;
    this->viaje = viaje;
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
Viaje* Calificacion::getCaliViaje() {
    return viaje;
}
