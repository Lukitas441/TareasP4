#ifndef MANEJADOR_USUARIOS_H
#define MANEJADOR_USUARIOS_H

#include "DTUsuario.h"
#include "Usuario.h"
#include "Pasajero.h"
#include "Conductor.h"
#include <map>
#include <set>

class ManejadorUsuarios {

private:
    static ManejadorUsuarios* instance;
    std::map<std::string, Usuario*> usuarios;
    ManejadorUsuarios();

public:
    static ManejadorUsuarios* getInstance();

    void agregarUsuario(Usuario* usuario);

    Usuario* getUsuario(std::string nickname);

    std::set<Usuario*> getUsuarios();
    std::set<Pasajero*> getPasajeros();
    std::set<Conductor*> getConductores();
};

#endif