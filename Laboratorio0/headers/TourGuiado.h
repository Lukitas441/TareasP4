#include "Experiencia.h"
class TourGuiado : public Experiencia
{ // subclase de Experiencia
private:
    std::string agencia;
    std::list<std::string> lugaresVisitados;

public:
    TourGuiado(std::string, std::string, int, DTFecha, std::string, std::string, std::list<std::string>);  // constructor
    ~TourGuiado(); // destructor
    std::string getAgencia();
    std::list<std::string> getLugaresVisitados();
    virtual float calcularCosto();
    };  