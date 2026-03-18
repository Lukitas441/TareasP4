#ifndef DT_FECHA_H
#define DT_FECHA_H

class DTFecha{    
private:
    int dia;
    int mes;
    int anio;

public:
    // Constructores y destructores
    DTFecha();
    ~DTFecha();
    DTFecha(int, int, int);

    // Getters
    int getDia();
    int getMes();
    int getAnio();
};

#endif // DT_FECHA_H