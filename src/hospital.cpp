#include"hospital.h"
#include<iostream>
#include<string>

Hospital::Hospital(std:: string codigoHospital,std:: string nombre, std:: string ciudad, int capacidadCamas, Lista<std::string> especialidades,int personalMedico,double presupuestoAnual){
    codigoHospital = codigoHospital;
    nombre = nombre;
    ciudad = ciudad;
    capacidadCamas = capacidadCamas;
    especialidades = especialidades;
    personalMedico = personalMedico;
    presupuestoAnual = presupuestoAnual;
}

std::string Hospital::mostrarInformacion(){
    std::string mensaje = "\n" + codigoHospital +": " + nombre + " - " + ciudad + " - capacidad:"
    + std::to_string(capacidadCamas) + " - especialidades: ";

    for(int i = 0; i < especialidades.obtener_largo(); i++){
        mensaje += " - " + especialidades.consulta(i);
    }
    mensaje += " personal: " + std::to_string(personalMedico) + "presupuesto: $" + std::to_string(presupuestoAnual);
    return mensaje;
}

bool Hospital::tieneEspecialidad(std::string especialidad){
    for(int i = 0;i < especialidades.obtener_largo();i++){
        if(especialidades.consulta(i) == especialidad){
            return true;
        }
    }
    return false;
}

int Hospital::pacientesAtendidos(std::string fechaInicio, std::string fechaFin){
    int atendidos = 0;
    for(int i = 0; i < turnos.obtener_largo(); i++){
        std::string fecha = turnos.consulta(i)->getFecha();
       if(fechaInicio <=  fecha && fechaFin >= fecha){
        atendidos+=1;
       }
    }
    return atendidos;
}

int Hospital::cantidadPacientes(){
    return turnos.obtener_largo();
}

int Hospital::cantidadDeCamasDisponibles(){
    if(cantidadPacientes() > capacidadCamas){
        return -1;
    }
    return capacidadCamas - cantidadPacientes();
}


bool Hospital::tieneSobrecarga(){
    return (pacientesAtendidos("2025-05-05","2025-05-12") > 20 || (cantidadDeCamasDisponibles() / capacidadCamas) <= 0.10f);
}

std::string Hospital::getNombre(){
    return nombre;
}
std:: string Hospital::getCodigoHospital(){
    return codigoHospital;
}
std:: string Hospital::getCiudad(){
    return ciudad;
}
int Hospital::getCapacidadCamas(){
    return capacidadCamas;
}
Lista<std::string> Hospital::getEspecialidades(){
    return especialidades;
}
int Hospital::getPersonalMedico(){
    return personalMedico;
}
double Hospital::getPresupuestoAnual(){
    return presupuestoAnual;
}