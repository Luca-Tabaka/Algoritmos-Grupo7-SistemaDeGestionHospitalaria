#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include<string>
#include"insumo.h"
#include"paciente.h"
#include "primitivas/lista.h"
#include "primitivas/nodo.h"
#include"turno.h"
#include "priorityqueue.h"
using namespace std; 

class Hospital{
    private:
        string codigoHospital;
        string nombre;
        string ciudad;
        int capacidadCamas;
        Lista<string> especialidades;
        int personalMedico;
        double presupuestoAnual;
        Lista<Insumo*> insumos;
        Lista<Turno*> turnos;
        Lista<Paciente*> pacientes;
        PriorityQueue listaEspera;
        Paciente* obtenerPaciente(string dni);
        




    public:
        Hospital( string codigoHospital, string nombre,  string ciudad, int capacidadCamas, Lista<string> especialidades,int personalMedico,double presupuestoAnual);
        string mostrarInformacion();
        int pacientesAtendidos(string fechaInicio, string fechaFin);
        int cantidadDeCamasDisponibles();
        int cantidadPacientes();
        bool tieneEspecialidad(string especialidad);
        bool tieneSobrecarga();
        Lista<Insumo*> calcularCargaAmbulancia(Lista<Insumo*> insumos, int capacidadMax);
        string getNombre();
        string getCodigoHospital();
        string getCiudad();
        int getCapacidadCamas();
        Lista<string> getEspecialidades();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(string dniPaciente);
        int getPersonalMedico();
        double getPresupuestoAnual();
        void agregarTurno(Turno* turno);
        void agregarPaciente(Paciente* paciente);

        // lista de espera
        void agregarPacienteListaEspera(string dni);
        void cambiarPrioridadPaciente(string dni, int nuevaPrioridad);
        Paciente* extraerPacienteListaEspera();
};




#endif