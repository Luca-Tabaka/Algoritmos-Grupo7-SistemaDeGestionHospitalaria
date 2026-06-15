#ifndef PACIENTE_H_
#define PACIENTE_H_
#include<string>


class Paciente{
    private:
        std:: string codigoHospital;
        int idPaciente;
        std:: string dni;
        std:: string fechaIngreso; // aca podria ser date quizas
        std:: string diagnostico;
        int prioridad;
        float peso; 
    
    public:
        std:: string getodigoHospital();
        int getIdPaciente();
        std:: string getDni();
        std:: string getFechaIngreso(); // aca podria ser date quizas
        std:: string getDiagnostico();
        int getPrioridad();
        float getPeso();

};


#endif