#include "lista.h"

template<typename T>
Lista<T>::Lista(){
    primero = 0;
    largo = 0;
}

template<typename T>
bool Lista<T>::esVacia()
{
    return (largo == 0);
}

template<typename T>
void Lista<T>::alta(const T& dato, int pos){ // uso la referencia para no hacer copia del dato, y la posicion es un entero
    Nodo<T>* nuevoElemento = new Nodo<T>(dato); // creo nodo con el dato pasado por parametro
    
    if(pos == 1){
        nuevoElemento->cambiarSiguiente(primero); // si la posicion por parametro es 1 le cambio su puntero al primero
        primero = nuevoElemento;
    }else{
        Nodo<T>* anterior = obtenerNodo(pos - 1); // obtengo el nodo anterior a la posicion a insertar
        Nodo<T>* siguiente = anterior->obtenerSiguiente(); // obtengo el nodo siguiente a la posicion a insertar
        nuevoElemento->cambiarSiguiente(siguiente);
        anterior->cambiarSiguiente(nuevoElemento);
    }
    largo++;
}

template<typename T>
void Lista<T>::alta(const T& dato){
    alta(dato, largo + 1);
}

template<typename T>
Nodo<T>* Lista<T>::obtenerNodo(int pos){
    Nodo<T>* auxiliar = primero;
    for(int i = 1; i < pos; i++){
        auxiliar = auxiliar->obtenerSiguiente();
    }
    return auxiliar;
}

template<typename T>
T& Lista<T>::consulta(int pos)
{
    Nodo<T>* aux = obtenerNodo(pos);
    return aux->obtenerDato();
}


template<typename T>
void Lista<T>::baja(int pos)
{
    Nodo<T>* borrar;
    if (pos == 1)
    {
        borrar = primero;
        primero = borrar->obtenerSiguiente(); //el primero pasa a ser el siguiente al nodo a borrar
    }
    else
    {
        Nodo<T>* anterior = obtenerNodo(pos - 1);
        borrar = anterior->obtenerSiguiente();
        Nodo<T>* siguiente = borrar->obtenerSiguiente();
        anterior->cambiarSiguiente(siguiente);
    }
    delete borrar;
    largo--;
}

template<typename T>
Lista<T>::~Lista(){
    while(!esVacia()){
        baja(1);
    }
}

template<typename T>
int Lista<T>::obtenerLargo()
{
    return largo;
}

template<typename T>
void Lista<T>::mostrarLista()
{
      cout<<"[";

      if(!esVacia())
      {
          for (int i = 1; i < largo; i++)
            cout<<this->consulta(i)<<",";
        cout<<this->consulta(largo);
      }

      cout<<"]"<<endl;
}


