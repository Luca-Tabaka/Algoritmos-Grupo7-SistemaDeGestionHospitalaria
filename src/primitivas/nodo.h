#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

template <typename T>
class Nodo
{
private:
    // atributos
    T dato;
    Nodo<T>* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato de tipo T y valor = d y siguiente = nullptr
    Nodo(const T& dato);

    void cambiar_dato(T dato);

    void cambiar_siguiente(Nodo<T>* s);

    T obtener_dato();

    Nodo<T>* obtener_siguiente();
};
#include"nodo.tpp"
#endif // NODO_H_INCLUDED
