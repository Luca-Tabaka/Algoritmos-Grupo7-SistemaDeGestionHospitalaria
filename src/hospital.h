#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include<string>
#include "primitivas/lista.h"
#include "primitivas/nodo.h"
#include"turno.h"

class Hospital{
    private:
        std::string codigoHospital;
        std::string nombre;
        std::string ciudad;
        int capacidadCamas;
        Lista<std::string> especialidades;
        int personalMedico;
        double presupuestoAnual;
        Lista<Turno*> turnos;

    public:
        Hospital(std:: string codigoHospital,std:: string nombre, std:: string ciudad, int capacidadCamas, Lista<std::string> especialidades,int personalMedico,double presupuestoAnual);
        std:: string mostrarInformacion();
        //listaPacientes(); este sera de tipo vector con la lista de pacientes

        int pacientesAtendidos(std::string fechaInicio, std::string fechaFin);
        int cantidadDeCamasDisponibles();
        int cantidadPacientes();
        bool tieneEspecialidad(std::string especialidad);
        bool tieneSobrecarga();

        std::string getNombre();
        std:: string getCodigoHospital();
        std:: string getCiudad();
        int getCapacidadCamas();
        Lista<std::string> getEspecialidades();
        int getPersonalMedico();
        double getPresupuestoAnual();
};




#endif