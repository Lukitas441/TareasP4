#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email)
{
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;

    calificacionesRecibidas = std::map<std::string, Calificacion *>();
}

Usuario::~Usuario() {}

std::string Usuario::getNickname()
{
    return nickname;
}

DTUsuario Usuario::getInfoUsuarios()
{
    return DTUsuario(nickname, nombre);
}

std::map<std::string, Calificacion *> Usuario::getCalificacionesRecibidas()
{
    return calificacionesRecibidas;
}

float Usuario::calificacionPromedio()
{
    if (calificacionesRecibidas.empty())
    {
        return 0.0;
    }

    std::map<std::string, Calificacion *>::iterator it;
    int sumaPuntajes = 0;
    for (it = calificacionesRecibidas.begin(); it != calificacionesRecibidas.end(); ++it)
    {
        sumaPuntajes += it->second->getPuntaje();
    }

    return sumaPuntajes / calificacionesRecibidas.size();
}

// chequear pq distinto del Diagrama d Comunicacion
// esta va pal santi .l.
bool Usuario::existeCalificado(std::string nicknameCalificador, int codigoViaje)
{
    if (calificacionesRecibidas.empty())
    {
        return false;
    }

    std::map<std::string, Calificacion *>::iterator it;
    for (it = calificacionesRecibidas.begin(); it != calificacionesRecibidas.end(); ++it)
    {
        Usuario *usuarioCalificador = it->second->getUsuarioCalificador();
        Viaje *viajeCalificado = it->second->getCaliViaje();
        if (usuarioCalificador->getNickname() == nicknameCalificador && viajeCalificado->getCodigo() == codigoViaje)
        {
            return true;
        }
    }
    return false;
}
