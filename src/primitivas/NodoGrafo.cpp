/*
 * nodoGrafo.cpp
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#include"NodoGrafo.h"
NodoGrafo::NodoGrafo(std::string h){
	hospital = h;
}
void NodoGrafo::agregarArista(Arista a){
	aristas.push_back(a);
}
std::string NodoGrafo::getHospital(){
	return hospital;
}
/*
void NodoGrafo::setHospital(std::string h){
	hospital = h;
}
*/


std::vector<Arista> NodoGrafo::getAristas(){
	return aristas;
}
std::string NodoGrafo::toString(){
	std::string mensaje = "Nodo[ valor: " + hospital + " aristas: ";
	for(Arista a : aristas){
		mensaje += a.toString();
	}
	mensaje+="]";
	return mensaje;
}



