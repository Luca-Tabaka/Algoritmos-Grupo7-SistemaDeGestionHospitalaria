#include "nodo.h"
template <typename T>
Nodo<T>::Nodo(const T& dato){
        this->dato = dato;
        this->siguiente = nullptr;
    };
template <typename T>
void Nodo<T>::cambiar_dato(T d)
{
    dato = d;
}
template <typename T>
void Nodo<T>::cambiar_siguiente(Nodo<T>* s)
{
    siguiente = s;
}
template <typename T>
T Nodo<T>::obtener_dato()
{
    return dato;
}
template <typename T>
Nodo<T>* Nodo<T>::obtener_siguiente()
{
    return siguiente;
}
