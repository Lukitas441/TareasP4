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
    Viaje* viaje;

public:
    Calificacion(DTFecha fecha, int calificacion, Usuario* usuarioCalificador, Viaje* viaje);
    ~Calificacion();

    int getPuntaje();
    DTFecha getFecha();
    Usuario* getUsuarioCalificador();

    Viaje* getCaliViaje();
    



};

#endif
