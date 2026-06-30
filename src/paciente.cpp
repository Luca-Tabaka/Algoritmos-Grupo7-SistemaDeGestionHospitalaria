#include"paciente.h"
        Paciente::Paciente(string codigoHospital, int idPaciente, string dni, string fechaIngreso, string diagnostico, int prioridad, float peso){
            this->codigoHospital = codigoHospital;
            this->idPaciente = idPaciente;
            this->dni = dni;
            this->fechaIngreso = fechaIngreso;
            this->diagnostico = diagnostico;
            this->prioridad = prioridad;
            this->peso = peso;
        }
        
        std:: string Paciente::getCodigoHospital(){
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