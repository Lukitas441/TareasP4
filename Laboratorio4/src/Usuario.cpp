#include "../include/Usuario.h"
#include "Viaje.h"
#include "Calificacion.h"
#include "Conductor.h"
#include "Pasajero.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email)
{
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;

    calificacionesRecibidas = std::list<Calificacion*>();
}

Usuario::~Usuario() {}

std::string Usuario::getNickname()
{
    return nickname;
}
std::string Usuario::getNombre()
{
    return nombre;
}
std::string Usuario::getContrasena()
{
    return contrasena;
}
std::string Usuario::getEmail()
{
    return email;
}

DTUsuario Usuario::getInfoUsuario()
{
    return DTUsuario(nickname, nombre);
}

std::list<Calificacion*> Usuario::getCalificacionesRecibidas()
{
    return calificacionesRecibidas;
}

float Usuario::calificacionPromedio()
{
    if (calificacionesRecibidas.empty())
    {
        return 5;
    }

    std::list<Calificacion*>::iterator it;
    int sumaPuntajes = 0;
    for (it = calificacionesRecibidas.begin(); it != calificacionesRecibidas.end(); ++it)
    {
        sumaPuntajes += (*it)->getPuntaje();
    }

    return (float)sumaPuntajes / calificacionesRecibidas.size();
}

// chequear pq distinto del Diagrama d Comunicacion
// esta va pal santi .l. // crack el lucas 
// chequear la asociacion
bool Usuario::existeCalificador(std::string nicknameCalificador, int codigoViaje)
{
    if (calificacionesRecibidas.empty())
    {
        return false;
    }

    std::list<Calificacion*>::iterator it;
    for (it = calificacionesRecibidas.begin(); it != calificacionesRecibidas.end(); ++it)
    {
        Usuario *usuarioCalificador = (*it)->getUsuarioCalificador();
        Viaje *viajeCalificado = (*it)->getCaliViaje();
        if (usuarioCalificador->getNickname() == nicknameCalificador && viajeCalificado != nullptr && viajeCalificado->getCodigo() == codigoViaje)
        {
            return true;
        }
    }
    return false;
}


void Usuario::addCalif(Calificacion* calificacion){
    calificacionesRecibidas.push_back(calificacion);
}