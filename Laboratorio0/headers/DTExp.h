#include <list>
#include <iostream>
#include "DTFecha.h"


class DTExp{
private:
    std::string codigoReserva;   
    std::list<std::string> Turista;
    std::string descripcion; 
    DTFecha fecha;

public:
    DTExp(std::string, std::list<std::string> , std::string, DTFecha); // constructor

    std::string getCodigoReserva();
    std::list<std::string> getTurista();
    std::string getDescripcion();
    DTFecha getFecha();
};