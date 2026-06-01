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
    std::set<class Pasajero*> pasajeros; // a chequer

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    int getAsientos();
    DTFecha getFecha();
    Viaje *getViaje();
    std::set<class Pasajero*> getPasajeros();

    std::set<DTUsuarioViaje *> getPasajerosReserva();
};

#endif
