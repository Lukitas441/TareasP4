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

    int getCodigo() const;
    DTFecha getFecha() const;
    std::string getOrigen() const;
    std::string getDestino() const;
    std::string getNicknameConductor() const;

};

#endif
