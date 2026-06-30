#include "nodo.h"

template <typename T>
Nodo<T>::Nodo(const T& d){ // con el & paso el dato por referencia y con el const no lo puedo modificar asi evito copiar un objeto grande
    dato = d;
    siguiente = 0;
}


template <typename T>
void Nodo<T>::cambiarDato(const T& d){
    dato = d;
}

template <typename T>
void Nodo<T>::cambiarSiguiente(Nodo<T> *sig){
    siguiente = sig;
}

template <typename T>
T& Nodo<T>::obtenerDato(){
    return dato;
}

template <typename T>
const T& Nodo<T>::obtenerDato() const{
    return dato;
}

template <typename T>
Nodo<T>* Nodo<T>::obtenerSiguiente(){
    return siguiente;
}

template <typename T>
const Nodo<T>* Nodo<T>::obtenerSiguiente() const{
    return siguiente;
}