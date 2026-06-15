#ifndef DERIVACION_H_
#define DERIVACION_H_
#include<string>

class Derivacion{
    private:
        std:: string hospitalOrigen;
        std:: string hospitalDestino;
        int tiempoMinutos;
        
    public:
        std:: string getOrigen();
        std:: string getDestino();
        int getTiempo();
};

#endif