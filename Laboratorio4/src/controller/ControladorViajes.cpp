#include "ControladorViajes.h"
#include "../include/manejador/ManejadorViajes.h"
#include "Viaje.h"

ControladorViajes::ControladorViajes() {};
ControladorViajes::~ControladorViajes() {};

std::set<DTConsultaViaje*> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
  ManejadorViajes* mv = ManejadorViajes::getInstance();
  std::map<int, Viaje*> viajes = mv->getViajes();
  std::set<DTConsultaViaje*> resultado = std::set<DTConsultaViaje*>();

  std::map<int, Viaje*>::iterator it;
  for (it = viajes.begin(); it != viajes.end(); ++it) {
    Viaje* viaje = it->second;
    if(viaje->viajeCoincide(fecha, origen, destino) and viaje->asientosCheck(asientos)) {
      resultado.insert(new DTConsultaViaje(viaje->constructorDTConsultaViaje(asientos)));
    }

  }
  return resultado;
};

bool ControladorViajes::generarReserva(std::string nicknamePasajero, int codigoViaje, int cantAsientos) {
  ManejadorViajes* mv = ManejadorViajes::getInstance();
  Viaje* viaje = mv->getViaje(codigoViaje);
  if (viaje != nullptr) {

  }
  return false;
};