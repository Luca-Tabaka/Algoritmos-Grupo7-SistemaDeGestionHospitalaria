#ifndef TURNO_H_
#define TURNO_H_
#include<string>
#include<vector>

class Turno{
    private:
    int turnoId;
    std:: string codigoHospital;
    int idPaciente;
    int idMedico;
    std:: string fecha; // o date
    std:: string especialidad;
    int duracion;

};

#endif