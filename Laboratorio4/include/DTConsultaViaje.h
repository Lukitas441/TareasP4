#ifndef DT_CONSULTA_VIAJE_H
#define DT_CONSULTA_VIAJE_H

#include "DTFecha.h"
#include <string>

class DTConsultaViaje {
private:
  int codigo;
  std::string marca;
  std::string modelo;
  std::string nombreConductor;
  float calificacionProm;
  float precioTotal;

public:
  DTConsultaViaje(int codigo, std::string marca, std::string modelo, std::string nombreConductor, float calificacionProm, float precioTotal);

  int getCodigo();
  std::string getMarca();
  std::string getModelo();
  std::string getNombreConductor();
  float getCalificacionProm();
  float getPrecioTotal();
};

#endif
