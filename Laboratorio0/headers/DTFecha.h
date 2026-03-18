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