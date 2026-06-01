#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

#include "../interface/IControladorViajes.h"

class ControladorViajes : public IControladorViajes {
public:
    ControladorViajes();
    ~ControladorViajes();

    std::set<DTConsultaViaje*> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) override;
    //DTDetalleViaje detalleViaje(int codigo) override;
    //std::list<DTUsuario> listarUsuariosViaje(int codigo) override;
    bool generarReserva(std::string nicknamePasajero, int codigoViaje, int cantAsientos) override;
    void eliminarViaje() override;
    bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) override;
};
#endif