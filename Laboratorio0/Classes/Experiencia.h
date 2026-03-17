#include <iostream>
#include <list>
#include "DataTypes/DataTypes.h"
#include "DataTypes/Enumerados.h"

class Experiencia
{
private:
  std::string codigoReserva;
  std::string descripcion;
  int precioBase;
  DTFecha fecha;
  std::list<std::string> turistas; // lista de turistas que se alojan en el alojamiento

public:
  Experiencia(std::string, std::string, int, DTFecha); // constructor
  ~Experiencia();                                      // destructor
  std::string getCodigoReserva();
  std::string getDescripcion();
  int getPrecioBase();
  DTFecha getFecha();

  void agregarTurista(std::string); // Agrega un turista a la experiencia

  DTExp getDT();                 // getDataType link con turista
  virtual float calcularCosto() = 0; // Virtual por polimorfismo
};



class Alojamiento : public Experiencia
{ // subclase de Experiencia
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

class EventoCultural : public Experiencia
{ // subclase de Experiencia
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
