#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include <set>
#include "Viaje.h"
#include "Conductor.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "DTFecha.h"
#include "TipoUsuario.h"
#include "DTConductor.h"
#include "DTVehiculo.h"
#include "DTVehiculosConductor.h"

class Conductor;
class DTConductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::set<Viaje*> viajes;
    Conductor* conductor;    

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo, Conductor* conductor);
    ~Vehiculo();
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    std::set<Viaje*> getViajes();
    Conductor* getConductor();
    std::set<DTListarViaje> getDTViajes();
    DTVehiculo getInfoVehiculo();
    DTConductor getInfoConductor();
    DTUsuarioViaje getConductorVehiculo();
    bool hayViajesConductor(DTFecha fecha);
    bool hayViajesFecha(DTFecha fecha);
    DTVehiculosConductor getDTVehiculosConductor();
};

#endif
