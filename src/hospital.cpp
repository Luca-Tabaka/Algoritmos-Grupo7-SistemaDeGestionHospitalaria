#include"hospital.h"
#include<iostream>
#include<string>
using namespace std;

Hospital::Hospital(string codigoHospital, string nombre,  string ciudad, int capacidadCamas, Lista<string> especialidades,int personalMedico,double presupuestoAnual){
    this->codigoHospital = codigoHospital;
    this->nombre = nombre;
    this->ciudad = ciudad;
    this->capacidadCamas = capacidadCamas;
    this->especialidades = especialidades;
    this->personalMedico = personalMedico;
    this->presupuestoAnual = presupuestoAnual;
}

Hospital:: ~Hospital(){
    for (int i = 1; i <= pacientes.obtenerLargo(); i++)
    {
        Paciente* p = pacientes.consulta(i);
        delete p;
    }
    for (int i = 1; i <= turnos.obtenerLargo(); i++)
    {
        Turno* t = turnos.consulta(i);
        delete t;
    }   
    
    for (int i = 1; i <= insumos.obtenerLargo(); i++)
    {
        Insumo* in = insumos.consulta(i);
        delete in;
    }      
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
// no usa turnosMedico
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
    int largo = turnosMedico.obtenerLargo();
    for(int i=2; i<=largo; i++){
        Turno* turno = turnosMedico.consulta(i);
        int j = i - 1;
        while(j >= 1 && turnosMedico.consulta(j)->getFecha() > turno->getFecha()){
            turnosMedico.consulta(j + 1) = turnosMedico.consulta(j);
            j--;
            }
        turnosMedico.consulta(j + 1) = turno;
    }    

    for(int i=1; i<=turnosMedico.obtenerLargo();i++){
        Turno* t = turnosMedico.consulta(i);
        t->imprimir();
    }    
} 

void Hospital::listarTurnosPaciente(string dniPaciente){
    Paciente* paciente = obtenerPaciente(dniPaciente);
    if(paciente == nullptr){
        cout<<"No se encontro un paciente con ese dni";
        return;
    }
    for(int i=1; i<=turnos.obtenerLargo();i++){
        Turno* t = turnos.consulta(i);
        if (t->getIdPaciente()==paciente->getIdPaciente()){
           t->imprimir();
        }
    }
}
void Hospital::cargaDerivacion(int capacidadMax){
    Ambulancia amb = Ambulancia(capacidadMax);
    amb.calcularCarga(insumos);
    amb.mostrarMejor();
}
void Hospital::comparacionBacktracking(int capacidadMax){
    Ambulancia amb = Ambulancia(capacidadMax);
    amb.pruebaBacktracking(insumos);
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
    return pacientes.obtenerLargo();
}

int Hospital::cantidadDeCamasDisponibles(){
    if(cantidadPacientes() > capacidadCamas){
        return 0;
    }
    return capacidadCamas - cantidadPacientes();
}
Paciente* Hospital::quitarPaciente(){
    Paciente* p = pacientes.consulta(1);
    pacientes.baja(1);
    return p;
}


bool Hospital::tieneSobrecarga(string fecha){
    return (pacientesAtendidos(semanaAnterior(fecha),fecha) > 10 || (cantidadDeCamasDisponibles() / (float)capacidadCamas) <= 0.10f);
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
string Hospital::semanaAnterior(string fecha){
    tm t = {};

    t.tm_year = stoi(fecha.substr(0,4)) -1900; // agarra los primeros 4 digitos de fecha y le resta 1900 porque tm cuenta desde 1900
    t.tm_mon = stoi(fecha.substr(4,2)) -1;//resta 1 porque tm cuenta los meses desde el 0
    t.tm_mday = stoi(fecha.substr(6,2));

    time_t tiempo = mktime(&t);//se transforma a segundos
    tiempo -= 7*24*60*60; //se resta una semana en segundos

    //hacemos operacion inversa para producir el string de fecha
    t = *localtime(&tiempo);

    char buffer[9];

    sprintf(buffer,"%04d%02d%02d", t.tm_year + 1900, t.tm_mon+1,t.tm_mday);

    return string(buffer);
    
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

void Hospital::agregarEspecialidad(string especialidad){
        especialidades.alta(especialidad);
}


void Hospital::agregarTurno(Turno* turno){
    turnos.alta(turno,1);
}

void Hospital::agregarInsumo(Insumo* insumo){
    insumos.alta(insumo);
}