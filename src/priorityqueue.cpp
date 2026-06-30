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
    if (vacio())
    {
        cout<<"La lista esta vacia!"<<endl;
        return;
    }
    
    listaEspera.baja(1);
}

Paciente* PriorityQueue::primero(){
    if (vacio())
    {
        cout<<"La lista esta vacia!"<<endl;
        return nullptr;
    }
        
    return listaEspera.consulta(1);
}   

bool PriorityQueue::vacio(){
    return listaEspera.obtenerLargo() == 0;
}

void PriorityQueue::cambiarPrioridad(string dni, int nuevaPrioridad){
    int i = 1;
    while(i <= listaEspera.obtenerLargo()){
        Paciente* actual = listaEspera.consulta(i);
        if(actual->getDni() == dni){
            listaEspera.baja(i);
            actual->cambiarPrioridad(nuevaPrioridad);
            push(actual);
            cout<<"Prioridad cambiada con exito"<< endl;
            return;
        }
        i++;
    }
    cout<<"No se encontro el paciente con ese dni" << endl;
}

int PriorityQueue::size(){
    return listaEspera.obtenerLargo();
}