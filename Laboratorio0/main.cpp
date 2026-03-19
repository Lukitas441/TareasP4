#include <iostream>
#include <list>
#include <map>
#include "headers/Turista.h"
#include "headers/Alojamiento.h"
#include "headers/EventoCultural.h"
#include "headers/TourGuiado.h"
#include "headers/DTExp.h"
#include "headers/DTFecha.h"
#include "headers/Enumerados.h"



// Aca en el main por lo que entendi tenenemos que 
//Primero crear alojamiento:

int main()
{
    Alojamiento alojamiento1 = Alojamiento("reserva111", "Alojamiento en Hotel XYZ", 100, DTFecha(23, 12, 2023), "Hotel XYZ", allInclusive, 3);
    std::cout << alojamiento1.getDT() << std::endl;
    return 0;
}
