#include"nodoArbol.h"
using namespace std;
NodoArbol::NodoArbol(string diag, int frec){
    diagnostico = diag;
    frecuencia = frec;
    izq = nullptr;
    der = nullptr;
}

NodoArbol::~NodoArbol(){
    if (izq!= nullptr)
    {
        delete izq;
    }
    if (der!= nullptr)
    {
        delete der;
    }    
}

string NodoArbol::getDiagnostico(){
    return diagnostico;
}
int NodoArbol::getFrecuencia(){
    return frecuencia;
}

NodoArbol* NodoArbol::getIzq(){
    return izq;
}
NodoArbol* NodoArbol::getDer(){
    return der;
}

void NodoArbol::cambiarFrecuencia(int nuevaFrec){
    frecuencia = nuevaFrec;
}
void NodoArbol::cambiarDiagnostico(string nuevoDiag){
    diagnostico = nuevoDiag;
}

void NodoArbol::cambiarIzq(NodoArbol* nuevoIzq){
    izq = nuevoIzq;
}
void NodoArbol::cambiarDer(NodoArbol* nuevoDer){
    der = nuevoDer;
}
