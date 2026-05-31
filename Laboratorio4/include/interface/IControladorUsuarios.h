#ifndef I_CONTROLADOR_USUARIOS_H
#define I_CONTROLADOR_USUARIOS_H

#include <set>
#include <string>

#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "TipoLibreta.h"
#include "TipoVehiculo.h"

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
        std::set<TipoLibreta> libretas
    ) = 0;

    virtual int registrarVehiculo(
        std::string nickname,
        std::string matricula,
        int capacidad,
        std::string marca,
        std::string modelo,
        TipoVehiculo tipo
    ) = 0;

    virtual std::set<DTUsuario> listarUsuarios() = 0;

    virtual std::set<DTListarViaje> listarViajes(
        std::string nickname
    ) = 0;

    virtual bool calificarUsuario(
        std::string nicknameCalificado,
        int calificacion
    ) = 0;

    virtual std::set<std::string> listarPasajeros() = 0;

    virtual ~IControladorUsuarios() {};
};

#endif