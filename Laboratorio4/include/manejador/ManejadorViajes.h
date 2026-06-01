#ifndef MANEJADOR_VIAJES_H
#define MANEJADOR_VIAJES_H

#include "Viaje.h"
#include "DTUsuario.h"
#include "Usuario.h"
#include "Conductor.h"
#include "Pasajero.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
// pueden sobrar includes de Usuario

class ManejadorViajes {

private:
    static ManejadorViajes * instance;
    std::map<int, Viaje*> viajes;
    ManejadorViajes();

public:
    static ManejadorViajes * getInstance();

    Usuario* getUsuario(std::string nickname);

    std::set<Viaje*> getViajes();
    
    Viaje crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio);
};

#endif