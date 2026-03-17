#include "Experiencia.h"
class Alojamiento : public Experiencia{ // subclase de Experiencia
    
private:
    std::string hotel;
    enum TipoRegimen regimen;
    int cantNoches;

public:
    Alojamiento(std::string, std::string, int, DTFecha, std::string, enum TipoRegimen, int);  // constructor
    ~Alojamiento(); // destructor
    std::string getHotel();
    TipoRegimen getRegimen();
    int getCantNoches();
    virtual float calcularCosto();
};