#ifndef CONTROLADORVEHICULOS_H
#define CONTROLADORVEHICULOS_H

#include "../include/interface/IControladorVehiculos.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include <list>
#include <set>
#include <string>



class ControladorVehiculos : public IControladorVehiculos {
private:
    static ControladorVehiculos* instancia;
    ControladorVehiculos();

public:
    static ControladorVehiculos* getInstance();
    ~ControladorVehiculos();

    std::list<DTVehiculosConductor> ListarVehiculosConductor(
        std::string nickname
    ) override;

    bool AltaViaje(
        std::string matricula,
        DTFecha fecha, 
        std::string origen, 
        std::string destino,
        int asientos,
        float precio
    ) override;
};

#endif