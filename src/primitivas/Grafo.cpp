#include "grafo.h"
Grafo::Grafo(){}

void Grafo::agregarVertice(string id){
    NodoGrafo agregado(id);
    vertices.alta(agregado);
}

void Grafo::agregarArista(string origen, string destino, int peso){
    //creo las aristas
    Arista aristaOrigen(destino, peso);
    Arista aristaDestino(origen, peso);

    // encuentro el vertice al cual se le agrega
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        NodoGrafo& vertice = vertices.consulta(i);
        if(vertice.getId() == origen){
            vertice.agregarAdyacente(aristaOrigen);
        }
        if(vertice.getId() == destino){
            vertice.agregarAdyacente(aristaDestino);
        }
    }
}

void Grafo::eliminarVertice(string eliminar){
    NodoGrafo* vertice = buscarVertice(eliminar);
    if (vertice==nullptr)
    {
        cout<<"No se encontro el vertice a eliminar";
        return;
    }
        for(int i=1; i<=vertices.obtenerLargo(); i++){
            NodoGrafo* vertice = &vertices.consulta(i);
            if(vertice->getId() == eliminar){
                vertices.baja(i);
            }
    }
}

void Grafo::verAdyacentes(string id){
    // recorro la lista de vertices
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        if(vertices.consulta(i).getId() == id){
            // obtengo los adyacentes
            Lista<Arista>& adyacentes = vertices.consulta(i).getAdyacentes();
            // los voy imprimiendo
            for(int a=1; a<=adyacentes.obtenerLargo(); a++){
                adyacentes.consulta(a).mostrar();
            }
        }
    }
}

void Grafo::verGrafo(){
    // recorro la lista de vertices
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        // consigo el vertice a imprimir
        NodoGrafo& vertice = vertices.consulta(i);
        cout << "Hospital: " << vertice.getId()<<" -> ";
        // obtengo e imprimo las adyacencias
        Lista<Arista>& adyacentes = vertice.getAdyacentes();
        for(int a=1; a<=adyacentes.obtenerLargo(); a++){
            adyacentes.consulta(a).mostrar();
        }
        cout << endl;
    }
}

void Grafo::desmarcarVisitados(){
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        vertices.consulta(i).setVisitado(false);
    }
}

NodoGrafo* Grafo::buscarVertice(string id){
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        NodoGrafo* vertice = &vertices.consulta(i);
        if(vertice->getId() == id){
            return vertice;
        }
    }
    return nullptr;
}


void Grafo::dijkstra(string origen,string destino){
    desmarcarVisitados();
    int largo = vertices.obtenerLargo();
    int distancias[largo + 1];
    string caminos[largo + 1];

    const int inf=99999;

    for(int i=1; i<=largo; i++){
        distancias[i] = inf;
        caminos[i] = "";
    }
    
    NodoGrafo* verticeOrigen = buscarVertice(origen);
    Lista<Arista>& adyacentes = verticeOrigen->getAdyacentes();
    // inicializo las distancias y caminos de los adyacentes al origen
    for(int i=1; i<=adyacentes.obtenerLargo(); i++){
        Arista& arista = adyacentes.consulta(i);
        string verticeDestino = arista.getDestino();
        int peso = arista.getPeso();
        // busco el vertice destino en la lista de vertices
        for(int a=1; a<=largo; a++){
            NodoGrafo& vertice = vertices.consulta(a);
            if(vertice.getId() == verticeDestino){
                distancias[a] = peso;
                caminos[a] = origen;
            }
        }
    }
    verticeOrigen->setVisitado(true);
    // mientras haya vertices no visitados
    while (true){
        int minDistancia = inf;
        int verticeMinimo = -1;
        // busco el no visitado con menor distancia
        for(int i=1; i<=largo; i++){
            NodoGrafo& vertice = vertices.consulta(i);
            if(!vertice.getVisitado() && distancias[i] < minDistancia){
                minDistancia = distancias[i];
                verticeMinimo = i;
            }
        }
        if(verticeMinimo == -1){
            break;
        }
        // marco el vertice que encontre como visitado
        vertices.consulta(verticeMinimo).setVisitado(true);
        // obtengo los adyacentes del vertice minimo
        Lista<Arista>& adj = vertices.consulta(verticeMinimo).getAdyacentes();
        // hago recorrido por los adyacentes y actualizo distancias y caminos
        for(int i=1; i<=adj.obtenerLargo(); i++){
            Arista& arista = adj.consulta(i);
            string verticeDestino = arista.getDestino();
            int peso = arista.getPeso();
            // busco la posicion del vecino en la lista de vertices
            for(int a=1; a<=largo; a++){
                NodoGrafo& vertice = vertices.consulta(a);
                if(vertice.getId() == verticeDestino){
                    if(distancias[verticeMinimo] + peso < distancias[a]){
                        distancias[a] = distancias[verticeMinimo] + peso;
                        caminos[a] = vertices.consulta(verticeMinimo).getId();
                    }
                }
            }
        }
    }
    int posDestino = -1;
    // busco la posicion del destino en la lista de vertices
    for(int i=1; i<=largo; i++){
        if(vertices.consulta(i).getId() == destino){
            posDestino = i;
            break;
        }
    }
    
    cout << "tiempo minimo: " << distancias[posDestino] << endl;

    // construyo el camino desde origen a destino
    string camino = destino;
    string actual = destino;
    while(actual != origen){
        for(int i=1; i<=largo; i++){
            if(vertices.consulta(i).getId() == actual){
                actual = caminos[i];
                camino = actual + " -> " + camino;
                break;
            }
        }
    }
    cout << "camino: " << camino << endl;
}