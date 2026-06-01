#ifndef DT_LISTAR_VIAJE_H
#define DT_LISTAR_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTListarViaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    std::string nicknameConductor;

public:
    DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string nicknameConductor);

    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    std::string getNicknameConductor();

};

#endif
