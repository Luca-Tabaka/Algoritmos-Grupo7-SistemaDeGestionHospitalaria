#ifndef NODOARBOL_H_
#define NODOARBOL_H_

#include<string>

using namespace std;

class NodoArbol{
    private:
        string diagnostico;
        int frecuencia;
        NodoArbol* izq;
        NodoArbol* der;

    public:

        NodoArbol(string diag, int frec);
        string getDiagnostico();
        int getFrecuencia();

        NodoArbol* getIzq();
        NodoArbol* getDer();

        void cambiarFrecuencia(int nuevaFrec);
        void cambiarDiagnostico(string nuevoDiag);
        void cambiarIzq(NodoArbol* nuevoIzq);
        void cambiarDer(NodoArbol* nuevoDer);

        
};

#endif