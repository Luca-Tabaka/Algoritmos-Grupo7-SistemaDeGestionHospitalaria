#include "nodoGrafo.h"
NodoGrafo::NodoGrafo(){}
NodoGrafo::NodoGrafo(string id){
    this->id = id;
    this->visitado = false;
}

string NodoGrafo::getId(){
    return id;
}

bool NodoGrafo::getVisitado(){
    return visitado;
}
void NodoGrafo::setVisitado(bool estado){
    visitado = estado;
}
Lista<Arista>& NodoGrafo::getAdyacentes(){
    return adyacentes;
}

void NodoGrafo::agregarAdyacente(Arista arista){
    // aca uso el metodo de alta ya creado en lista
    adyacentes.alta(arista);
}