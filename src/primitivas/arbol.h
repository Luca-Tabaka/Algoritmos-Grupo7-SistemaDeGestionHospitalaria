#ifndef ARBOL_H_
#define ARBOL_H_
#include "nodoArbol.h"
class Arbol{
    private:
        NodoArbol* raiz;
        NodoArbol* buscarDiagnostico(NodoArbol* nodo, string diag);
        void mostrarDiagnosticos(NodoArbol* nodo);
        NodoArbol* insertar(NodoArbol* nodo, string diag, int frec);
        NodoArbol* minimo(NodoArbol* nodo);
        NodoArbol* eliminar(NodoArbol* nodo, int frec);
    public:
        Arbol(){
            raiz = nullptr;
        }
        NodoArbol* obtenerRaiz();
        void cambiarRaiz(NodoArbol* raiz);

        void insertar(string diag, int frec);

        void aumentarFrecuencia(string diag);
        NodoArbol* diagnosticoMasFrecuente();
        bool estaDesbalanceado();
        int altura(NodoArbol* nodo);
        void mostrarDiagnosticos();
        void eliminarDiagnostico(string diag);

};


#endif