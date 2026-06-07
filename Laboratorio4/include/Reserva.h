#ifndef RESERVA_H
#define RESERVA_H

#include <set>
#include "DTFecha.h"
#include "DTUsuarioViaje.h"

class Pasajero;
class Viaje;

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;
    Viaje *viaje;
    Pasajero *pasajero; 

public:
    Reserva(int asientosReservados, Pasajero *pasajero, DTFecha fecha);
    ~Reserva();

    int getAsientos();
    DTFecha getFecha();
    Viaje *getViaje();
    Pasajero *getPasajero();
    DTUsuarioViaje getPasajeroReserva();
};

#endif
