#include "../include/Conductor.h"
#include "Vehiculo.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::map<TipoLibreta, bool> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
};

Conductor::~Conductor() {};

std::map<TipoLibreta, bool> Conductor::getLibretas() {
    return this->libretas;
}

std::list<Vehiculo*> Conductor::getVehiculos() {
    return this->vehiculos;
}

void Conductor::agregarVehiculo(Vehiculo* vehiculo) {
    this->vehiculos.push_back(vehiculo);
};

bool Conductor::libretaValida(TipoVehiculo tipo) {
    if (((tipo == Auto && (libretas[AutoProfesional] || libretas[AutoAmateur])) || (tipo == Moto && (libretas[MotoProfesional] || libretas[MotoAmateur])))) {
            return true;
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

DTUsuarioViaje * Conductor::getDatosConductor() {
    DTUsuarioViaje *dtuv = new DTUsuarioViaje(this->nickname, TipoUsuario::conductor);
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

std::list<DTVehiculosConductor> Conductor::listarVehiculos() {
    std::list<DTVehiculosConductor> listaVehiculos;
    for (const auto& vehiculo : this->vehiculos) {
        DTVehiculosConductor dtvc = vehiculo->getDTVehiculoConductor();
        listaVehiculos.push_back(dtvc);
    }
    return listaVehiculos;
}
