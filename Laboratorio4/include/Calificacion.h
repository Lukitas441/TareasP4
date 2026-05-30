#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"
#include "Usuario.h"
#include "Reserva.h"
#include "Viaje.h"

class Calificacion {
private:
    Usuario* usuarioCalificador;
    int puntaje;
    DTFecha fecha;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int calificacion);
    ~Calificacion();

    int getPuntaje();
    DTFecha getFecha();
    Usuario* getUsuarioCalificador();
    Reserva* getReserva();

    //MISING: mismaCalificacion
    Viaje* getCaliViaje();
    



};

#endif
