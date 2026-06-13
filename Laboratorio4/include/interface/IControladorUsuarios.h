#ifndef I_CONTROLADOR_USUARIOS_H
#define I_CONTROLADOR_USUARIOS_H

#include <set>
#include <string>

#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "Usuario.h"
#include <list>
#include <map>

class IControladorUsuarios {
public:

    virtual bool altaPasajero(
        std::string nickname,
        std::string nombre,
        std::string contrasena,
        std::string email,
        std::string ci
    ) = 0;

    virtual bool altaConductor(
        std::string nickname,
        std::string nombre,
        std::string contrasena,
        std::string email,
        std::map<TipoLibreta, bool> libretas
    ) = 0;

    virtual int registrarVehiculo(
        std::string nickname,
        std::string matricula,
        int capacidad,
        std::string marca,
        std::string modelo,
        TipoVehiculo tipo
    ) = 0;

    virtual Usuario* getUsuario(std::string nickname) = 0;

    virtual std::list<DTUsuario> listarUsuarios() = 0;

    virtual std::list<DTListarViaje> listarViajes() = 0;
    virtual std::list<DTListarViaje> listarViajes(std::string nickname) = 0;

    virtual bool calificarUsuario(std::string nicknameCalificado, int calificacion) = 0;

    virtual std::list<DTUsuario> listarPasajeros() = 0;

    virtual ~IControladorUsuarios() = default; // virtual destructor, se pone para que al eliminar un objeto a través de un puntero a la clase base, se llame al destructor de la clase derivada. Si no se pone, puede haber fugas de memoria. El = default indica que se quiere el comportamiento por defecto del destructor, pero se necesita que sea virtual.

    virtual void liberarUsuarios() = 0;
};

#endif