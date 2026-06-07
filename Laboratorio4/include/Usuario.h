#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <map>
#include <DTUsuario.h>
#include <DTListarViaje.h>
#include <list>

class Calificacion;

class Usuario
{
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::list<Calificacion*> calificacionesRecibidas;
    
public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    virtual ~Usuario();

    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    std::list<Calificacion*> getCalificacionesRecibidas();
    
    DTUsuario getInfoUsuario();
    float calificacionPromedio();
    bool existeCalificador(std::string nicknameCalificador, int codigoViaje);
    virtual std::list<DTListarViaje> getViajesTotales() = 0;
    void addCalif(Calificacion* calif);
};

#endif
