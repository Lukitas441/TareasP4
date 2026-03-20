#ifndef TURISTA_H
#define TURISTA_H

#include <iostream>
#include <list>
#include <string>
#include "DTFecha.h"

class Experiencia;

class Turista
{
    private:
        std::string ci;
        std::string nombre;
        std::string email;
        std::list<Experiencia*> experiencias; // lista de experiencias en las que participa el turista

public:
    // Constructores y destructores
    Turista();
    ~Turista();
    Turista(std::string, std::string, std::string);

    // Getters
    std::string getCI();
    std::string getNombre();
    std::string getEmail();
    std::list<Experiencia*> getExperiencias();

    // Setters
    void setCI(std::string);
    void setNombre(std::string);
    void setEmail(std::string);
    void setExperiencias(Experiencia*);

    // Funciones
    std::string toString(); // string
    std::list<Experiencia*> listarExperiencias(DTFecha, float, float); // Set(string)
    void EliminarExperiencia(Experiencia* experiencia); // Elimina una experiencia de la lista de experiencias del turista
};

#endif // TURISTA_H