#include "../include/manejador/ManejadorVehiculos.h"

ManejadorVehiculos* ManejadorVehiculos::instance = nullptr;

ManejadorVehiculos::ManejadorVehiculos() {};

ManejadorVehiculos* ManejadorVehiculos::getInstance() {
    if (instance == nullptr) {
        instance = new ManejadorVehiculos();
    }
    return instance;
};

Vehiculo* ManejadorVehiculos::getVehiculo(std::string matricula) {
    auto it = vehiculos.find(matricula);
    if (it != vehiculos.end()) {
        return it->second;
    }
    return nullptr;
};

std::set<Vehiculo*> ManejadorVehiculos::getVehiculos() {
    std::set<Vehiculo*> resultado;
    for (const auto& pair : vehiculos) {
        resultado.insert(pair.second);
    }
    return resultado;
};