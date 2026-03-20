#include <iostream>
#include <list>
#include <map>

#include "headers/Turista.h"
#include "headers/Experiencia.h"

#include "headers/Alojamiento.h"
#include "headers/EventoCultural.h"
#include "headers/TourGuiado.h"
#include "headers/DTExp.h"
#include "headers/DTFecha.h"
#include "headers/Enumerados.h"

int main(){



//A-)​ Crear los siguientes objetos de la clase Alojamiento (con el constructor por parámetros):

    Alojamiento alojamiento1 = Alojamiento("ALX5489", "Hotel moderno", 30, DTFecha(18, 05, 2020), "Hotel Lindorf", allInclusive, 5);

    Alojamiento alojamiento2 = Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, DTFecha(10, 02, 2025), "Hotel SeaView", mediaPension, 15);
        

//B-)​ Crear los siguientes objetos de la clase TourGuiado (con el constructor por parámetros):

    //aca seteo los lugares visitados primero 
    // **************** Aca capz haya que cambiaer el order de los push backs o cambioarlos por push front dependiendo del orden

    std::list<std::string> lugares1;
    lugares1.push_back("Plaza Independencia");
    lugares1.push_back("Plaza Matriz");

    std::list<std::string> lugares2;
    lugares2.push_back("Puerta de la Ciudadela");
    lugares2.push_back("Mausoleo");
    lugares2.push_back("Cabildo");
    lugares2.push_back("Palacio Salvo");
    // def de los tours
    TourGuiado tourguiado1 = TourGuiado("TGO4657", "Plazas de Montevideo", 10, DTFecha(29, 8, 2024), "Paseos SA",lugares1);

    TourGuiado tourguiado2 = TourGuiado("TGR3257", "Puntos emblematicos", 5, DTFecha(29, 8, 2024), "Recorre",lugares1);

//C-) Crear los siguientes objetos de la clase EventoCultural (con el constructor por parámetros):

    EventoCultural eventoCultural1 = EventoCultural("ECP1346", "Danza en el Solis", 10, DTFecha(29, 10, 2025), "Teatro Solis", true);


// D-) Imprimir en consola utilizando la inserción de flujo el resultado de ejecutar la operación getDT() para cada uno de los objetos Experiencia creados.


    std::cout << alojamiento1.getDT() ;
    std::cout << alojamiento2.getDT() ;
    std::cout << tourguiado1.getDT() ;
    std::cout << tourguiado2.getDT() ;
    std::cout << eventoCultural1.getDT() ;






//E-> Crear los siguientes objetos de la clase Turista (con el constructor por parámetros):

    Turista turista1 = Turista("49512789", "Vanesa Castro", "vcastro.uy@servidor.net");

    Turista turista2 = Turista("15354420", "Karen Santos", "karen.s89@internet.uy");

//F-) Imprimir en consola el resultado de ejecutar la operación toString para cada uno de los objetos Turista creados.

std::cout << turista1.toString() << "\n";
std::cout << turista2.toString() << "\n";


//G-) Registrar las siguientes relaciones entre turistas y experiencias (creando links de la relación en ambas direcciones).

//H-) Invocar la operación listarExperiencias(10/12/2023, 0, 1000) para la turista 4.951.278-9 (Vanesa Castro) e imprimir el resultado en consola (un string por línea).

//I-) Ejecutar la eliminación del objeto TGR3257(Puntos emblematicos) de la clase Experiencia.

//J-) Invocar la operación listarExperiencias(10/10/2020, 0, 1000) para la turista 1.535.442-0 (Karen Santos) e imprimir el resultado en consola (un string por línea).
std::cout << "Caso J \n\n";
turista2.listarExperiencias(DTFecha(10, 10, 2020), 0, 1000);
//K-) Imprimir en consola utilizando la inserción de flujo el resultado de ejecutar la operación getDT() para cada uno de los objetos Experiencias creados (mismo código que la parte d).
std::cout << "Caso K \n\n";

std::cout << alojamiento1.getDT() ;
std::cout << alojamiento2.getDT() ;
std::cout << tourguiado1.getDT() ;
std::cout << tourguiado2.getDT() ;
std::cout << eventoCultural1.getDT() ;


}
