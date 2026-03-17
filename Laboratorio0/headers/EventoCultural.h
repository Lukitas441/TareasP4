#include "Experiencia.h"
#include <string>

class EventoCultural : public Experiencia{ // subclase de Experiencia

private:
    std::string ubicacion;
    bool usoCupon;

public:
    EventoCultural(std::string, std::string, int, DTFecha, std::string, std::string, bool);  // constructor
    ~EventoCultural(); // destructor
    std::string getUbicacion();
    bool getUsoCupon();
    virtual float calcularCosto();  
};
