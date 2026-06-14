#include "../include/controller/ControladorViajes.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"
#include "../include/manejador/ManejadorVehiculos.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include "Pasajero.h"
#include "../include/manejador/ControladorFechaActual.h"
#include <algorithm>

ControladorViajes::ControladorViajes() {};
ControladorViajes::~ControladorViajes() {};

std::list<DTConsultaViaje*> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
  ManejadorViajes *mv = ManejadorViajes::getInstance();
  std::map<int, Viaje*> viajes = mv->getViajes();
  std::list<DTConsultaViaje*> resultado;

  for (const auto& pair : viajes) {
    Viaje* viaje = pair.second;
    if (!viaje) continue;
    if (!viaje->viajeCoincide(fecha, origen, destino)) continue;
    if (!viaje->asientosCheck(asientos)) continue;

    resultado.push_back(new DTConsultaViaje(viaje->constructorDTConsultaViaje(asientos)));
  }

  resultado.sort([](DTConsultaViaje* a, DTConsultaViaje* b) {
    if (a->getPrecioTotal() != b->getPrecioTotal()) {
      return a->getPrecioTotal() < b->getPrecioTotal();
    }
    if (a->getCalificacionProm() != b->getCalificacionProm()) {
      return a->getCalificacionProm() > b->getCalificacionProm();
    }
    return a->getCodigo() < b->getCodigo();
  });

  return resultado;
};

bool ControladorViajes::generarReserva(std::string nicknamePasajero, int codigoViaje, int cantAsientos) {
  ManejadorViajes *mv = ManejadorViajes::getInstance();
  Viaje *viaje = mv->getViaje(codigoViaje);
  if (viaje != nullptr) {
    bool valido = viaje->asientosCheck(cantAsientos);
    if (valido){
      bool encontrado = viaje->findPasajero(nicknamePasajero);
      if (!encontrado){
        ManejadorUsuarios *mu = ManejadorUsuarios::getInstance();
        Pasajero *pasajeroSelect = dynamic_cast<Pasajero*>(mu->getUsuario(nicknamePasajero));
        ControladorFechaActual *mf = ControladorFechaActual::getInstance();
        DTFecha fecha =  mf->getFecha();
        Reserva *rese = new Reserva(cantAsientos, pasajeroSelect, fecha, viaje);
        viaje->addRese(rese);
        pasajeroSelect->addReserva(rese);
        return true;
      }
    }
  }
  return false;
};

DTDetalleViaje ControladorViajes::detalleViaje(int codigo) {
  ManejadorViajes *mv = ManejadorViajes::getInstance();
  Viaje *viaje = mv->getViaje(codigo);

  Vehiculo *v = viaje->getVehiculo();
  DTDetalleVehiculo dtv(v->getMatricula(), v->getCapacidad(), v->getMarca(), v->getModelo(), v->getTipo());

  std::vector<DTDetalleReserva> reservas;
  for (Reserva* r : viaje->getReservas()) {
    reservas.push_back(DTDetalleReserva(r->getAsientos(), r->getFecha(), r->getPasajero()->getNickname()));
  }

  return DTDetalleViaje(viaje->getCodigo(), viaje->getFecha(), viaje->getOrigen(), viaje->getDestino(),
  viaje->getAsientosPublicados(), viaje->getPrecio(), dtv, reservas);
};

void ControladorViajes::eliminarViaje(int codigo) {
    ManejadorViajes *mv = ManejadorViajes::getInstance();
    Viaje* viaje = mv->getViaje(codigo);
    if (viaje == nullptr) return;

    mv->eliminarViaje(codigo);
    delete viaje;
};

std::list<DTUsuarioViaje*> ControladorViajes::listarUsuariosViaje(int codigo) {
    ManejadorViajes *mv = ManejadorViajes::getInstance();
    Viaje *viaje = mv->getViaje(codigo);
    std::list<DTUsuarioViaje*> resultado = std::list<DTUsuarioViaje*>();
    if (viaje != nullptr) {
        resultado.push_back(viaje->getConductorViaje());
        resultado.splice(resultado.end(), viaje->getUsuarioRes());
    }
    return resultado;
};


bool ControladorViajes::altaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
  ManejadorVehiculos *mv = ManejadorVehiculos::getInstance();
  Vehiculo *v = mv->getVehiculo(matricula);
  bool hayViajesFecha = false;
  int capacidad = v->getCapacidad();
  if (capacidad>=asientos) {
    hayViajesFecha = v->hayViajesConductor(fecha);
  }
  ManejadorViajes *mvi = ManejadorViajes::getInstance();
  if (capacidad>=asientos && !hayViajesFecha) { 
    Viaje* cvi = mvi->crearViaje(fecha, origen, destino, asientos, precio, v);
    mvi->agregarViaje(cvi);
    v->addViaje(cvi);
    return true;
  }
  return false;
};

std::map<int, Viaje*> ControladorViajes::listarViajes(){
  ManejadorViajes* mv = ManejadorViajes::getInstance();
  return mv->getViajes();
}

void ControladorViajes::liberarViajes(){
  ManejadorViajes* mv = ManejadorViajes::getInstance();
  for(std::pair<int, Viaje*> v : mv->getViajes())
  {
    mv->eliminarViaje(v.second->getCodigo());
    delete v.second;
  }
}
