#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <iostream>
#include <list>
#include <string>
#include "headers/DTFecha.h"
#include "headers/Enumerados.h"
#include "headers/DTExp.h"

class Experiencia{
  private:
  std::string codigoReserva;
  std::string descripcion;
  int precioBase;
  DTFecha fecha;
  std::list<std::string> turistas; // lista de turistas que se alojan en el alojamiento

  public:
  // Constructores y destructores
  Experiencia();
  ~Experiencia();
  Experiencia(std::string, std::string, int, DTFecha);

  // Getters
  std::string getCodigoReserva();
  std::string getDescripcion();
  int getPrecioBase();
  DTFecha getFecha();
  DTExp getDT();

  // Setters
  void setCodigoReserva(std::string);
  void setDescripcion(std::string);
  void setPrecioBase(int);
  void setFecha(DTFecha);
  void setDT(DTExp);

  // Funciones
  virtual float calcularCosto() = 0; // Virtual para que no se rompa la funcion

  void agregarTurista(std::string); // Agrega un turista a la experiencia
};

#endif // EXPERIENCIA_H





