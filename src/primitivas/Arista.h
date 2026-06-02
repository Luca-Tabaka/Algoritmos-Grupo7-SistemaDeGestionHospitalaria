/*
 * arista.h
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#ifndef ARISTA_H_
#define ARISTA_H_
#include<string>
class NodoGrafo;

class Arista{
	private:
		NodoGrafo* origen;
		NodoGrafo* destino;
		int peso;
	public:
		Arista(NodoGrafo* o,NodoGrafo* d, int p);
		NodoGrafo* obtenerOrigen();
		NodoGrafo* obtenerDestino();
		void setDestino(NodoGrafo* nuevoDestino);
		void setOrigen(NodoGrafo* nuevoOrigen);
		int getPeso();
		void setPeso(int p);
		std::string toString();
};



#endif /* ARISTA_H_ */
