#include "../include/controller/ControladorVehiculos.h"
#include "../include/manejador/ManejadorVehiculos.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"

ControladorVehiculos::ControladorVehiculos() {};
ControladorVehiculos::~ControladorVehiculos() {};

//Lista de DTVehiculosConductor 
std::list<DTVehiculosConductor> ControladorVehiculos::ListarVehiculosConductor(std::string nickname) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Conductor* c = dynamic_cast<Conductor*>(mu->getUsuario(nickname));
    if (c == nullptr) {
        return std::list<DTVehiculosConductor>();
    }
    std::list<DTVehiculosConductor> listaVehiculos;
    listaVehiculos = c->listarVehiculos();
    return listaVehiculos;
};

bool ControladorVehiculos::AltaViaje(std::string matricula, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
    ManejadorVehiculos* mv = ManejadorVehiculos::getInstance();
    Vehiculo* v = mv->getVehiculo(matricula);
    if (v == nullptr) {
        return false;
    }
    bool hayViajesFecha = false;
    int capacidad = v->getCapacidad();
    if (capacidad >= asientos) {
        hayViajesFecha = v->hayViajesConductor(fecha);
    }
    
    ManejadorViajes* mvi = ManejadorViajes::getInstance();
    if (capacidad >= asientos && !hayViajesFecha) {
        Viaje* cvi = mvi->crearViaje(fecha, origen, destino, asientos, precio, v);
        mvi->agregarViaje(cvi);
        v->addViaje(cvi);
        return true;
    }
    return false;
};


