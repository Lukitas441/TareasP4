#ifndef TOUR_GUIADO_H
#define TOUR_GUIADO_H

#include "headers/Experiencia.h"
#include <list>
#include <string>

class TourGuiado : public Experiencia
{ // subclase de Experiencia
private:
    std::string agencia;
    std::list<std::string> lugaresVisitados;

public:
    // Constructores y destructores
    TourGuiado();
    ~TourGuiado();
    TourGuiado(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string agencia, std::list<std::string> lugaresVisitados);
    
    // Getters
    std::string getAgencia();
    std::list<std::string> getLugaresVisitados();

    // Setters
    void setAgencia(std::string agencia);
    void setLugaresVisitados(std::list<std::string> lugaresVisitados);

    // Funciones
    virtual float calcularCosto();
};

#endif // TOUR_GUIADO_H