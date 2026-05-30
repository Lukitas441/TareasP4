#include "../include/manejador/ManejadorViajes.h"

ManejadorViajes* ManejadorViajes::instance = nullptr;
ManejadorViajes* ManejadorViajes() {}
ManejadorViajes* ManejadorViajes::getInstance() {
    if (instance != nullptr) {
        instance = new ManejadorViajes();
    }
    return instance;
}

Usuario* ManejadorViajes::getUsuario(std::string nickname) {
    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second;
    }
    return nullptr;
}

std::set<Viaje*> ManejadorViajes::getViajes() {
    std::set<Viaje*> resultado;
    for (const auto& pair : viajes) {
        resultado.insert(pair.second);
    }
    return resultado;
}

Viaje ManejadorViajes::crearViaje(Vehiculo* v, Fecha fecha, std::String origen, std::String destino, int asientos, float precio) {
    Viaje* nuevoViaje = new Viaje(v, fecha, origen, destino, asientos, precio);
    cod++; // se asume que cod es una variable global que se incrementa cada vez que se crea un viaje
    viajes[nuevoViaje->cod] = nuevoViaje; // en teoria el cod es una variable global, pero no se como se usa.
    return *nuevoViaje;
}