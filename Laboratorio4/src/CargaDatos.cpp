#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/interface/IControladorUsuarios.h"
#include "../include/interface/IControladorViajes.h"
#include "../include/interface/IControladorFechaActual.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"
#include "../include/DTFecha.h"
#include "../include/TipoLibreta.h"
#include "../include/TipoVehiculo.h"
#include <iostream>

CargaDatos* CargaDatos::instancia = nullptr;

CargaDatos::CargaDatos() {
    datosCargados = false;
}

CargaDatos* CargaDatos::getInstance() {
    if (instancia == nullptr) {
        instancia = new CargaDatos();
    }
    return instancia;
}

void CargaDatos::cargarDatos() {
    if (datosCargados) {
        std::cout << "Error: Los datos ya han sido cargados anteriormente.\n";
        return;
    }

    std::cout << "Cargando datos harcodeados del sistema...\n";

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorUsuarios* icu = fabrica->getIControladorUsuarios();
    IControladorViajes* icv = fabrica->getIControladorViajes();
    IControladorFechaActual* fechaCtrl = fabrica->getIControladorFechaActual();

    fechaCtrl->setFecha(DTFecha(13, 3, 2026));

    // --- Usuario_Conductor ---
    {
        std::map<TipoLibreta, bool> libs = {
            {TipoLibreta::MotoProfesional, false},
            {TipoLibreta::MotoAmateur, false},
            {TipoLibreta::AutoProfesional, false},
            {TipoLibreta::AutoAmateur, true}
        };
        icu->altaConductor("matil92", "Matias Lopez", "m4t14s92", "matias.lopez.92@gmail.com", libs);
    }
    {
        std::map<TipoLibreta, bool> libs = {
            {TipoLibreta::MotoProfesional, false},
            {TipoLibreta::MotoAmateur, false},
            {TipoLibreta::AutoProfesional, true},
            {TipoLibreta::AutoAmateur, false}
        };
        icu->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", libs);
    }
    {
        std::map<TipoLibreta, bool> libs = {
            {TipoLibreta::MotoProfesional, false},
            {TipoLibreta::MotoAmateur, true},
            {TipoLibreta::AutoProfesional, false},
            {TipoLibreta::AutoAmateur, false}
        };
        icu->altaConductor("greg_m", "Diego Rodriguez", "drodriguez88", "diegorodriguez@fing.edu.uy", libs);
    }
    {
        std::map<TipoLibreta, bool> libs = {
            {TipoLibreta::MotoProfesional, true},
            {TipoLibreta::MotoAmateur, false},
            {TipoLibreta::AutoProfesional, false},
            {TipoLibreta::AutoAmateur, false}
        };
        icu->altaConductor("lau_vaz", "Laura Vazquez", "lvazquezQ7", "laura.vazquez@fing.edu.uy", libs);
    }
    {
        std::map<TipoLibreta, bool> libs = {
            {TipoLibreta::MotoProfesional, false},
            {TipoLibreta::MotoAmateur, true},
            {TipoLibreta::AutoProfesional, true},
            {TipoLibreta::AutoAmateur, false}
        };
        icu->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", libs);
    }

    // --- Usuario_Pasajero ---
    icu->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    icu->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    icu->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    icu->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    icu->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    // --- Vehiculo ---
    icu->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", TipoVehiculo::Auto);
    icu->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", TipoVehiculo::Auto);
    icu->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", TipoVehiculo::Auto);
    icu->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", TipoVehiculo::Auto);
    icu->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", TipoVehiculo::Moto);
    icu->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", TipoVehiculo::Moto);
    icu->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", TipoVehiculo::Auto);
    icu->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", TipoVehiculo::Moto);

    // --- Viaje ---
    icv->altaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
    icv->altaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
    icv->altaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
    icv->altaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
    icv->altaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
    icv->altaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
    icv->altaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
    icv->altaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
    icv->altaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
    icv->altaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
    icv->altaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
    icv->altaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
    icv->altaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    // --- Reserva ---
    fechaCtrl->setFecha(DTFecha(14, 3, 2026));
    icv->generarReserva("santi_90", 9, 2);
    icv->generarReserva("mari_b", 9, 1);
    icv->generarReserva("nacho_f", 10, 5);
    icv->generarReserva("valen_uy", 10, 3);
    icv->generarReserva("joaco_r", 10, 1);

    fechaCtrl->setFecha(DTFecha(13, 3, 2026));
    icv->generarReserva("mari_b", 12, 1);
    icv->generarReserva("nacho_f", 12, 1);
    icv->generarReserva("nacho_f", 9, 1);

    fechaCtrl->setFecha(DTFecha(1, 6, 2026));
    icv->generarReserva("mari_b", 1, 2);

    // --- Calificacion ---
    fechaCtrl->setFecha(DTFecha(14, 3, 2026));

    ManejadorUsuarios::getInstance()->setNicknameCalificador("santi_90");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    icu->calificarUsuario("matil92", 4);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("mari_b");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    icu->calificarUsuario("matil92", 4);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("matil92");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    icu->calificarUsuario("mari_b", 3);

    fechaCtrl->setFecha(DTFecha(15, 3, 2026));
    ManejadorUsuarios::getInstance()->setNicknameCalificador("ana_silva");
    ManejadorViajes::getInstance()->setCodigoViajeActual(10);
    icu->calificarUsuario("valen_uy", 5);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("ana_silva");
    ManejadorViajes::getInstance()->setCodigoViajeActual(10);
    icu->calificarUsuario("joaco_r", 5);

    fechaCtrl->setFecha(DTFecha(13, 3, 2026));
    ManejadorUsuarios::getInstance()->setNicknameCalificador("mari_b");
    ManejadorViajes::getInstance()->setCodigoViajeActual(12);
    icu->calificarUsuario("carlos_r", 5);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("carlos_r");
    ManejadorViajes::getInstance()->setCodigoViajeActual(12);
    icu->calificarUsuario("nacho_f", 5);

    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";
}
