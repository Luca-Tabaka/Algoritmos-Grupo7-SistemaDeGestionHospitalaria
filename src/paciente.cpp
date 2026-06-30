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
        void Paciente::cambiarPrioridad(int nuevaPrioridad){
            prioridad = nuevaPrioridad;
        }

        float Paciente::getPeso(){
            return peso;
        }