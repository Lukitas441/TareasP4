#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "headers/Experiencia.h"

class Alojamiento : public Experiencia{ // subclase de Experiencia
    
private:
    std::string hotel;
    enum TipoRegimen regimen;
    int cantNoches;

public:
    // Constructores y destructores
    Alojamiento();
    ~Alojamiento(); // destructor    
    Alojamiento(std::string, std::string, int, DTFecha, std::string, enum TipoRegimen, int);

    // Getters
    std::string getHotel();
    TipoRegimen getRegimen();
    int getCantNoches();

    // Setters
    void setHotel(std::string hotel);
    void setRegimen(TipoRegimen regimen);
    void setCantNoches(int cantNoches);

    // Funciones
    virtual float calcularCosto();
};

#endif // ALOJAMIENTO_H