#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include<string>
#include"insumo.h"
#include"paciente.h"
#include "primitivas/lista.h"
#include "primitivas/nodo.h"
#include"turno.h"
#include"ambulancia.h"
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
        string semanaAnterior(string fecha);
        Paciente* obtenerPaciente(string dni);
        
    public:
        Hospital( string codigoHospital, string nombre,  string ciudad, int capacidadCamas, Lista<string> especialidades,int personalMedico,double presupuestoAnual);
        ~Hospital();
        
        //GETTERS
        string getNombre();
        string getCodigoHospital();
        string getCiudad();
        int getCapacidadCamas();
        int getPersonalMedico();
        double getPresupuestoAnual();
        Lista<string> getEspecialidades();



        string mostrarInformacion();
        int pacientesAtendidos(string fechaInicio, string fechaFin);
        int cantidadDeCamasDisponibles();
        int cantidadPacientes();
        bool tieneEspecialidad(string especialidad);
        bool tieneSobrecarga(string fecha);
        Paciente* quitarPaciente();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(string dniPaciente);

        void cargaDerivacion(int capacidadMax);
        void comparacionBacktracking(int capacidadMax);

        void agregarEspecialidad(string especialidad);
        void agregarTurno(Turno* turno);
        void agregarPaciente(Paciente* paciente);
        void agregarInsumo(Insumo* insumo);

        // lista de espera
        void agregarPacienteListaEspera(string dni);
        void cambiarPrioridadPaciente(string dni, int nuevaPrioridad);
        Paciente* extraerPacienteListaEspera();
};




#endif