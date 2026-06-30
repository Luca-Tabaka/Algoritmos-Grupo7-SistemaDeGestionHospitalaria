#ifndef TURNO_H_
#define TURNO_H_
#include<string>
using namespace std;

class Turno{
    private:
        int idTurno;
        string codigoHospital;
        int idPaciente;
        int idMedico;
        string fecha; // o date
        string especialidad;
        int duracion;
    public:
        Turno(int id, string codhospital, int idP, int idM, string fec, string especialidad, int t);
        int getTurnoId();
        string getCodigoHospital();
        int getIdPaciente();
        int getIdMedico();
        string getFecha(); // o date
        string getEspecialidad();
        int getDuracion();
        void imprimir();

};

#endif