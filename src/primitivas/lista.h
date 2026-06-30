#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
using namespace std;
#include "nodo.h"
template<typename T>

class Lista{
    private:
        Nodo<T>* primero; // puntero al primer nodo de la lista
        int largo;

        
    
    public:
        // el constructor de lista
        Lista();
        //constructor de copia
        Lista(const Lista<T>& lista);
        //operador asignacion
        Lista<T>& operator=(const Lista<T>& lista);
        // metodo para agregar un nodo a la lista, con la posicion donde guardar
        void alta(const T& dato, int pos); 

        // metodo para agregar un nodo en el final de la lista
        void alta(const T& dato);

        // metodo para borrar un elemento de la lista dada su posicion
        void baja(int pos);
        // metodo para obtener el dato de una posicion
        T& consulta(int pos); 
        const T& consulta(int pos) const;
        // metodo para averiguar si en la lista hay elemenos
        bool esVacia() const;

        // destructor de la lista
        ~Lista();

        // metodo para conseguir el largo de la lista
        int obtenerLargo() const;

        void mostrarLista();
        const Nodo<T>* obtenerNodo(int pos) const;
        Nodo<T>* obtenerNodo(int pos);

        void vaciar();

};
#include "lista.tpp"


#endif // LISTA_H_INCLUDED