/*
 * nodoGrafo.h
 *
 *  Created on: 30 May 2026
 *      Author: xenbr
 */

#ifndef NODOGRAFO_H_
#define NODOGRAFO_H_
#include<vector>
#include"Arista.h"
#include<string>

class NodoGrafo{
	private:
		std::string hospital;
		std::vector<Arista> aristas;
	public:
		NodoGrafo(std::string h);
		std::string getHospital();
		//void setHospital(std::string h);
		std::vector<Arista> getAristas();
		void agregarArista(Arista a);
		std::string toString();
};



#endif /* NODOGRAFO_H_ */



