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
    } //recupero la lista de adyacencias del vertice
    Lista<Arista> adyacentes = vertice->getAdyacentes();
    for(int i=1;i<=adyacentes.obtenerLargo();i++){
        // elimino la arista que conecta el vecino con vertice
        NodoGrafo* vecino = buscarVertice(adyacentes.consulta(i).getDestino());
        vecino->eliminarAdyacente(eliminar);
    } // entro a la lista de vertices del grafo y elimino buscado
    for(int i=1; i<=vertices.obtenerLargo(); i++){
        NodoGrafo* vertice = &vertices.consulta(i);
        if(vertice->getId() == eliminar){
            vertices.baja(i);
            break;
        }
    }
    delete vertice;
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


void Grafo::dijkstra(NodoGrafo* verticeOrigen, Lista<string>& caminos, Lista<int>& distancias){
    desmarcarVisitados();
    int largo = vertices.obtenerLargo();
    // creo dos arrays para representar distancias y caminos
    int d[largo + 1];
    string c[largo + 1];  

    const int inf=99999;
    // este for es para inicializar los arrays creados
    for(int i=1; i<=largo; i++){
        d[i] = inf;
        c[i] = "";
    }
    // busco el vertice del parametro

    // consigo la lista de adyacentes del origen
    Lista<Arista>& adyacentes = verticeOrigen->getAdyacentes();
    // inicializo las distancias y caminos de los adyacentes al origen
    for(int i=1; i<=adyacentes.obtenerLargo(); i++){
        // consigo la arista
        Arista& arista = adyacentes.consulta(i);
        string verticeDestino = arista.getDestino();
        int peso = arista.getPeso();
        // busco el vertice destino en la lista de vertices
        for(int a=1; a<=largo; a++){
            NodoGrafo& vertice = vertices.consulta(a);
            if(vertice.getId() == verticeDestino){
                d[a] = peso;
                c[a] = verticeOrigen->getId();
            }
        }
    }//marco el vertice origen como visitado
    verticeOrigen->setVisitado(true);
    // mientras haya vertices no visitados
    while (true){
        // mindistancia almacena la distancia minima encontrada
        int minDistancia = inf;
        int verticeMinimo = -1; // almacena la posicion del vertice minimo
        // busco el no visitado con menor distancia
        for(int i=1; i<=largo; i++){
            NodoGrafo& vertice = vertices.consulta(i);
            if(!vertice.getVisitado() && d[i] < minDistancia){
                minDistancia = d[i]; // guardo la distancia encontrada
                verticeMinimo = i; // guardo la posicion del vertice encontrado
            }
        }// salgo del while si no encuentro ningun no visitado
        if(verticeMinimo == -1){
            break;
        }
        // marco el vertice que encontre como visitado
        vertices.consulta(verticeMinimo).setVisitado(true);
        // obtengo la lista de adyacentes del vertice minimo
        Lista<Arista>& adj = vertices.consulta(verticeMinimo).getAdyacentes();
        // hago recorrido por los adyacentes y actualizo distancias y caminos 
        for(int i=1; i<=adj.obtenerLargo(); i++){
            Arista& arista = adj.consulta(i);
            string verticeDestino = arista.getDestino();
            int peso = arista.getPeso();
            // busco la posicion del vecino en la lista de vertices
            for(int a=1; a<=largo; a++){
                // voy buscando el vertice
                NodoGrafo& vertice = vertices.consulta(a);
                if(vertice.getId() == verticeDestino){
                    // actualizo si la distancia es menor a la guardada
                    if(d[verticeMinimo] + peso < d[a]){
                        d[a] = d[verticeMinimo] + peso; // guardo la nueva distancia
                        c[a] = vertices.consulta(verticeMinimo).getId(); //guardo el id del vertice anterior en el camino
                    }
                }
            }
        }
    }
    // copiar en listas que pasamos por referencia
    for (int i = 1; i <= largo; i++){
        caminos.alta(c[i]);
        distancias.alta(d[i]);
    }
}

void Grafo::calcularCamino(string origen, string destino){
    // armo listas de caminos y distancias a ser usadas en dijkstra
    NodoGrafo* verticeOrigen = buscarVertice(origen);
    if(verticeOrigen == nullptr){
        cout<< "No existe el vertice"<<endl;
        return;
    }
    Lista<string> caminos;
    Lista<int> distancias;
    dijkstra(verticeOrigen, caminos, distancias); // ejecutamos dijstra
    int largo =vertices.obtenerLargo();
    int posDestino = -1; // variable para guardar la posicion del vertice
    for(int i=1; i<=largo; i++){ // for para guardar la posicion del vertice
        if(vertices.consulta(i).getId() == destino){
            posDestino = i;
            break;
        }
    }
    if(posDestino == -1){
        cout<< "No existe el vertice destino"<<endl;
        return;
    }   
    // armo el camino 
    string camino = destino;
    string actual = destino;
    while(actual != origen ){ // mientras que el actual no llegue al origen
        for(int i=1; i<=largo; i++){ // encuentro el vertice
            if(vertices.consulta(i).getId() == actual){
                actual = caminos.consulta(i); // cambio el actual para que sea el anterior
                camino = actual + " -> " + camino; // armo el camino
                break;
            }
        }
    }
    cout << "camino: " << camino << endl;
}


Lista<string>Grafo::hospitalesMasCercanos(string origen){
    Lista<string> caminos;
    Lista<int> distancias;
    NodoGrafo* verticeOrigen = buscarVertice(origen);
    if(verticeOrigen == nullptr){
        cout<< "No existe el vertice"<<endl;
        return caminos;
    }    
    dijkstra(verticeOrigen, caminos, distancias);
    desmarcarVisitados();  
    int largo = vertices.obtenerLargo();
    Lista<string> hospitales; // lista que guarda 
    while (true){
        int minDistancia = 99999;
        int verticeMinimo = -1;
        // busco el no visitado con menor distancia
        for(int i=1; i<=largo; i++){
            NodoGrafo& vertice = vertices.consulta(i);
            // verifico que no sea visitado y que la distancia sea menor
            if(!vertice.getVisitado() && distancias.consulta(i) < minDistancia && vertice.getId() != origen){
                minDistancia = distancias.consulta(i); // guardo la distancia
                verticeMinimo = i; // guardo la posicion del vertice
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
