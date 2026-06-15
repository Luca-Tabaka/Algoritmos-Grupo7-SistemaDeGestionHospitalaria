#include"paciente.h"

        std:: string Paciente::getodigoHospital(){
            return codigoHospital;
        }
        int Paciente::getIdPaciente(){
            return idPaciente;
        }
        std:: string Paciente::getDni(){
            return dni;
        }
        std:: string Paciente::getFechaIngreso(){
            return fechaIngreso;
        } 
        std:: string Paciente::getDiagnostico(){
            return diagnostico;
        }
        int Paciente::getPrioridad(){
            return prioridad;
        }
        float Paciente::getPeso(){
            return peso;
        }