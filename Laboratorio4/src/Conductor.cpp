#include "../include/Conductor.h"
#include "Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::list <TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
};

Conductor::~Conductor() {};

std::list<TipoLibreta> Conductor::getLibretas() {
    return this->libretas;
}

std::list<Vehiculo*> Conductor::getVehiculos() {
    return this->vehiculos;
}

void Conductor::agregarVehiculo(Vehiculo* vehiculo) {
    this->vehiculos.push_back(vehiculo);
};

bool Conductor::libretaValida(TipoVehiculo tipo) {

    for (const auto& libreta : libretas) {
        if ((tipo == TipoVehiculo::Auto && (libreta == TipoLibreta::AutoProfesional || libreta == TipoLibreta::AutoAmateur)) ||
            (tipo == TipoVehiculo::Moto && (libreta == TipoLibreta::MotoProfesional || libreta == TipoLibreta::MotoAmateur))) {
            return true;
        }
    }
    return false;
}

std::list<DTListarViaje> Conductor::getViajesTotales() {
    std::list<DTListarViaje> viajes;
    for (const auto& vehiculo : this->vehiculos) {
        std::list<DTListarViaje> dtViajes = vehiculo->getDTViajes();
        viajes.insert(viajes.end(), dtViajes.begin(), dtViajes.end());
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

std::set<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::set<DTVehiculosConductor> listaVehiculos;
    for (const auto& vehiculo : this->vehiculos) {
        DTVehiculosConductor dtvc = vehiculo->getDTVehiculoConductor();
        listaVehiculos.insert(dtvc);
    }
    return listaVehiculos;
}
