#ifndef DT_EXP_H
#define DT_EXP_H

#include <set>
#include <iostream>
#include <string>
#include "headers/DTFecha.h"

class DTExp{
private:
    std::string codigoReserva;   
    std::set<std::string> turistas;
    std::string descripcion; 
    DTFecha fecha;

public:
    // Constructores y destructores
    DTExp();
    ~DTExp();
    DTExp(std::string, std::set<std::string> , std::string, DTFecha);
    
    // Getters
    std::string getCodigoReserva();
    std::set<std::string> getTuristas();
    std::string getDescripcion();
    DTFecha getFecha();
    friend std::ostream& operator<<(std::ostream&, DTExp);
};

#endif // DT_EXP_H