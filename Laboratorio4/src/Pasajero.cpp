#include "../include/Pasajero.h"

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
};

Pasajero::~Pasajero() {};

void Pasajero::addReserva(Reserva* reserva) { //agrega una reserva al set de reservas
    this->reservas.insert(reserva);
};


std::string Pasajero::getCI() {
    return this->ci;
};

std::set<Reserva*> Pasajero::getReservas() {
    return this->reservas;
};