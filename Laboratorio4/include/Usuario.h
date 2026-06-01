#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <DTUsuario.h>
#include <Calificacion.h>
#include <DTListarViaje.h>
#include <set>

class Calificacion;

class Usuario
{
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::map<std::string, Calificacion*> calificacionesRecibidas;
    float calificacionPromedio;
    

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    std::map<std::string, Calificacion*> getCalificacionesRecibidas();
    float getCalificacionPromedio();


    DTUsuario getInfoUsuario();
    float calificacionPromedio();
    bool existeCalificado(std::string nicknameCalificador, int codigoViaje);
    virtual std::set<DTListarViaje> getViajesTotales();
};

#endif
