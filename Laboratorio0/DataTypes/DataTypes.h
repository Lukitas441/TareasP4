#include <list>
#include <iostream>

class DTFecha{    
    private:
        int Dia;
        int Mes;
        int Año;
    
    public:
        int getdia();
        int getmes();
        int getaño();
};

class DTExp{
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