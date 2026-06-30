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
    adyacentes.alta(arista);
}

int NodoGrafo::buscarAdyacente(string id){
    for(int i = 1; i <= adyacentes.obtenerLargo(); i++){
        if(adyacentes.consulta(i).getDestino() == id){
            return i;
        }
    }
    return -1; 
}

void NodoGrafo::eliminarAdyacente(string idDestino){
    int pos = buscarAdyacente(idDestino);
    if(pos == -1){
        cout << "No se encontro el adyacente: " <<endl;
        return;
    }
    adyacentes.baja(pos);
} 

void NodoGrafo::vaciarAdyacentes(){
    adyacentes.vaciar();
}
