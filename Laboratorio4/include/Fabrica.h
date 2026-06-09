#ifndef FABRICA_H
#define FABRICA_H


class IControladorUsuarios;
class IControladorViajes;
class IControladorVehiculos;
class IControladorFechaActual;
class ControladorFechaActual;
class ControladorUsuarios;
class ControladorViajes;
class ControladorVehiculos;



class Fabrica {
private:
    static Fabrica * instancia;

    Fabrica();

public:
    static Fabrica * getInstance();
    IControladorFechaActual* getIControladorFechaActual();
    IControladorUsuarios* getIControladorUsuarios();
    IControladorViajes* getIControladorViajes();
    IControladorVehiculos* getIControladorVehiculos();
    
/*
    IVehiculo * getIVehiculo();
    IUsuario * getIUsuario();
    IViaje * getIViaje();
*/
    };

#endif
