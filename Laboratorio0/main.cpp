#include <iostream>
#include <set>
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

    Alojamiento *alojamiento1 = new Alojamiento("ALX5489", "Hotel moderno", 30, DTFecha(18, 05, 2020), "Hotel Lindorf", allInclusive, 5);

    Alojamiento *alojamiento2 = new Alojamiento("ALJ4789", "Todas las habitaciones con vista al mar", 100, DTFecha(10, 02, 2025), "Hotel SeaView", mediaPension, 15);
        

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
    TourGuiado* tourguiado1 = new TourGuiado("TGO4657", "Plazas de Montevideo", 10, DTFecha(29, 8, 2024), "Paseos SA",lugares1);

    TourGuiado* tourguiado2 = new TourGuiado("TGR3257", "Puntos emblematicos", 5, DTFecha(29, 8, 2024), "Recorre",lugares1);

//C-) Crear los siguientes objetos de la clase EventoCultural (con el constructor por parámetros):

    EventoCultural* eventoCultural1 = new EventoCultural("ECP1346", "Danza en el Solis", 10, DTFecha(29, 10, 2025), "Teatro Solis", true);


// D-) Imprimir en consola utilizando la inserción de flujo el resultado de ejecutar la operación getDT() para cada uno de los objetos Experiencia creados.

std::cout << "\nCaso D \n";


if (alojamiento1) {
    std::cout << alojamiento1->getDT() ;
};
if (alojamiento2) {
    std::cout << alojamiento2->getDT() ;
};
if (tourguiado1) {
    std::cout << tourguiado1->getDT() ;
};
if (tourguiado2) {
    std::cout << tourguiado2->getDT() ;
};
if (eventoCultural1) {
    std::cout << eventoCultural1->getDT() ;
};



//E-> Crear los siguientes objetos de la clase Turista (con el constructor por parámetros):

    Turista *turista1 = new Turista("49512789", "Vanesa Castro", "vcastro.uy@servidor.net");

    Turista *turista2 = new Turista("15354420", "Karen Santos", "karen.s89@internet.uy");

//F-) Imprimir en consola el resultado de ejecutar la operación toString para cada uno de los objetos Turista creados.
std::cout << "\nCaso F \n";

std::cout << turista1->toString() << std::endl;
std::cout << turista2->toString() << std::endl;

 
//G-) Registrar las siguientes relaciones entre turistas y experiencias (creando links de la relación en ambas direcciones).

    turista1->setExperiencias(alojamiento1);
    alojamiento1->agregarTurista(turista1);

    turista1->setExperiencias(alojamiento2);
    alojamiento2->agregarTurista(turista1);

    turista1->setExperiencias(tourguiado2);
    tourguiado2->agregarTurista(turista1);

    turista1->setExperiencias(eventoCultural1);
    eventoCultural1->agregarTurista(turista1);

    turista2->setExperiencias(tourguiado1);
    tourguiado1->agregarTurista(turista2);
    
    turista2->setExperiencias(tourguiado2);
    tourguiado2->agregarTurista(turista2);
    

//H-) Invocar la operación listarExperiencias(10/12/2023, 0, 1000) para la turista 4.951.278-9 (Vanesa Castro) e imprimir el resultado en consola (un string por línea).

std::cout << "\nCaso H\n";

std::set<Experiencia*> experienciasFiltradas = turista1->listarExperiencias(DTFecha(10, 12, 2023), 0, 1000);
std::set<Experiencia*>::iterator it = experienciasFiltradas.begin();
while (it != experienciasFiltradas.end()) {
    std::cout << (*it)->getCodigoReserva() << std::endl; 
    it++;
}


//I-) Ejecutar la eliminación del objeto TGR3257(Puntos emblematicos) de la clase Experiencia.

delete tourguiado2;
tourguiado2 = NULL; // Evitar acceso a memoria liberada

//J-) Invocar la operación listarExperiencias(10/10/2020, 0, 1000) para la turista 1.535.442-0 (Karen Santos) e imprimir el resultado en consola (un string por línea).
std::cout << "\nCaso J \n";
std::set<Experiencia*> experienciasFiltradas2 = turista2->listarExperiencias(DTFecha(10, 10, 2020), 0, 1000);
std::set<Experiencia*>::iterator it2 = experienciasFiltradas2.begin();
while (it2 != experienciasFiltradas2.end()) {
    std::cout << (*it2)->getCodigoReserva() << std::endl;
    it2++;
}

//K-) Imprimir en consola utilizando la inserción de flujo el resultado de ejecutar la operación getDT() para cada uno de los objetos Experiencias creados (mismo código que la parte d).

//delete turista1; si se intenta eliminar el unico turista de una experiencia, se lanza una excepcion

std::cout << "\nCaso K \n";
if (alojamiento1) {
    std::cout << alojamiento1->getDT() ;
} else {
    std::cout << "Alojamiento 1 ha sido eliminado." << std::endl;
}

if (alojamiento2) {
    std::cout << alojamiento2->getDT() ;
} else {
    std::cout << "Alojamiento 2 ha sido eliminado." << std::endl;
}

if (tourguiado1) {
    std::cout << tourguiado1->getDT() ;
} else {
    std::cout << "Tour guiado 1 ha sido eliminado." << std::endl;
}

if (tourguiado2) {
    std::cout << tourguiado2->getDT() ;
} else {
    std::cout << "Tour guiado 2 ha sido eliminado." << std::endl;
}

if (eventoCultural1) {
    std::cout << eventoCultural1->getDT() ;
} else {
    std::cout << "Evento cultural 1 ha sido eliminado." << std::endl;
}

}
