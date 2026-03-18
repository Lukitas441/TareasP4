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
    TourGuiado(std::string, std::string, int, DTFecha, std::string, std::string, std::list<std::string>);  // constructor
    ~TourGuiado(); // destructor
    std::string getAgencia();
    std::list<std::string> getLugaresVisitados();
    virtual float calcularCosto();
};

#endif // TOUR_GUIADO_H