#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <typename T>


class Nodo{
    private:
        T dato; // dato que guardo
        Nodo<T>* siguiente; // puntero al nodo siguiente

    public:
        // creo un nodo con el dato de tipo T y el puntero en 0
        Nodo(const T& dato); 

        // cambio el dato del nodo a un nuevo dato
        void cambiarDato(const T& dato);

        // cambio el puntero que se encuentra en siguiente a uno nuevo
        void cambiarSiguiente(Nodo<T>* sig);

        // obtengo el dato del nodo
        T& obtenerDato();
        const T& obtenerDato() const;

        // obtengo el puntero al nodo que se encuentra en siguiente
        Nodo<T>* obtenerSiguiente();
        const Nodo<T>* obtenerSiguiente() const;

};
#include"nodo.tpp"
#endif // NODO_H_INCLUDED