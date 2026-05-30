#ifndef RESERVA_H
#define RESERVA_H

#include <map>
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
    std::map<std::string, Pasajero*> pasajeros;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    int getAsientos();
    DTFecha getFecha();
    Viaje *getViaje();
    std::map<std::string, Pasajero*> getPasajeros();

    std::set<DTUsuarioViaje *> getPasajerosReserva();
};

#endif
