#ifndef FABRICA_H
#define FABRICA_H

#include "IControladorFechaActual.h"
#include "interface/IControladorUsuarios.h"
#include "interface/IControladorViajes.h"
#include "interface/IControladorVehiculos.h"

class Fabrica {
private:
    static Fabrica * instancia;

    Fabrica();

public:
    static Fabrica * getInstance();

    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuarios* getIControladorUsuarios();
    IControladorViajes* getIControladorViajes();
    IControladorVehiculos* getIControladorVehiculos();

};

#endif
