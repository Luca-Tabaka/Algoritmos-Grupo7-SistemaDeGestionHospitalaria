#include"priorityqueue.h"


void PriorityQueue::push(Paciente* p){
    if(listaEspera.vacia()){
        listaEspera.alta(p,1);
    }
    else{
        int i = 1;
        while(i <= listaEspera.obtener_largo()){
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
    return listaEspera.obtener_largo() == 0;
}

int PriorityQueue::size(){
    return listaEspera.obtener_largo();
}