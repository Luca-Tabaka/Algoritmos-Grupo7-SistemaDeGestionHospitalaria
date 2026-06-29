#ifndef GRAFO_H_
#define GRAFO_H_
#include "nodoGrafo.h"

class Grafo{
    private:
        Lista<NodoGrafo> vertices;
        void desmarcarVisitados();

    public:
        // metodo constructor
        Grafo();
        // metodo para agregar vertice
        void agregarVertice(string id);
        // metodo para agregar arista a un vertice
        void agregarArista(string origen, string destino, int peso);
        // metodo para ver las adyacencias que tiene un vertice
        void verAdyacentes(string id);
        NodoGrafo* buscarVertice(string id);
        void verGrafo();
        void dijkstra(string origen, string destino);

};



#endif /* GRAFO_H_ */