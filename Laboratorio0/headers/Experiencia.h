#include <iostream>
#include <list>
#include "DTFecha.h"
#include "Enumerados.h"
#include "DTExp.h"

class Experiencia{
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





