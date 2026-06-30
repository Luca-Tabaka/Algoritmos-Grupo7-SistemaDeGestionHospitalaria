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

void Ambulancia::backtrackingPoda(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial, int& nodosVisitados){
    int n = insumosHospital.obtenerLargo();
    nodosVisitados++;
    if(i>n){
        if(valorActual > mejorValor){
            mejorValor = valorActual;
            mejorSolucion = solucionParcial;
        }
        return;
    }

    if(pesoActual > capacidadMaxima){
        return;
    }
    if(valorActual + valorMaximoRestante(i,insumosHospital) <= mejorValor){
        return;
    }
    Insumo* actual = insumosHospital.consulta(i);
    float peso = actual-> getPeso();
    int valor = actual-> getPrioridad();

    backtrackingPoda(i+1, pesoActual,valorActual,insumosHospital,solucionParcial,nodosVisitados);

    if(pesoActual + peso <= capacidadMaxima){
        solucionParcial.alta(actual, 1);
        backtrackingPoda(i+1, pesoActual+peso,valorActual+valor,insumosHospital,solucionParcial,nodosVisitados);
        solucionParcial.baja(1);
    }

}
void Ambulancia::backtrackingPuro(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial, int& nodosVisitados){
    int n = insumosHospital.obtenerLargo();
    nodosVisitados++;
    if(i>n){
        if(valorActual > mejorValor){
            mejorValor = valorActual;
            mejorSolucion = solucionParcial;
        }
        return;
    }
    Insumo* actual = insumosHospital.consulta(i);
    float peso = actual-> getPeso();
    int valor = actual-> getPrioridad();

    backtrackingPuro(i+1, pesoActual,valorActual,insumosHospital,solucionParcial,nodosVisitados);

    if(pesoActual + peso <= capacidadMaxima){
        solucionParcial.alta(actual, 1);
        backtrackingPuro(i+1, pesoActual+peso,valorActual+valor,insumosHospital,solucionParcial,nodosVisitados);
        solucionParcial.baja(1);
    }

}

void Ambulancia::pruebaBacktracking(Lista<Insumo*>& insumosHospital){
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
    for(int i = 1;i <= mejorSolucion.obtenerLargo();i++){
        Insumo* insumoActual = mejorSolucion.consulta(i);
        cout<<"Insumo: " << insumoActual->getNombre() << " Peso: " << insumoActual->getPeso() << " prioridad: " << insumoActual->getPrioridad() << endl;
    }
}