#ifndef DTCONDUCTOR_H
#define DTCONDUCTOR_H

#include <string>

//NUESTRO CREADO
class DTConductor {
private:
    std::string nombre;
    float calificacionPromedio;

public:
    DTConductor(std::string nombre, float calificacionPromedio);
    
    std::string getNombre();
    float getCalificacionPromedio();
};

#endif // DTCONDUCTOR_H