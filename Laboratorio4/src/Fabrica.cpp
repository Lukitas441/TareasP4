#include "../include/Fabrica.h"
#include "../include/controller/ControladorFechaActual.h"
#include "../include/controller/ControladorViajes.h"
#include "../include/controller/ControladorUsuarios.h"
#include "../include/controller/ControladorVehiculos.h"
#include "../include/interface/IControladorVehiculos.h"
#include "../include/interface/IControladorViajes.h"
#include "../include/interface/IControladorUsuarios.h"



Fabrica* Fabrica::instancia = nullptr;

Fabrica::Fabrica() {}

Fabrica* Fabrica::getInstance() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
};

IControladorFechaActual* Fabrica::getIControladorFechaActual() {
    return ControladorFechaActual::getInstance();
};

IControladorUsuarios* Fabrica::getIControladorUsuarios() {
    return ControladorUsuarios::getInstance();
};

IControladorViajes* Fabrica::getIControladorViajes() {
    return ControladorViajes::getInstance();
};

IControladorVehiculos* Fabrica::getIControladorVehiculos() {
    return ControladorVehiculos::getInstance();
};
