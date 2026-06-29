#ifndef ARISTA_H
#define ARISTA_H
#include <iostream>
using namespace std;
class Arista{
    private:
        string destino;
        int peso;

    public:
        Arista();
        Arista(string destino, int peso);
        string getDestino();
        int getPeso();
        void mostrar();
};


#endif // ARISTA_H