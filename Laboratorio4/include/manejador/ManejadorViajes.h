#ifndef MANEJADOR_VIAJES_H
#define MANEJADOR_VIAJES_H


#include "DTUsuario.h"
#include "DTFecha.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include "Viaje.h"

// pueden sobrar includes de Usuario

class Viaje;
class Usuario;
class Vehiculo;

class ManejadorViajes {

private:
    static ManejadorViajes * instance;
    std::map<int, Viaje*> viajes;
    int codigoViaje;
public:
    ManejadorViajes();
    static ManejadorViajes* getInstance();
    void agregarViaje(Viaje* viaje);
    Viaje* getViaje(int codigo);
    std::map<int, Viaje*> getViajes();
    void eliminarViaje(int codigo);
    Viaje crearViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo);
    int getCodigoViaje();
};

#endif