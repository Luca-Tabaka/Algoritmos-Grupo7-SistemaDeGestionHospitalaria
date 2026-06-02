/*
 * grafo.cpp
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#include"NodoGrafo.h"
#include<vector>
#include"Grafo.h"

Grafo::Grafo(){

}
void Grafo::agregarNodo(NodoGrafo* n){
	nodos.push_back(n);
}

std::vector<NodoGrafo*> Grafo::getNodos(){
	return nodos;
}

std::string Grafo::toString(){
	std::string mensaje = "Grafo [Nodos: ";
	for(NodoGrafo* n : nodos){
		mensaje+= "\n" + n->toString();
	}
	mensaje += "]";
	return mensaje;
}

