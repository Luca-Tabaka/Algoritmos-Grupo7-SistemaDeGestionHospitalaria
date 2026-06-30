#include"turno.h"
#include<iostream>
    Turno::Turno(int id, string codhospital, int idP, int idM, string fec, string especialidad, int t){
        this->idTurno = id;
        this->codigoHospital = codhospital;
        this->idPaciente = idP;
        this->idMedico = idM;
        this->fecha = fec;
        this->especialidad = especialidad;
        this->duracion = t;
    }
    
    int Turno::getTurnoId(){
        return idTurno;
    }
    std:: string Turno::getCodigoHospital(){
        return codigoHospital;
    }
    int Turno::getIdPaciente(){
        return idPaciente;
    }
    int Turno::getIdMedico(){
        return idMedico;
    }
    std:: string Turno::getFecha(){
        return fecha;
    }
    std:: string Turno::getEspecialidad(){
        return especialidad;
    }
    int Turno::getDuracion(){
        return duracion;
    }

    void Turno::imprimir(){
        cout << "ID Turno: " << idTurno<<" ";
        cout << "Codigo Hospital: " << codigoHospital<<" ";
        cout << "ID Paciente: " << idPaciente<<" ";
        cout << "ID Medico: " << idMedico<<" ";
        cout << "Fecha: " << fecha<<" ";
        cout << "Especialidad: " << especialidad<<" ";
        cout << "Duracion: " << duracion << endl;
    }