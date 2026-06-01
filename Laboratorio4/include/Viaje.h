#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTUsuarioViaje.h"
#include "DTConsultaViaje.h"
#include <string>
#include <set>
#include "Reserva.h"
#include "Vehiculo.h"

class Viaje {
private:

    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    std::set<Reserva*> reservas;
    Vehiculo* vehiculo;
    

public:

    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo);
    ~Viaje();
    int getCodigo(); 
    DTFecha getFecha(); 
    std::string getOrigen();
    std::string getDestino(); 
    int getAsientosPublicados();
    float getPrecio(); 
    std::set<Reserva*> getReservas();
    Vehiculo* getVehiculo();

    DTListarViaje getDatosViaje();
    DTUsuarioViaje getConductorViaje();
    bool viajeCoincide(DTFecha fecha, std::string origen, std::string destino);
    bool asientosCheck(int asientos);
    DTConsultaViaje constructorDTConsultaViaje(int asientos);
    bool findPasajero(std::string nickname);
    DTUsuarioViaje getUsuarioRes(std::string nickname);
    void addRese(Reserva* reserva);    

};
#endif
