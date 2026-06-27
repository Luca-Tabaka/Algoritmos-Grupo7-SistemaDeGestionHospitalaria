#ifndef SISTEMAHOSPITALARIO_H_INCLUDED
#define SISTEMAHOSPITALARIO_H_INCLUDED
#include"turno.h"
#include"derivacion.h"
#include"primitivas/lista.h"
#include"hospital.h"

class SistemaHospitalario{
    private:
        //listaHash listaHospitales;
        Lista<Turno> turnos;
        Lista<Derivacion*> listaDerivaciones;
        //ABB diagnosticos;
    public:
        void consultarInformacionHospital(std::string codHospital);
        void agregarHospital(Hospital hospital);
        void eliminarHospital(std::string codigoHospital);
        void listarHospitales();
        //lista calcularRutaDerivacion(Hospital origen, Hospital destino);
        Lista<Hospital*> hospitalesConSobrecarga();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(int idPaciente);
        Lista<Hospital*> hospitalesPorEspecialidad(std::string especialidad);
};


#endif