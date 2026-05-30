#ifndef RESERVA_H
#define RESERVA_H

#include <set>
#include "DTFecha.h"
#include "Viaje.h"
#include "Pasajero.h"
#include "DTUsuarioViaje.h"

class Reserva
{
private:
    int asientosReservados;
    DTFecha fecha;
    Viaje *viaje;
    std::set<class Pasajero*> pasajeros;

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
