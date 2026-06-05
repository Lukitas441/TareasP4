#ifndef CONTROLADOR_USUARIOS_H
#define CONTROLADOR_USUARIOS_H

#include "TipoLibreta.h"
#include "TipoVehiculo.h"
#include "../include/interface/IControladorUsuarios.h"
#include <set>
#include <string>

class DTListarViaje;
class DTUsuario;
class Vehiculo;
class Pasajero;
class Conductor;

class ControladorUsuarios : public IControladorUsuarios {
private:
    static ControladorUsuarios* instancia;

public:
    static ControladorUsuarios* getInstance();

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
        std::list<TipoLibreta> libretas
    ) override;

    int registrarVehiculo(
    std::string nickname,
    std::string matricula,
    int capacidad,
    std::string marca,
    std::string modelo,
    TipoVehiculo tipo
    ) override;

    std::set<DTUsuario> listarUsuarios() override;

    std::set<DTUsuario> listarPasajeros() override;

    std::list<DTListarViaje> listarViajes(std::string nickname) override;

    bool calificarUsuario(
        std::string nicknameCalificado,
        int calificacion
    ) override;
};

#endif