/*
 * arista.cpp
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#include"Arista.h"
#include"NodoGrafo.h"
Arista::Arista(NodoGrafo* o, NodoGrafo* d, int p){
	origen = o;
	destino = d;
	peso = p;
}
NodoGrafo* Arista::obtenerOrigen(){
	return origen;
}
NodoGrafo* Arista::obtenerDestino(){
	return destino;
}
void Arista::setDestino(NodoGrafo* nuevoDestino){
	destino = nuevoDestino;
}
void Arista::setOrigen(NodoGrafo* nuevoOrigen){
	origen = nuevoOrigen;
}

int Arista::getPeso(){
	return peso;
}
void Arista::setPeso(int p){
	peso = p;
}

std::string Arista::toString(){
	std::string mensaje = "\nArista [origen: " + origen->getHospital() + " destino: " + destino->getHospital() + " peso: " + std::to_string(peso) + "]";
	return mensaje;
}



