#include "../include/DTListarViaje.h"

DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string nicknameConductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->nicknameConductor = nicknameConductor;
}

int DTListarViaje::getCodigo() { return codigo; }
DTFecha DTListarViaje::getFecha() { return fecha; }
std::string DTListarViaje::getOrigen() { return origen; }
std::string DTListarViaje::getDestino() { return destino; }
std::string DTListarViaje::getNicknameConductor() { return nicknameConductor; }
