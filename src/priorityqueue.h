#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include<vector>
#include"Paciente.h"
#include"primitivas/lista.h"

class PriorityQueue{
    private:
        Lista<Paciente*> listaEspera;

    public:
        void cambiarPrioridad(string dni, int nuevaPrioridad);
        void push(Paciente* p);

        void pop();

        Paciente* primero();

        bool vacio();

        int size();
};

#endif