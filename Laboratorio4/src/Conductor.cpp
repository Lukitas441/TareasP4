#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
};

Conductor::~Conductor() {};

std::set<TipoLibreta> Conductor::getLibretas() {
    return this->libretas;
}

std::set<Vehiculo*> Conductor::getVehiculos() {
    return this->vehiculos;
}

bool Conductor::libretaValida(TipoVehiculo tipo) {
    if (tipo == TipoVehiculo::Auto) {
        for (std::set<TipoLibreta>::iterator it = this->libretas.begin(); it != this->libretas.end(); ++it) {
            if (*it == TipoLibreta::AutoProfesional || *it == TipoLibreta::AutoAmateur) {
                return true;
            }
        }
    } else if (tipo == TipoVehiculo::Moto) {
        for (std::set<TipoLibreta>::iterator it = this->libretas.begin(); it != this->libretas.end(); ++it) {
            if (*it == TipoLibreta::MotoProfesional || *it == TipoLibreta::MotoAmateur) {
                return true;
            }
        }
    }
    return false;
}

std::set<DTListarViaje> Conductor::getViajesTotales() {
    std::set<DTListarViaje> viajes;
    for (const auto& vehiculo : this->vehiculos) {
        auto vehiculoViajes = vehiculo->getViajes();
        viajes.insert(vehiculoViajes.begin(), vehiculoViajes.end());
    }
    return viajes;
}

DTUsuarioViaje Conductor::getDatosConductor() {
    return DTUsuarioViaje(this->getNickname(), this->getNombre(), this->getEmail());
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for (const auto& vehiculo : this->vehiculos) {
        if (vehiculo->hayViajesFecha(fecha)) {
            return true;
        }
    }
    return false;
}
