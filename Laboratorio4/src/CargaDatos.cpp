#include "../include/CargaDatos.h"
#include "../include/Fabrica.h"
#include "../include/interface/IControladorUsuarios.h"
#include "../include/interface/IControladorViajes.h"
#include "../include/interface/IControladorVehiculos.h"
#include "../include/manejador/ControladorFechaActual.h"
#include "../include/manejador/ManejadorUsuarios.h"
#include "../include/manejador/ManejadorViajes.h"
#include <iostream>
#include <limits>

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

    IControladorUsuarios* iCU = Fabrica::getInstance()->getIControladorUsuarios();
    IControladorViajes* iCVia = Fabrica::getInstance()->getIControladorViajes();
    IControladorVehiculos* iCV = Fabrica::getInstance()->getIControladorVehiculos();

    std::cout << "Cargando datos harcodeados del sistema...\n";
    
    // Cargar conductores

    std::map<TipoLibreta, bool> librerasMatil92;
    librerasMatil92[AutoAmateur] = true;
    librerasMatil92[AutoProfesional] = false;
    librerasMatil92[MotoAmateur] = false;
    librerasMatil92[MotoProfesional] = false;
    iCU->altaConductor("matil92", "Matías López", "m4t14s92", "matias.lopez.92@gmail.com", librerasMatil92);
    
    std::map<TipoLibreta, bool> librerasAnaSilva;
    librerasAnaSilva[AutoAmateur] = false;
    librerasAnaSilva[AutoProfesional] = true;
    librerasAnaSilva[MotoAmateur] = false;
    librerasAnaSilva[MotoProfesional] = false;
    iCU->altaConductor("ana_silva", "Ana Silva", "asilva2026", "anasilva.m@outlook.com", librerasAnaSilva);

    std::map<TipoLibreta, bool> librerasGregM;
    librerasGregM[AutoAmateur] = false;
    librerasGregM[AutoProfesional] = false;
    librerasGregM[MotoAmateur] = true;
    librerasGregM[MotoProfesional] = false;
    iCU->altaConductor("greg_m", "Diego Rodríguez", "rodriguez8", "diegorodriguez@fing.edu.uy", librerasGregM);
    std::map<TipoLibreta, bool> librerasLauVaz;
    
    librerasLauVaz[AutoAmateur] = false;
    librerasLauVaz[AutoProfesional] = false;
    librerasLauVaz[MotoAmateur] = false;
    librerasLauVaz[MotoProfesional] = true;
    iCU->altaConductor("lau_vaz", "Laura Vázquez", "vazquezQ", "laura.vazquez@fing.edu.uy", librerasLauVaz);
    
    std::map<TipoLibreta, bool> librerasCarlosR;
    librerasCarlosR[AutoAmateur] = false;
    librerasCarlosR[AutoProfesional] = true;
    librerasCarlosR[MotoAmateur] = true;
    librerasCarlosR[MotoProfesional] = false;
    iCU->altaConductor("carlos_r", "Carlos Rossi", "crossi99x", "carlos.rossi.uy@gmail.com", librerasCarlosR);


    // Cargar pasajeros
    iCU->altaPasajero("santi_90", "Santiago Acosta", "sacosta90", "santiago.acosta@gmail.com", "1.492.304-2");
    iCU->altaPasajero("mari_b", "Maria Noel Barreto", "maribarreto6", "mari.barreto@outlook.com", "4.103.859-1");
    iCU->altaPasajero("nacho_f", "Ignacio Figueroa", "ifigueroa26", "ignacio.figueroa@fing.edu.uy", "3.847.112-5");
    iCU->altaPasajero("valen_uy", "Valentina Mendez", "vmendezQ2", "valen.mendez@fing.edu.uy", "2.956.403-0");
    iCU->altaPasajero("joaco_r", "Joaquin Rivero", "jrivero99x", "joaquin_rivero@hotmail.com", "5.021.784-3");

    // Cargar vehiculos
    iCU->registrarVehiculo("matil92", "ABJ4586", 4, "Chevrolet", "Onix", Auto);
    iCU->registrarVehiculo("matil92", "ACM4455", 6, "Toyota", "Rush", Auto);
    iCU->registrarVehiculo("ana_silva", "BAS7895", 4, "Fiat", "Argo", Auto);
    iCU->registrarVehiculo("ana_silva", "BCS4105", 9, "Hyundai", "H1", Auto);
    iCU->registrarVehiculo("greg_m", "LDA4875", 1, "Honda", "CB Twist", Moto);
    iCU->registrarVehiculo("lau_vaz", "PDB1205", 1, "Yumbo", "Max 110", Moto);
    iCU->registrarVehiculo("carlos_r", "SBJ4874", 4, "Volkswagen", "Gol", Auto);
    iCU->registrarVehiculo("carlos_r", "SCF2469", 1, "Yamaha", "FZ S", Moto);

    // Cargar viajes
    iCV->AltaViaje("ABJ4586", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 200);
    iCV->AltaViaje("ACM4455", DTFecha(20, 10, 2026), "young", "montevideo", 5, 250);
    iCV->AltaViaje("BAS7895", DTFecha(20, 10, 2026), "young", "montevideo", 4, 200);
    iCV->AltaViaje("BCS4105", DTFecha(21, 10, 2026), "montevideo", "mercedes", 9, 200);
    iCV->AltaViaje("LDA4875", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 300);
    iCV->AltaViaje("PDB1205", DTFecha(21, 10, 2026), "montevideo", "mercedes", 1, 350);
    iCV->AltaViaje("SBJ4874", DTFecha(21, 10, 2026), "montevideo", "mercedes", 4, 260);
    iCV->AltaViaje("SCF2469", DTFecha(20, 10, 2026), "montevideo", "cerro chato", 1, 150);
    iCV->AltaViaje("ABJ4586", DTFecha(15, 3, 2026), "montevideo", "colonia", 4, 140);
    iCV->AltaViaje("BCS4105", DTFecha(15, 3, 2026), "montevideo", "colonia", 9, 180);
    iCV->AltaViaje("SBJ4874", DTFecha(15, 3, 2026), "montevideo", "colonia", 1, 100);
    iCV->AltaViaje("SBJ4874", DTFecha(14, 3, 2026), "montevideo", "colonia", 4, 600);
    iCV->AltaViaje("LDA4875", DTFecha(20, 10, 2026), "young", "montevideo", 1, 250);

    // Cargar reservas
    
    ControladorFechaActual::getInstance()->setFecha(DTFecha(14, 3, 2026));
    iCVia->generarReserva("santi_90", 9, 2);
    iCVia->generarReserva("mari_b", 9, 1);
    iCVia->generarReserva("nacho_f", 10, 5);
    iCVia->generarReserva("valen_uy", 10, 3);
    iCVia->generarReserva("joaco_r", 10, 1);

    ControladorFechaActual::getInstance()->setFecha(DTFecha(13, 3, 2026));
    iCVia->generarReserva("mari_b", 12, 1);
    iCVia->generarReserva("nacho_f", 12, 1);

    ControladorFechaActual::getInstance()->setFecha(DTFecha(1, 6, 2026));
    iCVia->generarReserva("mari_b", 1, 2);

    ControladorFechaActual::getInstance()->setFecha(DTFecha(13, 3, 2026));
    iCVia->generarReserva("nacho_f", 9, 1);

    // Cargar calificaciones
    ManejadorUsuarios::getInstance()->setNicknameCalificador("santi_90");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    iCU->calificarUsuario("matil92", 4);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("mari_b");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    iCU->calificarUsuario("matil92", 4);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("matil92");
    ManejadorViajes::getInstance()->setCodigoViajeActual(9);
    iCU->calificarUsuario("mari_b", 3);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("ana_silva");
    ManejadorViajes::getInstance()->setCodigoViajeActual(10);
    iCU->calificarUsuario("valen_uy", 5);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("ana_silva");
    ManejadorViajes::getInstance()->setCodigoViajeActual(10);
    iCU->calificarUsuario("joaco_r", 5);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("mari_b");
    ManejadorViajes::getInstance()->setCodigoViajeActual(12);
    iCU->calificarUsuario("carlos_r", 5);

    ManejadorUsuarios::getInstance()->setNicknameCalificador("carlos_r");
    ManejadorViajes::getInstance()->setCodigoViajeActual(12);
    iCU->calificarUsuario("nacho_f", 5);


    datosCargados = true;
    std::cout << "Datos cargados exitosamente.\n";

    delete iCU;
    delete iCVia;
    delete iCV;
}
