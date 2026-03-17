#include <iostream>
#include <list>
#include "DTFecha.h"

class Turista
{
    private:
        std::string ci;
        std::string nombre;
        std::string email;

    public:
        Turista(std::string, std::string, std::string); // constructor
        ~Turista();                                     // destructor
        std::string toString();
        std::list<std::string> listarExperiencias(DTFecha, float, float);
};