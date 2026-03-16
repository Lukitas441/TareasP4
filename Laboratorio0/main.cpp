#include <iostream>
#include <list>
#include <map>
#include "Classes.h"
#include "DataTypes.h"


// Coment de valen

// Datatypes



// Clases




Turista::~Turista(){        //totalemente falso
};

std::string Turista::toString(){
    return this->ci + "->" + this->nombre + "/" + this->email;
};

std::list<std::string> Turista::listarExperiencias(DTFecha desde, float min, float max){
    return 0
};

