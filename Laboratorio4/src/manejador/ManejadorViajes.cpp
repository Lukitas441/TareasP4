#include "../include/manejador/ManejadorViajes.h"
#include "Viaje.h"

ManejadorViajes* ManejadorViajes::instance = nullptr;
ManejadorViajes::ManejadorViajes() {};

ManejadorViajes* ManejadorViajes::getInstance() {
    if (instance == nullptr) {
        instance = new ManejadorViajes();
    }
    return instance;
};

std::map<int, Viaje*> ManejadorViajes::getViajes() {
    return viajes;
};

Viaje* ManejadorViajes::getViaje(int codigo) {
    std::map<int, Viaje*>::iterator it = viajes.find(codigo);
    if (it != viajes.end()) {
        if(it->second->getCodigo() == codigo) {
            return it->second;
        }
    }
    return nullptr;
};

void ManejadorViajes::agregarViaje(Viaje* viaje) {
    viajes[viaje->getCodigo()] = viaje;
};

void ManejadorViajes::eliminarViaje(int codigo) {
    viajes.erase(codigo);
}

Viaje ManejadorViajes::crearViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo) {
    Viaje viaje = Viaje(codigo, fecha, origen, destino, asientosPublicados, precio, vehiculo);
    return viaje;
};