#ifndef GRAFO_H_
#define GRAFO_H_
#include "nodoGrafo.h"

class Grafo{
    private:
        Lista<NodoGrafo> vertices;
        void desmarcarVisitados();
        NodoGrafo* buscarVertice(string id);

    public:
        // metodo constructor
        Grafo();
        // metodo para agregar vertice
        void agregarVertice(string id);
        // metodo para agregar arista a un vertice
        void agregarArista(string origen, string destino, int peso);
        // metodo para ver las adyacencias que tiene un vertice
        void verAdyacentes(string id);
        void eliminarVertice(string id);
        void verGrafo();
        void dijkstra(string origen, Lista<string>& caminos, Lista<int>& distancias);
        void calcularCamino(string origen, string destino);
        Lista<string> hospitalesMasCercanos(string origen);
        void cargarDerivacionesATXT();
};



#endif /* GRAFO_H_ */