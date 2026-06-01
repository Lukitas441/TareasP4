#include "../include/manejador/ManejadorVehiculos.h"

ManejadorVehiculos* ManejadorVehiculos::instance = nullptr;
ManejadorVehiculos* ManejadorVechiulos() {};
ManejadorVehiculos* ManejadorVehiculos::getInstance() {
    if (instance == nullptr) {
        instance = new ManejadorVehiculos();
    }
    return instance;
};

Vehiculo* ManejadorVehiculo::getVehiculo(std::string matricula) {
    auto it = vehiculos.find(matricula);
    if (it != vehiculos.end()) {
        return it->second;
    }
    return nullptr;
};

std::set<Vehiculo*> ManejadorVehiculo::getVehiculos() {
    std::set<Vehiculo*> resultado;
    for (const auto& pair : vehiculos) {
        resultado.insert(pair.second);
    }
    return resultado;
};