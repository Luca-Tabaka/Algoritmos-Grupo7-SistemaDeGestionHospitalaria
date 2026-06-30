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
    if(nodo == nullptr){//Si llega a su posicion, inserta
        return new NodoArbol(diag,frec);
    }
    else if(frec < nodo->getFrecuencia()){//si la frecuencia es mas chica, inserta a la izquierda
        nodo-> cambiarIzq(insertar(nodo->getIzq(),diag,frec));
    }
    else if(frec > nodo->getFrecuencia()){//si es mas grande, inserta a la derecha
         nodo-> cambiarDer(insertar(nodo->getDer(),diag,frec));
    }
    else if(diag < nodo->getDiagnostico()){// si las frecuencias son iguales, desempata el diagnostico por orden alfabético
        nodo-> cambiarIzq(insertar(nodo->getIzq(),diag,frec));
    }
    else{
         nodo-> cambiarDer(insertar(nodo->getDer(),diag,frec));
    }
    return nodo;
}

void Arbol::aumentarFrecuencia(string diag){
    NodoArbol* nodoBuscado = buscarDiagnostico(raiz,diag);
    if(nodoBuscado == nullptr){
        cout<<"El diagnostico que ingresó no existe, no se puede incrementar frecuencia";
        return;
    }
    else{
        int frec = nodoBuscado->getFrecuencia();//si lo encuentra, guarda la frecuencia
        raiz = eliminar(raiz,frec,diag);//elimina el nodo
        raiz = insertar(raiz,diag,frec+1);//Lo vuelve a insertar con frecuencia + 1
    }
}

NodoArbol* Arbol::buscarDiagnostico(NodoArbol* nodo, string diag){
    if(nodo == nullptr){
        return nullptr;// si llega a una hoja, vuelve
    }
    if(nodo->getDiagnostico() == diag){// si lo encuentra, devuelve el nodo y corta la recurcion
        return nodo;
    }
    NodoArbol* encontrado = buscarDiagnostico(nodo->getIzq(), diag);//primero busca a izquierda

    if(encontrado != nullptr){//si lo encuentra, lo devuelve
        return encontrado;
    }
    return buscarDiagnostico(nodo->getDer(), diag);//si no, busca a derecha
}


bool Arbol::existeDiagnostico(string diag){
    NodoArbol* encontrado = buscarDiagnostico(raiz, diag);
    return encontrado != nullptr;
}
NodoArbol* Arbol::diagnosticoMasFrecuente(){
    NodoArbol* nodoActual = raiz;
    if(nodoActual == nullptr) return nullptr;
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
        return 1 + max(altura(nodo->getIzq()),altura(nodo->getDer()));
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

NodoArbol* Arbol::eliminar(NodoArbol* nodo, int frec, string diag){
    if(nodo == nullptr){
        return nullptr;
    }
    if(frec<nodo->getFrecuencia() || (frec==nodo->getFrecuencia() && diag < nodo->getDiagnostico())){
        nodo->cambiarIzq(eliminar(nodo->getIzq(),frec,diag));
    }
    else if(frec > nodo->getFrecuencia()|| (frec==nodo->getFrecuencia() && diag > nodo->getDiagnostico())){
        nodo->cambiarDer(eliminar(nodo->getDer(),frec,diag));
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
        nodo->cambiarDer(eliminar(nodo->getDer(),sucesor->getFrecuencia(),sucesor->getDiagnostico()));//elimina al sucesor

    }
    return nodo;
}

void Arbol::eliminarDiagnostico(string diag){
    NodoArbol* nodo = buscarDiagnostico(raiz, diag);

    if(nodo != nullptr){
        raiz = eliminar(raiz,nodo->getFrecuencia(),diag);
    }
    else{
        cout<<"No se encontro el diagnostico a eliminar" << endl;
    }
}

NodoArbol* Arbol::minimo(NodoArbol* nodo){
    while(nodo->getIzq() != nullptr){
        nodo = nodo->getIzq();
    }
    return nodo;
}