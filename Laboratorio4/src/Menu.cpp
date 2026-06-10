#include "../include/Menu.h"
#include "../include/Fabrica.h"
#include "../include/interface/IControladorFechaActual.h"
#include "../include/CargaDatos.h"
#include "../include/DTFecha.h"
#include "../include/DTConsultaViaje.h"

#include "../include/controller/ControladorUsuarios.h"
#include "../include/controller/ControladorViajes.h"
#include "../include/controller/ControladorVehiculos.h"

#include "../include/manejador/ManejadorViajes.h"
#include "../include/manejador/ManejadorVehiculos.h"
#include "../include/manejador/ManejadorUsuarios.h"

#include <limits>
#include <iostream>
#include <limits>
#include <string>
#include <set>
#include <list>

void Menu::altaUsuario() {
    int tipoUsuario;
    std::cout << "1. Alta Pasajero\n";
    std::cout << "2. Alta Conductor\n";
    std::cout << "Seleccione: ";
    std::cin >> tipoUsuario; 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (tipoUsuario != 1 && tipoUsuario != 2) {
        std::cout << "Opcion invalida.\n";
        return;
    }

    std::string nickname, nombre, contrasena, email;
    std::cout << "Ingrese nickname: "; std::getline(std::cin, nickname);
    std::cout << "Ingrese nombre: "; std::getline(std::cin, nombre);
    std::cout << "Ingrese contrasena: "; std::getline(std::cin, contrasena);
    std::cout << "Ingrese email: "; std::getline(std::cin, email);




    bool usuarioOk = false;
    IControladorUsuarios* ICU = Fabrica::getInstance()->getIControladorUsuarios();

    if (tipoUsuario == 1) {
        std::string ci;
        std::cout << "Ingrese CI: "; std::getline(std::cin, ci);
        IControladorUsuarios* icu = Fabrica::getInstance()->getIControladorUsuarios();
        icu->altaPasajero(nickname,nombre,contrasena,email,ci);
        
    } else if (tipoUsuario == 2) {
        
        
        bool tieneMotoProfesional = false;
        bool tieneMotoAmateur = false;
        bool tieneAutoProfesional = false;
        bool tieneAutoAmateur = false;

        int cantLibretas = 0;
        int agregarLibreta = 1;

        while (agregarLibreta == 1 && cantLibretas < 4) {
            int tipoLibreta;
            std::cout << "\n=== Registrar Libreta ===\n";
            std::cout << "0. Moto (Profesional)\n";
            std::cout << "1. Moto (Amateur)\n";
            std::cout << "2. Auto (Profesional)\n";
            std::cout << "3. Auto (Amateur)\n";
            std::cout << "Seleccione el tipo de libreta: ";
            std::cin >> tipoLibreta;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


            bool yaExiste = false;
            if (tipoLibreta == 0) {
                if (tieneMotoProfesional) {
                    yaExiste = true;
                } else {
                    tieneMotoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 1) {
                if (tieneMotoAmateur) {
                    yaExiste = true;
                } else {
                    tieneMotoAmateur = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 2) {
                if (tieneAutoProfesional) {
                    yaExiste = true;
                } else {
                    tieneAutoProfesional = true;
                    cantLibretas++;
                }
            } else if (tipoLibreta == 3) {
                if (tieneAutoAmateur) {
                    yaExiste = true;
                } else {
                    tieneAutoAmateur = true;
                    cantLibretas++;
                }
            } else {
                std::cout << "Opcion invalida.\n";
                continue;
            }

            if (yaExiste) {
                std::cout << "Esa libreta ya fue ingresada.\n";
            } else {
                std::cout << "Libreta agregada.\n";
            }

            if (cantLibretas < 4) {
                std::cout << "¿Desea agregar otra libreta? (1: Si, 0: No): ";
                std::cin >> agregarLibreta;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Se ha alcanzado el limite maximo de libretas.\n";
            }
        }

        if (cantLibretas == 0) {
            std::cout << "Debe ingresar al menos una libreta para registrar un conductor.\n";
            return;
        }

        // Ejemplo de como armar el conjunto de libretas utilizando map
        std::map<TipoLibreta, bool> libretas =  {
                {TipoLibreta::MotoProfesional, tieneMotoProfesional},
                {TipoLibreta::MotoAmateur, tieneMotoAmateur},
                {TipoLibreta::AutoProfesional, tieneAutoProfesional},
                {TipoLibreta::AutoAmateur, tieneAutoAmateur}
            };
        
        usuarioOk = ICU->altaConductor(nickname, nombre, contrasena, email, libretas);
        int agregarVehiculo = 1;
        while (usuarioOk == true && agregarVehiculo == 1) {
            std::string matricula, marca, modelo;
            int capacidad, auxTipo;
            TipoVehiculo tipo;

            std::cout << "\n=== Registrar Vehiculo ===\n";
            std::cout << "Ingrese matricula: "; std::getline(std::cin, matricula);
            std::cout << "Ingrese capacidad: "; std::cin >> capacidad;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ingrese marca: "; std::getline(std::cin, marca);
            std::cout << "Ingrese modelo: "; std::getline(std::cin, modelo);
            std::cout << "Ingrese tipo (0: Auto, 1: Moto): "; std::cin >> auxTipo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            int resultadoRegistrarVehiculo = -3;

            tipo = auxTipo <= 0 ? Auto : Moto;

            resultadoRegistrarVehiculo = ICU->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo);
            
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            }
            std::cout << "¿Desea agregar otro vehiculo? (1: Si, 0: No): ";
            std::cin >> agregarVehiculo;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::altaViaje() {
    std::string nickname, 
                matricula, 
                origen, 
                destino;
            int dia, 
                mes, 
                anio, 
                asientos;   
          float precio;
    /*"El caso de uso comienza cuando se desea generar un nuevo viaje. El
    Administrador indica el nickname del conductor que quiere generar el viaje y el
    Sistema lista todos los vehículos registrados para este conductor incluyendo
    matrícula, modelo y capacidad del vehículo. 
    
    Luego el Administrador ingresa la matrícula del vehículo, fecha del viaje, origen, destino, cantidad de asientos disponibles para el viaje y el precio por asiento.

    El Sistema da de alta el viaje con los datos ingresados y un código incremental
    autogenerado. En caso de que ya exista un viaje para la misma fecha o se
    supere la cantidad de asientos disponibles del vehículo, el Sistema comunica
    el error y no se da de alta el viaje" */
            

    // In Nickname
    std::cout << "Ingrese nickname del conductor: "; std::getline(std::cin, nickname);
     
    // Inicializo una instancia de fabrica hacia IControladorVehiculo
    IControladorVehiculos* icv = Fabrica::getInstance()->getIControladorVehiculos();

    // Guardo en lista la lista de los DTVehiculos 
    std::list<DTVehiculosConductor> lista = icv->ListarVehiculosConductor(nickname);


    // Itero en lista y imprimo utilizando los gets
    if (lista.empty()) {
        std::cout << "No hay Vehiculos a nombre del Nickname \n" ;
        return; 
    }
    for (const auto& v : lista) {
    std::cout << "Matrícula: " << v.getMatricula()
              << ", Capacidad: " << v.getCapacidad()
              << ", Modelo: " << v.getModelo()
              << "\n";
        }

    // In Matricula
    std::cout << "Ingrese matricula del vehiculo a utilizar: "; std::getline(std::cin, matricula);


    /*
        bool matriculaValida = matriculaValido(matricula);
        //Chekeo Valiz de matriculo
        if (!matriculaValida()) {
            std::cout << "Matricula invalida.\n";
            return;
         }
    */

    // In fecha
    std::cout << "Ingrese fecha del viaje (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // In origen
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);

    // In destino
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);

    // In cant asientos
    std::cout << "Ingrese cantidad de asientos: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // in precio
    std::cout << "Ingrese precio por asiento: "; std::cin >> precio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    //ACA TENGO QUE PRIMERO CREAR UN DTFECHA para la fucnion ALtaViaje
    DTFecha fecha = DTFecha(dia,mes,anio);

    // A partir de la misma instancia de IControladorVehiculos llamo a AltaViaje   
    // y lo guardo en viajeOk
    bool viajeOk = false; 
    viajeOk = icv->AltaViaje(matricula, fecha, origen, destino, asientos, precio);

        // AltaViaje que me chekea si los datos estan corrector en especifico :
        // capacidad del auto < asientos => retorna false
        // hayViajeFechas == true => retorna false 

        // Me genera un viaje nuevo con los datos mandados y retorna true si esta todo bien
    
    if (viajeOk) {
        std::cout << "Viaje registrado exitosamente.\n";
    } else {
        std::cout << "Error al registrar el viaje.\n";
    }

    


}

void Menu::generarReserva() {
    IControladorUsuarios* icu = Fabrica::getInstance()->getIControladorUsuarios();
    std::list<DTUsuario> pasajeros = icu->listarPasajeros();
    for (DTUsuario& p : pasajeros) {
        std::cout << "> " << p.getNickname() << std::endl;
    }

    std::string nickname;
    std::cout << "Ingrese nickname del pasajero: "; std::getline(std::cin, nickname);

    bool nicknameValido = false;
    for (DTUsuario& p : pasajeros) {
        if (p.getNickname() == nickname) { nicknameValido = true; break; }
    }
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    int dia, mes, anio, asientos;
    std::string origen, destino;
    std::cout << "Ingrese fecha del viaje a consultar (dia mes anio): "; std::cin >> dia >> mes >> anio;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ingrese origen: "; std::getline(std::cin, origen);
    std::cout << "Ingrese destino: "; std::getline(std::cin, destino);
    std::cout << "Ingrese cantidad de asientos a reservar: "; std::cin >> asientos;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    IControladorViajes* icv = Fabrica::getInstance()->getIControladorViajes();
    std::set<DTConsultaViaje*> viajes = icv->consultarViajes(DTFecha(dia, mes, anio), origen, destino, asientos);
    for (DTConsultaViaje* v : viajes) {
        std::cout << "> Codigo: " << v->getCodigo() << ", Marca: " << v->getMarca()
                  << ", Modelo: " << v->getModelo() << ", Conductor: " << v->getNombreConductor()
                  << ", CalificacionPromedio: " << v->getCalificacionProm()
                  << ", PrecioTotal: " << v->getPrecioTotal() << std::endl;
    }

    bool hayViajes = !viajes.empty();
    if (!hayViajes) {
        std::cout << "No hay viajes disponibles.\n";
        return;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a reservar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool codigoValido = false;
    for (DTConsultaViaje* v : viajes) {
        if (v->getCodigo() == codigo) { codigoValido = true; break; }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    bool reservaOk = icv->generarReserva(nickname, codigo, asientos);
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }
}

void Menu::calificarUsuario() {
    //TODO: Coleccion de DTUsuario = controlador->listarUsuarios()
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Nombre: yyy"
    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    bool nicknameValido = false;
    //TODO: Validar nickname en listado
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    //TODO: Coleccion de DTListarViaje = controlador->listarViajes(nickname)
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    int codigo;
    std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: Coleccion de DTUsuarioViaje = Controlador->listarUsuariosViaje(codigo)
    //TODO: Recorrer la coleccion y mostrar "> Nickname: xx, Tipo: yyy"
    std::string nicknameCalificado;
    int calificacion;
    std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
    std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool nicknameCalificadoValido = false;
    //TODO: Validar nickname en listado
    if (!nicknameCalificadoValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }

    bool calificacionOk = false;
    //TODO: calificacionOk = Controlador->calificarUsuario(nicknameCalificado, calificacion)
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}

void Menu::eliminarViaje() {
    //TODO: Coleccion de DTListarViaje = controlador->listarViajes()
    //TODO: Recorrer la coleccion y mostrar "> Codigo: xx, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Conductor: aaa"
    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    bool codigoValido = false;
    //TODO: Validar codigo en listado
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    //TODO: DTDetalleViaje = controlador->detalleViaje(codigo)
    //TODO: Mostrar detalle del viaje siguiendo el formato
    //>> Viaje <<
    //--- Matrícula: aa, Fecha: dd/mm/aaaa, Origen: zzz, Destino: www, Capacidad: bbb, Precio por asiento: qqq
    //>> Vehiculo <<
    //--- Matricula: mm, Capacidad: aa, Marca: bbb, Modelo: ccc, Tipo: ddd
    //>> Reservas <<
    //--- AsientosReservados: xx, Fecha: dd/mm/aaaa, Pasajero: aaa
    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        //TODO: controlador->eliminarViaje()
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
        //TODO: controlador->cancelarEliminarViaje()
        std::cout << "Eliminacion cancelada.\n";
    }
}

void Menu::administrarFechaActual() {
    int opFecha;
    std::cout << "1. Ver fecha actual\n";
    std::cout << "2. Modificar fecha actual\n";
    std::cout << "Seleccione: ";
    std::cin >> opFecha;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Fabrica* fabrica = Fabrica::getInstance();
    IControladorFechaActual* controladorFecha = fabrica->getIControladorFechaActual();

    if (opFecha == 1) {
        DTFecha fecha = controladorFecha->getFecha();
        std::cout << "Fecha actual: " << fecha << "\n";
    } else if (opFecha == 2) {
        int dia, mes, anio;
        std::cout << "Ingrese dia: "; std::cin >> dia;
        std::cout << "Ingrese mes: "; std::cin >> mes;
        std::cout << "Ingrese anio: "; std::cin >> anio;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        controladorFecha->setFecha(DTFecha(dia, mes, anio));
        std::cout << "Fecha modificada exitosamente a " << controladorFecha->getFecha() << "\n";
    } else {
        std::cout << "Opcion invalida.\n";
    }
}

void Menu::cargarDatos() {
    CargaDatos::getInstance()->cargarDatos();
}

void listarUsuarios(){
    IControladorUsuarios* iCU = Fabrica::getInstance()->getIControladorUsuarios();
    std::list<DTUsuario> ls = iCU->listarUsuarios(); 
    std::list<DTUsuario>::iterator it;
    for( it = ls.begin(); it != ls.end(); it++){
        std::cout << it->getNickname() << std::endl;
    }
}
void listarVehiculosDe(){
    std::string nickname;
    std::cout << "Ingrese nickname de un conductor: "; std::getline(std::cin, nickname);
    IControladorUsuarios* iCU = Fabrica::getInstance()->getIControladorUsuarios();
    Conductor* c = dynamic_cast<Conductor*>(iCU->getUsuario(nickname));
    if (c != nullptr){
        std::list<Vehiculo*> vehiculos = c->getVehiculos();
        for(const auto it : vehiculos){
            std::cout << it->getMatricula() << std::endl;
        }
    }

}

void Menu::mostrarMenu() {
    int opcion = -1;
    while (opcion != 8) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Alta de Usuario\n";
        std::cout << "2. Alta de Viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar Usuario\n";
        std::cout << "5. Eliminar Viaje\n";
        std::cout << "6. Administrar Fecha Actual\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "8. Salir\n";
        std::cout << "9. Listar usuarios\n";
        std::cout << "10. Listar vehiculos\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                altaUsuario();
                break;
            case 2:
                altaViaje();
                break;
            case 3:
                generarReserva();
                break;
            case 4:
                calificarUsuario();
                break;
            case 5:
                eliminarViaje();
                break;
            case 6:
                administrarFechaActual();
                break;
            case 7:
                cargarDatos();
                break;
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;
            case 9:
                listarUsuarios();
                break;
            case 10:
                listarVehiculosDe();
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
