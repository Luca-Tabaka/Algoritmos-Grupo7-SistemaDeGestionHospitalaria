#include "arista.h"
using namespace std;


Arista::Arista(){}
Arista::Arista(string destino, int peso){
    this->destino = destino;
    this->peso = peso;
}


string Arista::getDestino(){
    return destino;
}

int Arista::getPeso(){
    return peso;
}

void Arista::mostrar(){
    cout << "Adyacente: " << destino << " tiempo: " << peso<<" ";
}
