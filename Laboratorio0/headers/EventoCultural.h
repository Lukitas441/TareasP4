
#ifndef EVENTO_CULTURAL_H
#define EVENTO_CULTURAL_H
#include <iostream>
#include "headers/Experiencia.h"
#include <string>



class EventoCultural : public Experiencia{ // subclase de Experiencia

private:
    std::string ubicacion;
    bool usoCupon;

public:
    // Constructores y destructores
    EventoCultural();
    ~EventoCultural();
    EventoCultural(std::string, std::string, int, DTFecha, std::string, bool);


    // Getters
    std::string getUbicacion();
    bool getUsoCupon();

    // Setters
    void setUbicacion(std::string ubicacion);
    void setUsoCupon(bool usoCupon);

    // Funciones
    virtual float calcularCosto();  
};

#endif // EVENTO_CULTURAL_H
