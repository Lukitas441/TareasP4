#ifndef I_CONTROLADOR_VIAJES_H
#define I_CONTROLADOR_VIAJES_H

#include <list>
#include <string>
#include <set>

#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"

class Viaje;

class IControladorViajes {
public:
  virtual std::set<DTConsultaViaje*> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) = 0;
  //virtual DTDetalleViaje detalleViaje(int codigo) = 0;
  virtual std::list<DTUsuarioViaje*> listarUsuariosViaje(int codigo) = 0;
  virtual bool generarReserva(std::string nicknamePasajero, int codigoViaje, int cantAsientos) = 0;
  virtual void eliminarViaje(int codigo) = 0;
  virtual ~IControladorViajes() {};
  virtual bool altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) = 0;

};

#endif