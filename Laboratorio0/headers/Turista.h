#ifndef TURISTA_H
#define TURISTA_H

#include <iostream>
#include <list>
#include <string>
#include "headers/DTFecha.h"

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

#endif // TURISTA_H