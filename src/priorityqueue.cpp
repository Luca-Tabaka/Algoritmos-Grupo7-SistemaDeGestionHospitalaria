#include"priorityqueue.h"


void PriorityQueue::push(Paciente* p){
    if(listaEspera.esVacia()){
        listaEspera.alta(p,1);
    }
    else{
        int i = 1;
        while(i <= listaEspera.obtenerLargo()){
            Paciente* actual = listaEspera.consulta(i);

            if(actual->getPrioridad() > p->getPrioridad() || (actual->getPrioridad() == p->getPrioridad() && actual->getFechaIngreso() >= p->getFechaIngreso())){
                listaEspera.alta(p,i);
                return;
            }

            i++;
        }
        listaEspera.alta(p,i);
    }
}

void PriorityQueue::pop(){
    listaEspera.baja(1);
}

Paciente* PriorityQueue::primero(){
    return listaEspera.consulta(1);
}   

bool PriorityQueue::vacio(){
    return listaEspera.obtenerLargo() == 0;
}

int PriorityQueue::size(){
    return listaEspera.obtenerLargo();
}