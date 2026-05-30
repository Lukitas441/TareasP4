#ifndef MANEJADOR_VIAJES_H
#define MANEJADOR_VIAJES_H

#include "DTViajes.h"
#include "Viaje.h"
#include "DTUsuario.h"
#include "Usuario.h"
#include "Conductor.h"
#include "Pasajero.h"
// pueden sobrar includes de Usuario

class ManejadorViajes {

private:
    static ManejadorViajes * instance;
    std::map<std::int, Viaje*> viajes;
    ManejadorViajes();

public:
    static ManejadorViajes * getInstance();

    Usuario* getUsuario(std::String nickname);

    std::set<Viaje*> getViajes();
    
    Viaje crearViaje(Vehiculo* v, Fecha fecha, std::String origen, std::String destino, int asientos, float precio);
}

#endif