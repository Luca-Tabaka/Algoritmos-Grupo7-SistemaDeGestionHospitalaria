#ifndef SISTEMAHOSPITALARIO_H_INCLUDED
#define SISTEMAHOSPITALARIO_H_INCLUDED
#include"hospital.h"

class SistemaHospitalario{
    private:
        //listaHash listaHospitales;
        //lista listaDerivaciones;
        //ABB diagnosticos;
    public:
        void consultarInformacionHospital(std::string codHospital);
        void agregarHospital(Hospital hospital);
        void eliminarHospital(std::string codigoHospital);
        void listarHospitales();
        //lista calcularRutaDerivacion(Hospital origen, Hospital destino);
        //lista hospitalesConSobrecarga();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(int idPaciente);
        //lista hospitalesPorEspecialidad(std::string especialidad);
};


#endif