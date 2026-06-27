#ifndef SISTEMAHOSPITALARIO_H_INCLUDED
#define SISTEMAHOSPITALARIO_H_INCLUDED
#include"turno.h"
#include"tablaHash.h"
#include"derivacion.h"
#include"primitivas/lista.h"
#include"hospital.h"
using namespace std;

class SistemaHospitalario{
    private:
        TablaHash listaHospitales;
        Lista<Turno> turnos;
        Lista<Derivacion*> listaDerivaciones;
        //ABB diagnosticos;
    public:
        void consultarInformacionHospital(string codHospital);
        void agregarHospital(Hospital* hospital);
        void eliminarHospital(string codigoHospital);
        void listarHospitales();
        //lista calcularRutaDerivacion(Hospital origen, Hospital destino);
        Lista<Hospital*> hospitalesConSobrecarga();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(int idPaciente);
        Lista<Hospital*> hospitalesPorEspecialidad(string especialidad);
};


#endif