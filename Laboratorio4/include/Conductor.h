#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include <list>
#include <map>
#include <iostream>
#include <string>
#include "DTFecha.h"
#include "TipoVehiculo.h"
#include "DTVehiculosConductor.h"

class Vehiculo;
class Conductor : public Usuario {
private:
    std::map<TipoLibreta, bool> libretas;
    std::list<Vehiculo*> vehiculos;
public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::map<TipoLibreta, bool> libs);
    ~Conductor();
    void agregarVehiculo(Vehiculo* vehiculo);
    std::map<TipoLibreta, bool> getLibretas();
    std::list<Vehiculo*> getVehiculos();
    bool libretaValida(TipoVehiculo tipo);
    std::list<DTListarViaje> getViajesTotales();
    DTUsuarioViaje *getDatosConductor();
    bool hayViajesFechaConductor (DTFecha fecha);
    std::list<DTVehiculosConductor> listarVehiculos();
    
};

#endif
