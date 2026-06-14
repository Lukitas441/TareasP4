#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H


#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "../include/interface/IControladorUsuarios.h"
#include <set>
#include <map>
#include <string>

class DTListarViaje;
class DTUsuario;
class Vehiculo;
class Pasajero;
class Conductor;
class Usuario;

class ControladorUsuarios : public IControladorUsuarios {

public:
    ControladorUsuarios(); // constructor
    ~ControladorUsuarios(); // destructor

    bool altaPasajero(
        std::string nickname,
        std::string nombre,
        std::string contrasena,
        std::string email,
        std::string ci
    ) override; // el override indica que esta función es una implementación de una función virtual pura en la clase base, aunque te hayas equivocado.
                // se pone porque puede que le erres a la funcion, y el compilador no te va a decir que esta mal. Simplemente va a crear ese nuevo metodo.

    bool altaConductor(
        std::string nickname,
        std::string nombre,
        std::string contrasena,
        std::string email,
        std::map<TipoLibreta, bool> libretas
    ) override;

    int registrarVehiculo(
    std::string nickname,
    std::string matricula,
    int capacidad,
    std::string marca,
    std::string modelo,
    TipoVehiculo tipo
    ) override;

    Usuario* getUsuario(std::string nickname) override;

    std::list<DTUsuario> listarUsuarios() override;

    std::list<DTUsuario> listarPasajeros() override;

    std::list<DTListarViaje> listarViajes() override;
    std::list<DTListarViaje> listarViajes(std::string nickname) override;

    bool calificarUsuario(
        std::string nicknameCalificado,
        int calificacion
    ) override;

    void liberarUsuarios() override;
};

#endif