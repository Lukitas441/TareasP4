#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include "../include/interface/IControladorViajes.h"
#include <set>
#include <string>
#include <list>
#include "DTUsuarioViaje.h"
class Reserva;
 

class ControladorViajes : public IControladorViajes {
public:

    ControladorViajes();
    ~ControladorViajes();

    std::set<DTConsultaViaje*> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) override;
    //DTDetalleViaje detalleViaje(int codigo) override;//LUCAS??
    std::list<DTUsuarioViaje*> listarUsuariosViaje(int codigo) override; 
    bool generarReserva(std::string nicknamePasajero, int codigoViaje, int cantAsientos) override;
    void eliminarViaje(int codigo) override;
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) override;
};
#endif