#ifndef PACIENTE_H_
#define PACIENTE_H_
#include<string>
using namespace std;

class Paciente{
    private:
        string codigoHospital;
        int idPaciente;
        string dni;
        string fechaIngreso; // aca podria ser date quizas
        string diagnostico;
        int prioridad;
        float peso; 
    
    public:
        void cambiarPrioridad(int nuevaPrioridad);
        string getodigoHospital();
        int getIdPaciente();
        string getDni();
        string getFechaIngreso(); // aca podria ser date quizas
        string getDiagnostico();
        int getPrioridad();
        float getPeso();

};


#endif