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
    Vehiculo* vechiculo;
    

public:

    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vechiculo);
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
    DTConsultaViaje constructorDTConsultaViaje(int codigo);
    bool findPasajero(std::string nickname);
    DTUsuarioViaje getUsuarioRes();
    void addRese(Reserva* reserva);    

};
#endif
