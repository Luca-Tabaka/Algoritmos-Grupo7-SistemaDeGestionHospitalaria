#include"ambulancia.h"
        

        float Ambulancia::getCapacidad(){
            return capacidadMaxima;
        }
        Lista<Insumo*>  Ambulancia::getInsumos(){
            return insumos;
        }