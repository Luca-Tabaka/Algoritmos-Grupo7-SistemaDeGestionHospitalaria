#include "lista.h"
template<typename T>
Lista<T>::Lista()
{
    primero = 0;
    largo = 0;
}
template<typename T>
bool Lista<T>::vacia()
{
    return (largo == 0);
}
template<typename T>
void Lista<T>::alta(T d, int pos)
{
    Nodo<T>* nuevo = new Nodo<T>(d); // crea el nuevo nodo en el cual dentro se guarda el dato d 
    if (pos == 1)
    {
        nuevo->cambiar_siguiente(primero); // el siguiente del nuevo nodo es el primero actual
        primero = nuevo; // el nuevo nodo pasa a ser el primero esto no significa que el nodo anterior se borra, sino que ahora el nuevo nodo es el primero y el nodo anterior es el segundo
    }
    else
    {
        Nodo<T>* anterior = obtener_nodo(pos - 1); // obtenemos el nodo anterior a la posición donde queremos insertar el nuevo nodo
        Nodo<T>* siguiente = anterior->obtener_siguiente(); // obtenemos el nodo siguiente al nodo anterior, es decir el nodo que actualmente esta en la posición donde queremos insertar el nuevo nodo
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}
template<typename T>
Nodo<T>* Lista<T>::obtener_nodo(int pos)
{
    Nodo<T>* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}
template<typename T>
T Lista<T>::consulta(int pos)
{
    Nodo<T>* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}
template<typename T>
void Lista<T>::baja(int pos)
{
    Nodo<T>* borrar;
    if (pos == 1)
    {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else
    {
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo<T>* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    largo--;
}
template<typename T>
Lista<T>::~Lista()
{
    while (! vacia())
        baja(1);
}
template<typename T>
int Lista<T>::obtener_largo()
{
    return largo;
}
template<typename T>
void Lista<T>::mostrar()
{
      cout<<"[";

      if(!vacia())
      {
          for (int i = 1; i < largo; i++)
            cout<<this->consulta(i)<<",";
        cout<<this->consulta(largo);
      }

      cout<<"]"<<endl;
}

