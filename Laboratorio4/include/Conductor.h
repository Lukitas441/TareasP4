#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "Vehiculo.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <set>
#include <iostream>
#include <string>
#include "DTFecha.h"
#include "TipoVehiculo.h"

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;
    std::set<Vehiculo*> vehiculos;
public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();
    std::set<TipoLibreta> getLibretas();
    std::set<Vehiculo*> getVehiculos();
    bool libretaValida(TipoVehiculo tipo);
    std::set<DTListarViaje> getViajesTotales();
    DTUsuarioViaje getDatosConductor();
    bool hayViajesFechaConductor (DTFecha fecha);



};

#endif
