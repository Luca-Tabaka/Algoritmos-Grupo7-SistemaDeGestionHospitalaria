#ifndef AMBULANCIA_H_INCLUDED
#define AMBULANCIA_H_INCLUDED
#include "insumo.h"
#include "primitivas/lista.h"

class Ambulancia{
    private:
        float capacidadMaxima;
        Lista<Insumo*> mejorSolucion;
        int mejorValor;
        void backtrackingPoda(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial,int& nodosVisitados);
        void backtrackingPuro(int i, float pesoActual, int valorActual,Lista<Insumo*>& insumosHospital, Lista<Insumo*>& solucionParcial,int& nodosVisitados);
        int valorMaximoRestante(int i, Lista<Insumo*>& insumos);
    public:
        Ambulancia(float capacidadMax){
            capacidadMaxima = capacidadMax;
            mejorValor = 0;
        }
        void pruebaBacktracking(Lista<Insumo*>& insumosHospital);
        Lista<Insumo*> calcularCarga(Lista<Insumo*>& insumosHospital);
        void mostrarMejor();
        float getCapacidad() const;
};
#endif