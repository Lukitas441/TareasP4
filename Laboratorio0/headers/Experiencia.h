#ifndef EXPERIENCIA_H
#define EXPERIENCIA_H

#include <iostream>
#include <set>
#include <string>
#include "DTFecha.h"
#include "DTExp.h"
#include "Turista.h"


class Experiencia{
  private:
  std::string codigoReserva;
  std::string descripcion;
  int precioBase;
  DTFecha fecha;
  std::set<Turista*> turistas; // lista de turistas que se alojan en el alojamiento

  public:
  // Constructores y destructores
  Experiencia();
  virtual ~Experiencia();
  Experiencia(std::string, std::string, int, DTFecha);

  // Getters
  std::string getCodigoReserva();
  std::string getDescripcion();
  std::set<Turista*> getTuristas();
  int getPrecioBase();
  DTFecha getFecha();
  DTExp getDT();

  // Setters
  void setCodigoReserva(std::string);
  void setDescripcion(std::string);
  void setPrecioBase(int);
  void setFecha(DTFecha);
  //void setDT(DTExp);

  // Funciones
  virtual float calcularCosto() = 0; // Virtual para que no se rompa la funcion SI VA EL =0;

  void agregarTurista(Turista*); // Agrega un turista a la experiencia
  void eliminarTurista(Turista*); // Elimina un turista de la experiencia
};

#endif // EXPERIENCIA_H





