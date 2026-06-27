#ifndef AMBULANCIA_H_INCLUDED
#define AMBULANCIA_H_INCLUDED
#include "insumo.h"
#include "primitivas/lista.h"

class Ambulancia{
    private:
        float capacidadMaxima;
        Lista<Insumo*> insumos;
    public:
        void cargarInsumo(Insumo insumo);

        float getCapacidad();
        Lista<Insumo*> getInsumos();
};


#endif