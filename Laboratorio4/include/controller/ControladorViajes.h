#ifndef CONTROLADOR_VIAJES_H
#define CONTROLADOR_VIAJES_H

#include "../interface/IControladorViajes.h"

class ControladorViajes : public IControladorViajes {
private:
    static ControladorViajes* instancia;
public:
    static ControladorViajes* getInstance();   

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