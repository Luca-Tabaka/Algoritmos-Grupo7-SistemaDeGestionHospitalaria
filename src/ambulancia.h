#ifndef AMBULANCIA_H_INCLUDED
#define AMBULANCIA_H_INCLUDED
#include "insumo.h"

class Ambulancia{
    private:
        float capacidadMaxima;
        //lista insumos = lista();
    public:
        void cargarInsumo(Insumo insumo);
};


#endif