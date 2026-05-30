#ifndef MANEJADOR_VEHICULOS_H
#define MANEJADOR_VEHICULOS_H

#include "DTVehiculo.h"
#include "Vehiculo.h"
#include <map>
#include <set>

class ManejadorVehiculos {

private:
    static ManejadorVehiculos* instance;
    std::map<std::string, Vehiculo*> vehiculos;
    ManejadorVehiculos();

public:
    static ManejadorVehiculos* getInstance();

    Vehiculo* getVehiculo(std::string matricula);

    std::set<Vehiculo*> getVehiculos();
}

#endif