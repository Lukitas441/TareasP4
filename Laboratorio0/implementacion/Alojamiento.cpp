#include "Alojamiento.h"

// Constructores y destructores
           //Alojamiento(std::string,               std::string,             int,            DTFecha,       std::string,       enum TipoRegimen,             int);
Alojamiento::Alojamiento(std::string codigoReserva, std::string descripcion, int precioBase, DTFecha fecha, std::string hotel, enum TipoRegimen tipoRegimen, int cantNoches) : Experiencia(codigoReserva, descripcion, precioBase, fecha){
    this->hotel = hotel;
    this->regimen = tipoRegimen;
    this->cantNoches = cantNoches;
};

Alojamiento::Alojamiento() {
};

Alojamiento::~Alojamiento() {
};

// Getters
std::string Alojamiento::getHotel(){
    return this->hotel;
};

TipoRegimen Alojamiento::getRegimen(){
    return this->regimen;
};

int Alojamiento::getCantNoches(){
    return this->cantNoches;
};

// Setters
void Alojamiento::setHotel(std::string hotel){
    this->hotel = hotel;
};

void Alojamiento::setRegimen(TipoRegimen regimen){
    this->regimen = regimen;
};

void Alojamiento::setCantNoches(int cantNoches){
    this->cantNoches = cantNoches;
};

 float Alojamiento::calcularCosto(){ // Implementa Guille
        float costo = this->getPrecioBase() * this->cantNoches;

    if (this->getRegimen() == allInclusive)
    {
        costo += 10 * this->cantNoches;
    }

    return costo;
};
