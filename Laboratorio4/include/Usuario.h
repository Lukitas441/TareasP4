#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <DTUsuario.h>
#include <Calificacion.h>

class Usuario
{
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::map<std::string, Calificacion*> calificacionesRecibidas; 

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    std::map<std::string, Calificacion*> getCalificacionesRecibidas();


    DTUsuario getInfoUsuarios();
    float calificacionPromedio();
    bool existeCalificado(std::string nicknameCalificador, int codigoViaje);
    virtual int getViajesTotales() = 0;
};

#endif
