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
    // Constructores y destructores
    Turista();
    ~Turista();
    Turista(std::string, std::string, std::string);

    // Getters
    std::string getCI();
    std::string getNombre();
    std::string getEmail();

    // Setters
    void setCI(std::string);
    void setNombre(std::string);
    void setEmail(std::string);

    // Funciones
    std::string toString(); // string
    std::list<std::string> listarExperiencias(DTFecha, float, float); // Set(string)
};

#endif // TURISTA_H