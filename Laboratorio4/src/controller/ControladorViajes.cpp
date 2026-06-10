#include "../include/controller/ControladorViajes.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"
#include "../include/manejador/ManejadorVehiculos.h"
#include "Reserva.h"
#include "Vehiculo.h"
#include "../include/manejador/ControladorFechaActual.h"

ControladorViajes::ControladorViajes() {};
ControladorViajes::~ControladorViajes() {};

std::set<DTConsultaViaje*> ControladorViajes::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) {
  ManejadorViajes *mv = ManejadorViajes::getInstance();
  std::map<int, Viaje*> viajes = mv->getViajes();
  std::set<DTConsultaViaje*> resultado = std::set<DTConsultaViaje*>();

  std::map<int, Viaje*>::iterator it;
  for (it = viajes.begin(); it != viajes.end(); ++it) {
    Viaje *viaje = it->second;
    if(viaje->viajeCoincide(fecha, origen, destino) and viaje->asientosCheck(asientos)) {
      resultado.insert(new DTConsultaViaje(viaje->constructorDTConsultaViaje(asientos)));
    }

  }
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
  mv->eliminarViaje(codigo);
  return;
};

std::list<DTUsuarioViaje*> ControladorViajes::listarUsuariosViaje(int codigo) {
  ManejadorViajes *mv = ManejadorViajes::getInstance();
  Viaje *viaje = mv->getViaje(codigo);
    std::list<DTUsuarioViaje*> resultado = std::list<DTUsuarioViaje*>();
  if (viaje != nullptr) {
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

