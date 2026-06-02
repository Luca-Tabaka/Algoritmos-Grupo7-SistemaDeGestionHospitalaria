/*
 * grafo.h
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#ifndef GRAFO_H_
#define GRAFO_H_
#include<vector>
#include<string>
#include "NodoGrafo.h"
class Grafo{

	private:
		std::vector<NodoGrafo*> nodos;
	public:
		Grafo();
		void agregarNodo(NodoGrafo* n);
		std::vector<NodoGrafo*> getNodos();
		std::string toString();
};



#endif /* GRAFO_H_ */
