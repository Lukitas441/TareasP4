#include "Pasajero.h"
#include "Reserva.h"
#include "Viaje.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
};

Pasajero::~Pasajero() {
    for(Calificacion* calif : calificacionesRecibidas) {
        delete calif;
    }
    if (!reservas.empty()) {
        for (Reserva* reserva : reservas) {
            delete reserva;
        }
    }
};

void Pasajero::addReserva(Reserva* reserva) { //agrega una reserva al set de reservas
    this->reservas.insert(reserva);
};


std::string Pasajero::getCI() {
    return this->ci;
};

std::set<Reserva*>& Pasajero::getReservas() {
    return this->reservas;
};

std::list<DTListarViaje> Pasajero::getViajesTotales() {
    std::list<DTListarViaje> viajes;
    for (const auto& reserva : this->reservas) {
        viajes.push_back(reserva->getViaje()->getDatosViaje());
    }
    viajes.sort([](const DTListarViaje& a, const DTListarViaje& b) {
        return a.getCodigo() < b.getCodigo();
    });
    return viajes;
};

DTUsuarioViaje* Pasajero::getDatosPasajero() {
    DTUsuarioViaje* dtp = new DTUsuarioViaje(this->nickname, TipoUsuario::pasajero);
    return dtp;
}

