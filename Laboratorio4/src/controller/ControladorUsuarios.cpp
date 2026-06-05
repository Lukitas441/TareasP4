#include "../include/controller/ControladorUsuarios.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "Pasajero.h"

ControladorUsuarios* ControladorUsuarios::instancia = nullptr;

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instancia == nullptr) {
        instancia = new ControladorUsuarios();
    }
    return instancia;
}


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

std::set<DTUsuario> ControladorUsuarios::listarUsuarios() {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    std::set<Usuario*> usuarios = mu->getUsuarios();
    std::set<DTUsuario> resultado;

    for (const auto& u : usuarios) {
        resultado.insert(u->getInfoUsuario());
    };

    return resultado;
};

std::set<DTUsuario> ControladorUsuarios::listarPasajeros() {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    std::set<Pasajero*> pasajeros = mu->getPasajeros();
    std::set<DTUsuario> resultado;

    for (const auto& p : pasajeros) {
        resultado.insert(p->getInfoUsuario());
    };

    return resultado;
};

std::list<DTListarViaje> ControladorUsuarios::listarViajes(std::string nickname) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Usuario* u = mu->getUsuario(nickname);

    return u->getViajesTotales();
};

int ControladorUsuarios::registrarVehiculo(std::string nickname, std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    return 0; //FALTA IMPLEMENTACION
};

bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    Usuario* u = mu->getUsuario(nicknameCalificado);

    
};
