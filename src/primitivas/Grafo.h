#ifndef GRAFO_H_
#define GRAFO_H_
#include "nodoGrafo.h"

class Grafo{
    private:
        Lista<NodoGrafo> vertices;
        NodoGrafo* buscarVertice(string id);
        void desmarcarVisitados();

    public:
        Grafo();
        void agregarVertice(string id);
        void agregarArista(string origen, string destino, int peso);
        void eliminarVertice(string id);
        void verGrafo();
        void dijkstra(NodoGrafo* verticeOrigen, Lista<string>& caminos, Lista<int>& distancias);
        void calcularCamino(string origen, string destino);
        Lista<string> hospitalesMasCercanos(string origen);
        void cargarDerivacionesATXT();
};



#endif /* GRAFO_H_ */