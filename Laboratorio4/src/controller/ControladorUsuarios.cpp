#include "../include/controller/ControladorUsuarios.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "Pasajero.h"
#include "Vehiculo.h"
#include "Conductor.h"

ControladorUsuarios::ControladorUsuarios() {};
ControladorUsuarios::~ControladorUsuarios() {};

bool ControladorUsuarios::altaPasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string ci) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    
    if (mu->getUsuario(nickname) != nullptr) {
        return false;
    };

    Pasajero* p = new Pasajero(nickname,nombre,contrasena,email,ci);
    mu->agregarUsuario(p);
    
    return true;
};

bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::list<TipoLibreta> libretas) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    
    if (mu->getUsuario(nickname) != nullptr) {
        return false;
    };

    Conductor* c = new Conductor(nickname,nombre,contrasena,email,libretas);
    mu->agregarUsuario(c);
    
    return true;
};

std::list<DTUsuario> ControladorUsuarios::listarUsuarios() {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    std::set<Usuario*> usuarios = mu->getUsuarios();
    std::list<DTUsuario> resultado;

    for (const auto& u : usuarios) {
        resultado.push_back(u->getInfoUsuario());
    };

    return resultado;
};

std::list<DTUsuario> ControladorUsuarios::listarPasajeros() {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    std::set<Pasajero*> pasajeros = mu->getPasajeros();
    std::list<DTUsuario> resultado;

    for (const auto& p : pasajeros) {
        resultado.push_back(p->getInfoUsuario());
    };

    return resultado;
};

std::list<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Usuario* u = mu->getUsuario(nickname);

    return u->getViajesTotales();
};

int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Conductor* c = dynamic_cast<Conductor*>(mu->getUsuario(nickname));
    std::list<Vehiculo*> vehiculos = c->getVehiculos();
    bool matValida = true;
    for (const auto& v : vehiculos) {
        if (v->getMatricula() == matricula) {
            return -1;
        };
    };
    if ((matValida) && (c->libretaValida(tipo))) {
        Vehiculo* vehiculo = new Vehiculo(matricula, capacidad, marca, modelo, tipo, c);
        c->agregarVehiculo(vehiculo);
        return 0;
    } else {
        return -2;
    };
};
/*. SANTI LO DEJO ASI
bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Usuario* u = mu->getUsuario(nicknameCalificado);
    if (u != nullptr) {
        u->agregarCalificacion(calificacion);
        return true;
    }
    return false;
};
*/
