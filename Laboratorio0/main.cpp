#include <iostream>
#include <list>
#include <map>

class Turista{
    private:
        string ci;
        string nombre;
        string email;
    public:
        Turista(string, string, string);     //constructor
        ~Turista();                          //destructor
        string toString();
        string listarExperiencias(DTFecha, float, float);
}
Turista::Turista(string ci, string nombre, string email){
    this->ci = ci;
    this->nombre = nombre;
    this->email = email;
}
Turista::~Turista(){        //totalemente falso
}
Turista::toString(){
    return this->ci + '->' + this->nombre + '/' + this->email;
}
Turista::listarExperiencias(DTFecha desde, float min, float max){
    return
}

