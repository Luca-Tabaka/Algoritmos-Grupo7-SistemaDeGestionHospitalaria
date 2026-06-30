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
        Paciente(string codigoHospital, int idPaciente, string dni, string fechaIngreso, string diagnostico, int prioridad, float peso);
        void cambiarPrioridad(int nuevaPrioridad);
        string getCodigoHospital();
        void setCodigoHospital(string cod);
        int getIdPaciente();
        string getDni();
        string getFechaIngreso(); // aca podria ser date quizas
        string getDiagnostico();
        int getPrioridad();
        float getPeso();

};


#endif