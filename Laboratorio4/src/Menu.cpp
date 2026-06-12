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
#include "../include/Conductor.h"

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




    IControladorUsuarios* ICU = Fabrica::getInstance()->getIControladorUsuarios();
    bool usuarioOk = false;

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
            tipo = auxTipo <= 0 ? Auto : Moto;

            int resultadoRegistrarVehiculo = ICU->registrarVehiculo(nickname, matricula, capacidad, marca, modelo, tipo);
            
            if (resultadoRegistrarVehiculo == -1) {
                std::cout << "Ya existe un vehiculo con esa matricula.\n";
            } else if (resultadoRegistrarVehiculo == -2) {
                std::cout << "El conductor no tiene la libreta necesaria para registrar ese vehiculo.\n";
            } else if (resultadoRegistrarVehiculo == 0) {
                std::cout << "Vehiculo registrado exitosamente.\n";
            } else {
                std::cout << "Error al registrar vehiculo.\n";
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
        std::cout << "> Matricula: " << v.getMatricula()
                  << ", Modelo: " << v.getMarca()
                  << ", Capacidad: " << v.getCapacidad() << "\n";
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
    bool viajeOk = icv->AltaViaje(matricula, fecha, origen, destino, asientos, precio);

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

    if (viajes.empty()) {
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
        for (DTConsultaViaje* v : viajes) delete v;
        return;
    }

    bool reservaOk = icv->generarReserva(nickname, codigo, asientos);
    if (reservaOk) {
        std::cout << "Reserva realizada exitosamente.\n";
    } else {
        std::cout << "Error al realizar la reserva.\n";
    }

    for (DTConsultaViaje* v : viajes) delete v;
}

void Menu::calificarUsuario() {


        /*El caso de uso comienza cuando se desea realizar una calificación para un
    usuario. Para esto el Sistema lista los nicknames y nombres de todos los
    usuarios y el Administrador selecciona el usuario que desea realizar la
    calificación, luego el Sistema lista de mayor a menor el código de todos los
    viajes para el usuario seleccionado. 

        -Si el usuario seleccionado es un conductor
        lista todos los viajes asociados a un vehículo registrado 

        -en cambio si el usuario
        seleccionado es un pasajero lista los viajes para los que se tenga una reserva.

    A continuación el Administrador ingresa el código del viaje y el sistema lista el
    nickname y tipo de todos los usuarios asociados al viaje que no sean el
    usuario seleccionado. Por último, el Administrador ingresa el nickname del
    usuario y su calificación del 1 al 5, y el sistema genera la calificación con el
    valor ingresado y la fecha actual del sistema.

    */
    
        //pido fabrica interface controlador usuarios
        IControladorUsuarios* icu = Fabrica::getInstance()->getIControladorUsuarios();

        // guardo en usuarios una lista icu que viene desde listarUsuarios metodos
        std::list<DTUsuario> usuarios = icu->listarUsuarios();

    //listamos nicknames y nombres de todos los usuarios
    for (DTUsuario& u : usuarios) {
        std::cout << "> Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre() << std::endl;
    }


    //a dmin seleciona nickname para
    std::string nickname;
    std::cout << "Ingrese su nickname: "; std::getline(std::cin, nickname);
    //check if nick exists 
    bool nickpasajero = false; // assumo que no es pasajero
    bool nicknameValido = false;
    for (DTUsuario& u : usuarios) {
        if (u.getNickname() == nickname) { nicknameValido = true; break; }
    }
    
    if (!nicknameValido) {
        std::cout << "Nickname invalido.\n";
        return;
    }
        //-Si el usuario seleccionado es un conductor lista todos los viajes asociados a un vehículo registrado 

       // -en cambio si el usuario seleccionado es un pasajero lista los viajes para los que se tenga una reserva.




    // TRUCO aca diferencio entre pasajero y conductor utilizando dinamic cast;

        //primero declaro u usuario llamandola por el ManejadorUsuarios DE EL NICKNAME 
        Usuario* u = ManejadorUsuarios::getInstance()->getUsuario(nickname);
        // aca dependiendo el {dinamic_cast} va a basicamente checkear si el valor de u Usuario es pasajer
        nickpasajero = (dynamic_cast<Pasajero*>(u) != nullptr); 
        // si es pasjero true si no es false sheesh

    






// TODO adentro de losif elses tengo que :

        //  //  lista los viajes para los que se tenga una reserva.
    // o tengo que

    //  //lista todos los viajes asociados a un vehículo registrado 

// y no lo he hecho aun ups

    if (nickpasajero){
        //  lista los viajes para los que se tenga una reserva.

        std::list<DTListarViaje> viajes = icu->listarViajes(nickname);
                for (DTListarViaje& v : viajes) {
                DTFecha f = v.getFecha();
                std::cout << "> Codigo: " << v.getCodigo() << ", Fecha: "
                        << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
                        << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino()
                        << ", Conductor: " << v.getNicknameConductor() << std::endl;
                }


    } else {
        //lista todos los viajes asociados a un vehículo registrado 
        std::list<DTListarViaje> viajes = icu->listarViajes(nickname);
                for (DTListarViaje& v : viajes) {   
                DTFecha f = v.getFecha();
                std::cout << "> Codigo: " << v.getCodigo() << ", Fecha: "
                << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
                << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino()
                << ", Conductor: " << v.getNicknameConductor() << std::endl;
                }


        }





    // A continuación el Administrador ingresa el código del viaje y el sistema lista el nickname y tipo de todos los usuarios asociados al viaje que no sean el usuario seleccionado.
        std::list<DTListarViaje> viajes = icu->listarViajes(nickname);

    //in codigo
        int codigo;
        std::cout << "Ingrese codigo del viaje: "; std::cin >> codigo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    /// check codigo
        bool codigoValido = false;
        for (DTListarViaje& v : viajes) {
            if (v.getCodigo() == codigo) { codigoValido = true; break; }
        }
        if (!codigoValido) {
            std::cout << "Codigo invalido.\n";
            return;
        }


        //llamo instancia
        IControladorViajes* icv = Fabrica::getInstance()->getIControladorViajes();
        // adentro de usuariosViaje guardo la list de Usuarios de el viaje de codigo
        std::list<DTUsuarioViaje*> usuariosViaje = icv->listarUsuariosViaje(codigo);
    // out lista de nicknames y sus tipos (EXLUYENDO A SI MISMO)    
        // itero usuarios
        for (DTUsuarioViaje* uv : usuariosViaje) {
            // aca hago con que si el nombre NO es igual al de usuario imprimo y si es no hago nada
            if (uv->getNickname() != nickname) {
                  std::string tipo;
                if (uv->getTipo() == conductor) {tipo = "Conductor";} 
                else {tipo = "Pasajero";}                       
                std::cout << "> Nickname: " << uv->getNickname() << ", Tipo: " << tipo << std::endl;
                 }
        }

    
        std::string nicknameCalificado;
        int calificacion;
    // in nick de usuario a calificar y su calificacion
        std::cout << "Ingrese nickname del usuario a calificar: "; std::getline(std::cin, nicknameCalificado);
        std::cout << "Ingrese calificacion (1-5): "; std::cin >> calificacion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // chekeo que el nickname es valido
        bool nicknameCalificadoValido = false;
        for (DTUsuarioViaje* uv : usuariosViaje) {
            if (uv->getNickname() == nicknameCalificado) { nicknameCalificadoValido = true; break; }
        }
        if (!nicknameCalificadoValido) {
            std::cout << "Nickname invalido.\n";
            return;
        }


    ManejadorUsuarios::getInstance()->setNicknameCalificador(nickname);
    ManejadorViajes::getInstance()->setCodigoViajeActual(codigo);


    // genero la calificacion con la fecha actual y el nombre (la parte de la fecha se implemente en calificarUsuario)
    bool calificacionOk = icu->calificarUsuario(nicknameCalificado, calificacion);  
    if (calificacionOk) {
        std::cout << "Calificacion exitosa.\n";
    } else {
        std::cout << "Error al calificar.\n";
    }
}


void Menu::eliminarViaje() {
    IControladorUsuarios* icu = Fabrica::getInstance()->getIControladorUsuarios();
    std::list<DTListarViaje> viajes = icu->listarViajes();
    for (DTListarViaje& v : viajes) {
        DTFecha f = v.getFecha();
        std::cout << "> Codigo: " << v.getCodigo() << ", Fecha: " << f.getDia() << "/" << f.getMes() << "/" << f.getAnio()
                  << ", Origen: " << v.getOrigen() << ", Destino: " << v.getDestino()
                  << ", Conductor: " << v.getNicknameConductor() << std::endl;
    }

    int codigo;
    std::cout << "Ingrese codigo del viaje a eliminar: "; std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    bool codigoValido = false;
    for (DTListarViaje& v : viajes) {
        if (v.getCodigo() == codigo) { codigoValido = true; break; }
    }
    if (!codigoValido) {
        std::cout << "Codigo invalido.\n";
        return;
    }

    IControladorViajes* icv = Fabrica::getInstance()->getIControladorViajes();
    DTDetalleViaje detalle = icv->detalleViaje(codigo);
    DTFecha fViaje = detalle.getFecha();
    std::cout << ">> Viaje <<\n";
    std::cout << "--- Codigo: " << detalle.getCodigo()
              << ", Fecha: " << fViaje.getDia() << "/" << fViaje.getMes() << "/" << fViaje.getAnio()
              << ", Origen: " << detalle.getOrigen() << ", Destino: " << detalle.getDestino()
              << ", AsientosPublicados: " << detalle.getAsientosPublicados()
              << ", Precio por asiento: " << detalle.getPrecio() << "\n";

    DTDetalleVehiculo dv = detalle.getVehiculo();
    std::cout << ">> Vehiculo <<\n";
    std::cout << "--- Matricula: " << dv.getMatricula()
              << ", Capacidad: " << dv.getCapacidad()
              << ", Marca: " << dv.getMarca()
              << ", Modelo: " << dv.getModelo()
              << ", Tipo: " << (dv.getTipo() == Auto ? "Auto" : "Moto") << "\n";

    std::cout << ">> Reservas <<\n";
    for (DTDetalleReserva& r : detalle.getReservas()) {
        DTFecha fRes = r.getFecha();
        std::cout << "--- AsientosReservados: " << r.getAsientosReservados()
                  << ", Fecha: " << fRes.getDia() << "/" << fRes.getMes() << "/" << fRes.getAnio()
                  << ", Pasajero: " << r.getPasajero() << "\n";
    }

    int confirmar;
    std::cout << "¿Confirmar eliminacion? (1: Si, 0: No): "; std::cin >> confirmar;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirmar == 1) {
        icv->eliminarViaje(codigo);
        std::cout << "Viaje eliminado exitosamente.\n";
    } else {
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
    while (opcion != 0) {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "1. Alta de usuario\n";
        std::cout << "2. Alta de viaje\n";
        std::cout << "3. Generar Reserva\n";
        std::cout << "4. Calificar usuario\n";
        std::cout << "5. Eliminar viaje\n";
        std::cout << "6. Modificar fecha del sistema\n";
        std::cout << "7. Cargar Datos\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";
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
            case 0:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    }
}
