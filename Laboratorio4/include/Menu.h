#ifndef MENU_H
#define MENU_H

#include "../include/interface/IControladorFechaActual.h"
#include "../include/interface/IControladorUsuarios.h"
#include "../include/interface/IControladorViajes.h"
#include "../include/interface/IControladorVehiculos.h"



class Menu {
private:
    void altaUsuario(IControladorUsuarios* iCu);
    void altaViaje(IControladorVehiculos* icv);
    void generarReserva(IControladorUsuarios* icu, IControladorViajes * icv);
    void calificarUsuario(IControladorUsuarios* icu, IControladorViajes* icv);
    void eliminarViaje(IControladorUsuarios* icu, IControladorViajes* icv);
    void administrarFechaActual(IControladorFechaActual* controladorFecha);
    void cargarDatos();

public:
    void mostrarMenu();
};

#endif
