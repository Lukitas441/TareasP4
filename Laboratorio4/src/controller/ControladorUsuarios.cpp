#include "../include/controller/ControladorUsuarios.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"
#include "../include/manejador/ManejadorVehiculos.h"
#include "../include/manejador/ControladorFechaActual.h"
#include "Viaje.h"
#include "Pasajero.h"
#include "Vehiculo.h"
#include "Conductor.h"
#include "Calificacion.h"
#include "Usuario.h"
#include "Reserva.h"

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

bool ControladorUsuarios::altaConductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::map<TipoLibreta, bool> libretas) {
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

std::list<DTListarViaje> ControladorUsuarios::listarViajes() {
    ManejadorViajes* mv = ManejadorViajes::getInstance();
    std::map<int, Viaje*> viajes = mv->getViajes();
    std::list<DTListarViaje> resultado;
    for (const auto& pair : viajes) {
        resultado.push_back(pair.second->getDatosViaje());
    }
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
        ManejadorVehiculos::getInstance()->agregarVehiculo(vehiculo);
        return 0;
    } else {
        return -2;
    };
};

bool ControladorUsuarios::calificarUsuario(std::string nicknameCalificado, int calificacion) {
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    ManejadorViajes* mv = ManejadorViajes::getInstance();
    Usuario* u = mu->getUsuario(nicknameCalificado);
    std::string nicknameCalificador = mu->getNicknameCalificador();
    int codigoViaje = mv->getCodigoViajeActual();
    
    if (nicknameCalificador == nicknameCalificado) {
        return false;
    };
    
    if (u != nullptr && codigoViaje > 0) {
        
        bool existe = u->existeCalificador(nicknameCalificador, codigoViaje);
        std::cout << "existe calificador: " << existe << std::endl;
        Usuario *calificador = (mu->getUsuario(nicknameCalificador));
        
        if (!existe && calificador != nullptr) {
            ControladorFechaActual* mf = ControladorFechaActual::getInstance();
            DTFecha fecha =  mf->getFecha();
            Viaje* viaje = mv->getViaje(codigoViaje);
            Calificacion * calif;
            Reserva* reservaCal = nullptr;
            
            for (Reserva* r : viaje->getReservas()) {
                if (dynamic_cast<Conductor*>(calificador) != nullptr) {    
                    if (r->getPasajero()->getNickname() == nicknameCalificado){
                        reservaCal = r;
                        break;
                    }
                }
                else {
                    if (r->getPasajero()->getNickname() == nicknameCalificador){
                        reservaCal = r;
                        break;
                    }
                }
            }

            calif = new Calificacion(fecha, calificacion, calificador, reservaCal); 
            u->addCalif(calif); 
            return true;
        }
    }
    return false;
};

Usuario* ControladorUsuarios::getUsuario(std::string nickname){
    ManejadorUsuarios* mu = ManejadorUsuarios::getInstance();
    return mu->getUsuario(nickname);
}
