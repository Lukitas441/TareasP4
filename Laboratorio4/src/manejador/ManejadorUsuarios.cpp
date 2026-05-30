#include "../include/manejador/ManejadorUsuarios.h"

ManejadorUsuarios* ManejadorUsuarios::instance = nullptr;
ManejadorUsuarios::ManejadorUsuarios() {}
ManejadorUsuarios* ManejadorUsuarios::getInstance() {
    if (instance == nullptr) {
        instance = new ManejadorUsuarios();
    }
    return instance;
}

Usuario* ManejadorUsuarios::getUsuario(std::string nickname) {
    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second;
    }
    return nullptr;
}

std::set<Usuario*> ManejadorUsuarios::getUsuarios() {
    std::set<Usuario*> resultado;
    for (const auto& pair : usuarios) {
        resultado.insert(pair.second);
    }
    return resultado;
}

std::set<Usuario*> ManejadorUsuarios::getPasajeros() {
    std::set<Pasajero*> resultado;
    for (const auto& pair : usuarios) {
        Pasajero* pasajero:= dynamic_cast<Pasajero*>(pair.second);
        if (pasajero != nullptr) {
            resultado.insert(pasajero);
        }
    }
    return resultado;
}

std::set<Usuario*> ManejadorUsuario::getConductores() {
    std::set<Conductor*> resultado;
    for (const auto& pair : usuarios) {
        Conductor* conductor:= dynamic_cast<Conductor*>(pair.second);
        if (conductor != nullptr) {
            resultado.insert(conductor);
        }
    }
    return resultado;
}