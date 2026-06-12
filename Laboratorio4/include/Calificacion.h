#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Usuario;
class Viaje;
class Reserva;

class Usuario;

class Calificacion {
private:
    Usuario* usuarioCalificador;
    int puntaje;
    DTFecha fecha;
    Reserva* reserva;

public:
    Calificacion(DTFecha fecha, int calificacion, Usuario* usuarioCalificador, Reserva* reserva);
    ~Calificacion();

    int getPuntaje();
    DTFecha getFecha();
    Usuario* getUsuarioCalificador();
    Reserva* getReserva();

    //MISING: mismaCalificacion
    Viaje* getCaliViaje();
    



};

#endif
