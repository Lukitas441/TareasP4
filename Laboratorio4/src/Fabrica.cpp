#include "../include/Fabrica.h"
#include "../include/ControladorFechaActual.h"
#include "../include/controller/ControladorViajes.h"

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
