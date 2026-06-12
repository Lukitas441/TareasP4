#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include "DTUsuarioViaje.h"
#include <string>
#include <iostream>
#include <set>

class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;
    std::set<Reserva*> reservas;
public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();
    void addReserva(Reserva* reserva);
    std::string getCI ();
    std::set<Reserva*>& getReservas();
    std::list<DTListarViaje> getViajesTotales();
    DTUsuarioViaje* getDatosPasajero();
};

#endif
