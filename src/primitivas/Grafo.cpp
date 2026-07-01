#include "grafo.h"
#include <iostream>
#include <fstream>
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
    Lista<Arista> adyacentes = vertice->getAdyacentes();
    for(int i=1;i<=adyacentes.obtenerLargo();i++){
        NodoGrafo* vecino = buscarVertice(adyacentes.consulta(i).getDestino());
        vecino->eliminarAdyacente(eliminar);
    }
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        NodoGrafo* vertice = &vertices.consulta(i);
        if(vertice->getId() == eliminar){
            vertices.baja(i);
        }
    }
    vertice->vaciarAdyacentes();
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


void Grafo::dijkstra(string origen, Lista<string>& caminos, Lista<int>& distancias){
    desmarcarVisitados();
    int largo = vertices.obtenerLargo();
    int d[largo + 1];
    string c[largo + 1];

    const int inf=99999;

    for(int i=1; i<=largo; i++){
        d[i] = inf;
        c[i] = "";
    }
    NodoGrafo* verticeOrigen = buscarVertice(origen);
    if(verticeOrigen == nullptr){
        cout<< "No existe el vertice origen"<<endl;
        return;
    }

    Lista<Arista>& adyacentes = verticeOrigen->getAdyacentes();
    // inicializo las d y c de los adyacentes al origen
    for(int i=1; i<=adyacentes.obtenerLargo(); i++){
        Arista& arista = adyacentes.consulta(i);
        string verticeDestino = arista.getDestino();
        int peso = arista.getPeso();
        // busco el vertice destino en la lista de vertices
        for(int a=1; a<=largo; a++){
            NodoGrafo& vertice = vertices.consulta(a);
            if(vertice.getId() == verticeDestino){
                d[a] = peso;
                c[a] = origen;
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
            if(!vertice.getVisitado() && d[i] < minDistancia){
                minDistancia = d[i];
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
        // hago recorrido por los adyacentes y actualizo d y c
        for(int i=1; i<=adj.obtenerLargo(); i++){
            Arista& arista = adj.consulta(i);
            string verticeDestino = arista.getDestino();
            int peso = arista.getPeso();
            // busco la posicion del vecino en la lista de vertices
            for(int a=1; a<=largo; a++){
                NodoGrafo& vertice = vertices.consulta(a);
                if(vertice.getId() == verticeDestino){
                    if(d[verticeMinimo] + peso < d[a]){
                        d[a] = d[verticeMinimo] + peso;
                        c[a] = vertices.consulta(verticeMinimo).getId();
                    }
                }
            }
        }
    }
    // copiar en listas
    for (int i = 1; i <= largo; i++){
        caminos.alta(c[i]);
        distancias.alta(d[i]);
    }
    

}

void Grafo::calcularCamino(string origen, string destino){
    Lista<string> caminos;
    Lista<int> distancias;
    dijkstra(origen, caminos, distancias);
    int largo =vertices.obtenerLargo();
    int posDestino = -1;

    for(int i=1; i<=largo; i++){
        if(vertices.consulta(i).getId() == destino){
            posDestino = i;
            break;
        }
    }
    if(posDestino == -1){
        cout<< "No existe el vertice destino"<<endl;
        return;
    }    
    string camino = destino;
    string actual = destino;
    while(actual != origen ){
        for(int i=1; i<=largo; i++){
            if(vertices.consulta(i).getId() == actual){
                actual = caminos.consulta(i);
                camino = actual + " -> " + camino;
                break;
            }
        }
    }
    cout << "camino: " << camino << endl;
}


Lista<string>Grafo::hospitalesMasCercanos(string origen){
    Lista<string> caminos;
    Lista<int> distancias;
    dijkstra(origen, caminos, distancias);
    desmarcarVisitados();  
    int largo = vertices.obtenerLargo();
    Lista<string> hospitales;
    while (true){
        int minDistancia = 99999;
        int verticeMinimo = -1;
        // busco el no visitado con menor distancia
        for(int i=1; i<=largo; i++){
            NodoGrafo& vertice = vertices.consulta(i);
            if(!vertice.getVisitado() && distancias.consulta(i) < minDistancia && vertice.getId() != origen && distancias.consulta(i) != 99999){
                minDistancia = distancias.consulta(i);
                verticeMinimo = i;
            }
        }
        if(verticeMinimo == -1){
            break;
        }
        // marco el vertice que encontre como visitado
        NodoGrafo& vertice = vertices.consulta(verticeMinimo);
        hospitales.alta(vertice.getId());
        vertice.setVisitado(true);
    }    
    return hospitales;
}



void Grafo::cargarDerivacionesATXT(){
    ofstream archivo("archivosDeEntrada/derivaciones.txt"); 
    if (archivo.fail()) {
        cerr << "No se pudo abrir el archivo de derivaciones." << endl;
        return;
    }
    //recorro la lista de vertices
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        NodoGrafo& vertice = vertices.consulta(i);
        //consigo los adyacentes
        Lista<Arista>& adj = vertice.getAdyacentes();
        //los voy escribiendo en el archivo
        for (int i = 1; i <= adj.obtenerLargo(); i++)
        {
            Arista& arista = adj.consulta(i);

            if (vertice.getId()<arista.getDestino())
            {
                archivo<< vertice.getId()<<""<<arista.getDestino()<<" "<<arista.getPeso()<<endl;
            }  
        }
        
    }    
    archivo.close();
}
