#include <iostream>
#include <list>
#include "DataTypes.h"
#include "Enumerados.h"

class Experiencia{
    private:
        std::string codigoReserva;   
        std::string descripcion; 
        int precioBase;
        DTFecha fecha;
    
    public:
        Experiencia();     //constructor
        ~Experiencia();    //destructor
        std::string getCodigoReserva();
        std::string getDescripcion();
        int getPrecioBase();
        DTFecha getFecha();
        DTExp getDT();      // getDataType
        float calcularCosto();
};

class Alojamiento : public Experiencia{   // subclase de Experiencia
  private:
    std::string hotel;
    enum TipoRegimen regimen;
    int cantNoches;

  public:
    Alojamiento();     //constructor
    ~Alojamiento();    //destructor
    std::string getHotel();
    TipoRegimen getRegimen();
    int getCantNoches();
    float calcularCosto();
};

class TourGuiado : public Experiencia{   // subclase de Experiencia
  private:
    std::string agencia;
    int duracion;   // en horas

  public:
    TourGuiado();     //constructorrr
    ~TourGuiado();    //destructor
    std::string getLugar();
    int getDuracion();
    float calcularCosto();
};
