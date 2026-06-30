#ifndef NODOGRAFO_H
#define NODOGRAFO_H
#include "arista.h"
#include "lista.h"

class NodoGrafo{
    private:
        string id;
        bool visitado;
        Lista<Arista> adyacentes;
        int buscarAdyacente(string idDestino);

    public:
        NodoGrafo();
        NodoGrafo(string id);
        // metodo para conseguir el id identifcador del nodo
        string getId();
        // metodo para conseguir por referencia los adyacentes al nodo
        Lista<Arista>& getAdyacentes();
        // metodo para agregar una arista al listado de adyacencias
        void agregarAdyacente(Arista arista);
        // metodo para conseguir el estado del nodo
        bool getVisitado();
        // metodo para cambiar el estado del nodo
        void setVisitado(bool estado);
        void eliminarAdyacente(string idDestino);
        void vaciarAdyacentes();
};


#endif // NODOGRAFO_H