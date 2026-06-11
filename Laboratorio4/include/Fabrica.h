#ifndef FABRICA_H
#define FABRICA_H

#include "../include/interface/IControladorFechaActual.h"
#include "../include/interface/IControladorUsuarios.h"
#include "../include/interface/IControladorViajes.h"
#include "../include/interface/IControladorVehiculos.h"

class IControladorUsuarios;
class IControladorViajes;
class IControladorVehiculos;
class IControladorFechaActual;
class ControladorFechaActual;
class ControladorUsuarios;
class ControladorViajes;
class ControladorVehiculos;



class Fabrica {
private:
    static Fabrica * instancia;
    Fabrica();

public:
    static Fabrica * getInstance();
    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuarios* getIControladorUsuarios();
    IControladorViajes *getIControladorViajes();
    IControladorVehiculos* getIControladorVehiculos();
};

#endif
