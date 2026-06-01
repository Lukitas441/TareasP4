#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"

class IControladorViajes;

class Fabrica {
private:
    static Fabrica * instancia;

    Fabrica();

public:
    static Fabrica * getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorViajes* getIControladorViajes();
/*
    IVehiculo * getIVehiculo();
    IUsuario * getIUsuario();
    IViaje * getIViaje();
*/
    };

#endif
