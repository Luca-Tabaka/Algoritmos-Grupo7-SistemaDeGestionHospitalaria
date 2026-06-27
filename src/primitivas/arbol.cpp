#include "arbol.h"
#include<cmath>
#include<iostream>
#include<algorithm>
NodoArbol* Arbol::obtenerRaiz(){
    return raiz;
}

void Arbol::cambiarRaiz(NodoArbol* nuevaRaiz){
    raiz = nuevaRaiz;
}

NodoArbol* Arbol::insertar(NodoArbol* nodo, string diag, int frec){
    if(nodo == nullptr){
        return new NodoArbol(diag,frec);
    }
    if(frec < nodo->getFrecuencia()){
        nodo-> cambiarIzq(insertar(nodo->getIzq(),diag,frec));
    }
    else{
         nodo-> cambiarDer(insertar(nodo->getDer(),diag,frec));
    }
}

void Arbol::aumentarFrecuencia(string diag){
    NodoArbol* nodoBuscado = buscarDiagnostico(raiz,diag);
    if(nodoBuscado == nullptr){
        cout<<"No se pudo encontrar el nodo";
    }
    else{
        nodoBuscado->cambiarFrecuencia(nodoBuscado->getFrecuencia() + 1);
    }
}

NodoArbol* Arbol::buscarDiagnostico(NodoArbol* nodo, string diag){
    if(nodo == nullptr){
        return nullptr;
    }
    if(nodo->getDiagnostico() == diag){
        return nodo;
    }
    NodoArbol* encontrado = buscarDiagnostico(nodo->getIzq(), diag);

    if(encontrado != nullptr){
        return encontrado;
    }
    return buscarDiagnostico(nodo->getDer(), diag);
}

NodoArbol* Arbol::diagnosticoMasFrecuente(){
    NodoArbol* nodoActual = raiz;
    while(nodoActual->getDer() != nullptr){
        nodoActual = nodoActual->getDer();
    }
    return nodoActual;
}
bool Arbol::estaDesbalanceado(){
    if (raiz == nullptr) return false;
    return abs(altura(raiz->getIzq()) - altura(raiz->getDer())) > 2;
}
int Arbol::altura(NodoArbol* nodo){
    if(nodo == nullptr){
        return 0;
    }
    else{
        return 1 + altura(nodo->getIzq()) + altura(nodo->getDer());
    }
}
void Arbol::mostrarDiagnosticos(NodoArbol* nodo){
    if(nodo == nullptr) return;
    mostrarDiagnosticos(nodo->getIzq());
    cout<<"Diagnostico: " << nodo->getDiagnostico() << " Frecuencia: " << nodo->getFrecuencia() << endl;
    mostrarDiagnosticos(nodo->getDer());

}
void Arbol::mostrarDiagnosticos(){
    mostrarDiagnosticos(raiz);
}

void Arbol::insertar(string diag, int frec){
    raiz = insertar(raiz,diag,frec);
}

NodoArbol* Arbol::eliminar(NodoArbol* nodo, int frec){
    if(nodo == nullptr){
        return nullptr;
    }
    if(frec<nodo->getFrecuencia()){
        nodo->cambiarIzq(eliminar(nodo->getIzq(),frec));
    }
    else if(frec > nodo->getFrecuencia()){
        nodo->cambiarDer(eliminar(nodo->getIzq(),frec));
    }
    else{
        //hoja
        if(nodo-> getIzq() == nullptr && nodo -> getDer() == nullptr){
            delete nodo;
            return nullptr;
        }
        //tiene un solo hijo
        if(nodo->getIzq() == nullptr){
            NodoArbol* aux = nodo->getDer();
            delete nodo;
            return aux;
        }
        if(nodo->getDer() == nullptr){
            NodoArbol* aux = nodo->getIzq();
            delete nodo;
            return aux;
        }

        //tiene 2 hijos

        NodoArbol* sucesor = minimo(nodo->getDer());//buscamos un sucesor

        nodo->cambiarFrecuencia(sucesor->getFrecuencia());
        nodo->cambiarDiagnostico(sucesor->getDiagnostico());
        //reemplaza los datos del nodo a eliminar con los del sucesor
        nodo->cambiarDer(
            eliminar(nodo->getDer(),sucesor->getFrecuencia())//elimina al sucesor
        );

    }
    return nodo;
}

void Arbol::eliminarDiagnostico(string diag){
    NodoArbol* nodo = buscarDiagnostico(raiz, diag);

    if(nodo != nullptr){
        raiz = eliminar(raiz,nodo->getFrecuencia());
    }
    else{
        cout<<"Nodo no encontrado" << endl;
    }
}

NodoArbol* Arbol::minimo(NodoArbol* nodo){
    while(nodo->getIzq() != nullptr){
        nodo = nodo->getIzq();
    }
    return nodo;
}