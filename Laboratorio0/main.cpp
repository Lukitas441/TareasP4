#include <iostream>
#include <list>
#include <map>

// Datatypes
class DTFecha
{    
    private:
        int Dia;
        int Mes;
        int Año;
    
    public:
        int getdia();
        int getmes();
        int getaño();
};

int DTFecha::getdia(){
    return this->Dia;
};
int DTFecha::getmes(){
    return this->Mes;
};
int DTFecha::getaño(){
    return this->Año;
};

class DTExp
{
    private:
        std::string codigoReserva;   
        std::list<std::string> Turista;
        std::string descripcion; 
        DTFecha fecha;
    
    public:
        std::string getCodigoReserva();
        std::list<std::string> getTurista();
        std::string getDescripcion();
        DTFecha getFecha();
};
std::string DTExp::getCodigoReserva(){
    return this->codigoReserva;
};
std::list<std::string> DTExp::getTurista(){
    return this->Turista;
};
std::string DTExp::getDescripcion(){
    return this->descripcion;
};
DTFecha DTExp::getFecha(){
    return this->fecha;
};

// Clases

class Turista{
    
    private:
        std::string ci;
        std::string nombre;
        std::string email;
    public:
        Turista(std::string, std::string, std::string);     //constructor
        ~Turista();                          //destructor
        std::string toString();
        std::list<std::string> listarExperiencias(DTFecha, float, float);
};

Turista::Turista(std::string ci, std::string nombre, std::string email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
};

Turista::~Turista(){        //totalemente falso
};

std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::list<std::string> Turista::listarExperiencias(DTFecha desde, float min, float max){
    return 0
};

