#include"ambulancia.h"
#include<iostream>

using namespace std;

int Ambulancia::valorMaximoRestante(int i, Lista<Insumo*>& insumos){
    int suma = 0;
    for(int j = i; j <= insumos.obtenerLargo();j++){
        suma+= insumos.consulta(j)->getPrioridad();
    }
    return suma;
}
//
void Ambulancia::backtrackingPoda(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial, int& nodosVisitados){
    int n = insumosHospital.obtenerLargo();
    nodosVisitados++;//calcula cuantos nodos se visitaron durante la ejecucion
    if(i>n){//caso base, si llega al final de la lista, verifica la solucion y si es la mejor la guarda
        if(valorActual > mejorValor){
            mejorValor = valorActual;
            mejorSolucion = solucionParcial;
        }
        return;
    }
    if(valorActual + valorMaximoRestante(i,insumosHospital) <= mejorValor){// si la rama actual no puede superar la mejor, poda
        return;
    }
    Insumo* actual = insumosHospital.consulta(i);//se obtiene el siguiente elemento a revisar
    float peso = actual-> getPeso();
    int valor = actual-> getPrioridad();

    backtrackingPoda(i+1, pesoActual,valorActual,insumosHospital,solucionParcial,nodosVisitados);//se elige no incluir el objeto

    if(pesoActual + peso <= capacidadMaxima){//Se elige incluir al objeto, solo si su peso no supera el limite de capacidad
        solucionParcial.alta(actual, 1);
        backtrackingPoda(i+1, pesoActual+peso,valorActual+valor,insumosHospital,solucionParcial,nodosVisitados);
        solucionParcial.baja(1);//cuando recorre toda la rama, lo retira
    }

}
// Dada una lista de insumos calcula la mejor carga teniendo en cuenta un limite de capacidad
void Ambulancia::backtrackingPuro(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial, int& nodosVisitados){
    int n = insumosHospital.obtenerLargo();
    nodosVisitados++; //calcula cuantos nodos se visitaron durante la ejecucion
    if(i>n){ //caso base, si llega al final de la lista, verifica la solucion y si es la mejor la guarda
        if(valorActual > mejorValor){
            mejorValor = valorActual;
            mejorSolucion = solucionParcial;
        }
        return;
    }
    Insumo* actual = insumosHospital.consulta(i);//se obtiene el siguiente elemento a revisar
    float peso = actual-> getPeso(); // encuentro el peso
    int valor = actual-> getPrioridad(); // encuentro la prioridad

    backtrackingPuro(i+1, pesoActual,valorActual,insumosHospital,solucionParcial,nodosVisitados);//se elige no incluir el objeto

    if(pesoActual + peso <= capacidadMaxima){
        solucionParcial.alta(actual, 1); // lo da de alta en solucionparcial que es una lista que guarda la solucion de la rama actual
        backtrackingPuro(i+1, pesoActual+peso,valorActual+valor,insumosHospital,solucionParcial,nodosVisitados);//Se elige incluir al objeto, pero solo si su peso no supera el limite de capacidad
        solucionParcial.baja(1);//cuando recorre toda la rama, lo retira
    }

}

void Ambulancia::pruebaBacktracking(Lista<Insumo*>& insumosHospital){// comparacion de nodos visitados en ambas ejecuciones
    mejorValor = 0;
    mejorSolucion.vaciar();
    int nodosVisitados = 0;

    Lista<Insumo*> solucionParcial;

    backtrackingPoda(1,0,0, insumosHospital,solucionParcial,nodosVisitados);
    std::cout << "Nodos con poda: " << nodosVisitados << std::endl;
    nodosVisitados = 0;
    mejorValor = 0;
    mejorSolucion.vaciar();
    backtrackingPuro(1,0,0, insumosHospital,solucionParcial,nodosVisitados);
    std::cout << "Nodos sin poda: " << nodosVisitados << std::endl;
}

Lista<Insumo*> Ambulancia::calcularCarga(Lista<Insumo*>& insumosHospital){
    mejorValor = 0;
    mejorSolucion.vaciar();
    int nodosVisitados = 0;
    Lista<Insumo*> solucionParcial;
    backtrackingPoda(1,0,0, insumosHospital,solucionParcial,nodosVisitados);
    return mejorSolucion;
}

float Ambulancia::getCapacidad() const{
    return capacidadMaxima;
}
void Ambulancia::mostrarMejor(){
    if(mejorSolucion.esVacia()){
        cout<<"La ambulancia no tiene ninguna carga";
        return;
    }
    for(int i = 1;i <= mejorSolucion.obtenerLargo();i++){
        Insumo* insumoActual = mejorSolucion.consulta(i);
        cout<<"Insumo: " << insumoActual->getNombre() << " Peso: " << insumoActual->getPeso() << " prioridad: " << insumoActual->getPrioridad() << endl;
    }
}