#ifndef ICONTROLADORVEHICULOS_H
#define ICONTROLADORVEHICULOS_H

#include "DTVehiculosConductor.h"
#include <list>
#include <string>
#include "DTFecha.h"

class IControladorVehiculos {
public:
    virtual ~IControladorVehiculos() = default;

    virtual std::set<DTVehiculosConductor> ListarVehiculosConductor(
        std::string nickname
    ) = 0;

    virtual bool AltaViaje(
        std::string matricula,
        DTFecha fecha, 
        std::string origen, 
        std::string destino,
        int asientos,
        float precio
    ) = 0;
    
};

#endif