#include"hospital.h"
#include<iostream>
#include<string>
using namespace std;

Hospital::Hospital( string codigoHospital, string nombre,  string ciudad, int capacidadCamas, Lista<string> especialidades,int personalMedico,double presupuestoAnual){
    this->codigoHospital = codigoHospital;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->capacidadCamas = capacidadCamas;
    this->especialidades = especialidades;
    this->personalMedico = personalMedico;
    this->presupuestoAnual = presupuestoAnual;
}



string Hospital::mostrarInformacion(){
    string mensaje = "\n" + codigoHospital +": " + nombre + " - " + ciudad + " - capacidad:"
    + to_string(capacidadCamas) + " - especialidades: ";

    for(int i = 1; i <= especialidades.obtenerLargo(); i++){
        mensaje += especialidades.consulta(i)+" - ";
    }
    mensaje += " personal: " + to_string(personalMedico) + " presupuesto: $" + to_string(presupuestoAnual);
    return mensaje;
}

Paciente* Hospital::obtenerPaciente(string dni){
    Paciente* paciente = nullptr;
    for(int i = 1; i <=pacientes.obtenerLargo();i++){
        paciente = pacientes.consulta(i);
        if(paciente->getDni() == dni){
            return paciente;
        }
    }
    return nullptr;
}

void Hospital::listarTurnosMedico(int idMedico){
    Lista<Turno*> turnosMedico;
    for (int i = 1; i <= turnos.obtenerLargo() ; i++)
    {
        Turno* turno = turnos.consulta(i);
        if(turno->getIdMedico() == idMedico){
            turnosMedico.alta(turno, 1);
        }
    }

    if(turnosMedico.esVacia()){
        cout<<"No se encontraron turnos"<< endl;
        return;
    }
    int largo = turnos.obtenerLargo();
    for(int i=2; i<=largo; i++){
        Turno* turno = turnos.consulta(i);
        int j = i - 1;
        while(j >= 1 && turnos.consulta(j)->getFecha() > turno->getFecha()){
            turnos.consulta(j + 1) = turnos.consulta(j);
            j--;
            }
        turnos.consulta(j + 1) = turno;
    }    

    for(int i=1; i<=turnosMedico.obtenerLargo();i++){
        Turno* t = turnos.consulta(i);
        t->imprimir();
    }    
} 

void Hospital::listarTurnosPaciente(string dniPaciente){
    Paciente* paciente = obtenerPaciente(dniPaciente);
    if(paciente == nullptr){
        cout<<"No se encontro un paciente con ese dni";
    }

    for(int i=1; i<=turnos.obtenerLargo();i++){
        Turno* t = turnos.consulta(i);
        if (t->getIdPaciente()==paciente->getIdPaciente()){
           t->imprimir();
        }
    }
}







bool Hospital::tieneEspecialidad(string especialidad){
    for(int i = 1 ;i <= especialidades.obtenerLargo();i++){
        if(especialidades.consulta(i) == especialidad){
            return true;
        }
    }
    return false;
}

int Hospital::pacientesAtendidos(string fechaInicio, string fechaFin){
    int atendidos = 0;
    for(int i = 1; i <= turnos.obtenerLargo(); i++){
        string fecha = turnos.consulta(i)->getFecha();
       if(fechaInicio <=  fecha && fechaFin >= fecha){
        atendidos+=1;
       }
    }
    return atendidos;
}

int Hospital::cantidadPacientes(){
    return turnos.obtenerLargo();
}

int Hospital::cantidadDeCamasDisponibles(){
    if(cantidadPacientes() > capacidadCamas){
        return 0;
    }
    return capacidadCamas - cantidadPacientes();
}


bool Hospital::tieneSobrecarga(){
    return (pacientesAtendidos("2025-05-05","2025-05-12") > 20 || (cantidadDeCamasDisponibles() / capacidadCamas) <= 0.10f);
}

string Hospital::getNombre(){
    return nombre;
}
 string Hospital::getCodigoHospital(){
    return codigoHospital;
}
 string Hospital::getCiudad(){
    return ciudad;
}
int Hospital::getCapacidadCamas(){
    return capacidadCamas;
}
Lista<string> Hospital::getEspecialidades(){
    return especialidades;
}
int Hospital::getPersonalMedico(){
    return personalMedico;
}
double Hospital::getPresupuestoAnual(){
    return presupuestoAnual;
}

void Hospital::agregarPaciente(Paciente* paciente){
    pacientes.alta(paciente,1);
}

void Hospital::agregarTurno(Turno* turno){
    turnos.alta(turno,1);
}


// lista de espera
void Hospital:: agregarPacienteListaEspera(string dni){
    Paciente* p = obtenerPaciente(dni);
    if (p==nullptr)
    {
        cout<<"No se encontro el paciente a ingresar."<<endl;
        return;
    }
    listaEspera.push(p);
}
void Hospital::cambiarPrioridadPaciente(string dni, int nuevaPrioridad){
    Paciente* p = obtenerPaciente(dni);
    if (p==nullptr)
    {
        cout<<"No se encontro el paciente a ingresar."<<endl;
        return;
    }
    listaEspera.cambiarPrioridad(dni, nuevaPrioridad);
}
Paciente* Hospital::extraerPacienteListaEspera(){
    Paciente* primero = listaEspera.primero();
    listaEspera.pop();
    return primero;
}
