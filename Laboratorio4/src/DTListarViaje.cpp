#include "../include/DTListarViaje.h"

DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string nicknameConductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->nicknameConductor = nicknameConductor;
}

int DTListarViaje::getCodigo() const { return codigo; }
DTFecha DTListarViaje::getFecha() const { return fecha; }
std::string DTListarViaje::getOrigen() const { return origen; }
std::string DTListarViaje::getDestino() const { return destino; }
std::string DTListarViaje::getNicknameConductor() const { return nicknameConductor; }
