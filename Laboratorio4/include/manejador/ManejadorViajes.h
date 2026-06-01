#ifndef MANEJADOR_VIAJES_H
#define MANEJADOR_VIAJES_H


#include "DTUsuario.h"
#include "DTFecha.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
// pueden sobrar includes de Usuario

class Viaje;
class Usuario;
class Vehiculo;

class ManejadorViajes {

private:
    static ManejadorViajes * instance;
    std::map<int, Viaje*> viajes;
public:
    ManejadorViajes();
    static ManejadorViajes* getInstance();

    void agregarViaje(Viaje* viaje);
    Viaje* getViaje(int codigo);
    std::map<int, Viaje*> getViajes();
    void eliminarViaje(int codigo);

};

#endif