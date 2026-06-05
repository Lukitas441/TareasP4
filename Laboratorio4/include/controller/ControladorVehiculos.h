#ifndef CONTROLADORVEHICULOS_H
#define CONTROLADORVEHICULOS_H

#include "interface/IControladorVehiculos.h"
#include "DTVehiculosConductor.h"
#include "DTFecha.h"
#include <list>
#include <string>



class ControladorVehiculos : public IControladorVehiculos {
private:
    static ControladorVehiculos* instancia;
public:
    static ControladorVehiculos* getInstance();

    ControladorVehiculos();
    ~ControladorVehiculos();

    std::set<DTVehiculosConductor> ListarVehiculosConductor(
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