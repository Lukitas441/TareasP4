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

    for (const auto& libreta : libretas) {
        if ((tipo == TipoVehiculo::Auto && (libreta == TipoLibreta::AutoProfesional || libreta == TipoLibreta::AutoAmateur)) ||
            (tipo == TipoVehiculo::Moto && (libreta == TipoLibreta::MotoProfesional || libreta == TipoLibreta::MotoAmateur))) {
            return true;
        }
    }
    return false;
}

std::set<DTListarViaje> Conductor::getViajesTotales() {
    std::set<DTListarViaje> viajes;
    for (const auto& vehiculo : this->vehiculos) {
        auto viajesVehiculo = vehiculo->getDTViajes();
        viajes.insert(viajesVehiculo.begin(), viajesVehiculo.end());
    }
    return viajes;
}

DTUsuarioViaje Conductor::getDatosConductor() {
    DTUsuarioViaje dtuv(this->nickname, TipoUsuario::conductor);
    return dtuv;
}

bool Conductor::hayViajesFechaConductor(DTFecha fecha) {
    for (const auto& vehiculo : this->vehiculos) {
        if (vehiculo->hayViajesFecha(fecha)) {
            return true;
        }
    }
    return false;
};

