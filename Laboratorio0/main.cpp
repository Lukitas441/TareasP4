#include <iostream>
#include <list>
#include <map>

// Datatypes



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
        std::string listarExperiencias(DTFecha, float, float);
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

std::string Turista::listarExperiencias(DTFecha desde, float min, float max){
    return 0
};

