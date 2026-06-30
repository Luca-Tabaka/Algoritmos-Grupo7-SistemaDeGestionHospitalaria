#ifndef SISTEMAHOSPITALARIO_H_INCLUDED
#define SISTEMAHOSPITALARIO_H_INCLUDED
#include"turno.h"
#include"tablaHash.h"
#include"derivacion.h"
#include"primitivas/lista.h"
#include"primitivas/Grafo.h"
#include"hospital.h"
#include "primitivas/arbol.h"
using namespace std;

class SistemaHospitalario{
    private:
        TablaHash listaHospitales;
        Lista<Turno> turnos;
        Lista<Derivacion*> listaDerivaciones;
        Arbol diagnosticos;
        Grafo grafoHospitales;
        bool compararHospitales(Hospital* h1, Hospital* h2, int opcion);
        void insertionSort(Lista<Hospital*>& hospitales, int opcion);

    public:
        SistemaHospitalario(int cantidad);

        //hospitales
        Hospital* getHospital(string codHospital);
        void consultarInformacionHospital(string codHospital);
        void agregarHospital(Hospital* hospital);
        void eliminarHospital(string codigoHospital);
        void listarHospitales(int opcion);
        void listarHospitalesPorEspecialidad(string especialidad);
        //lista calcularRutaDerivacion(string HospitalOrigen, string Hospitaldestino);
        Lista<Hospital*> hospitalesConSobrecarga();
        Lista<Hospital*> hospitalesPorEspecialidad(string especialidad);

        //turnos
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(int idPaciente);

        //grafos
        void verGrafoHospitales();
        void conectarHospitales(string origen, string destino, int tiempo);
        void dijkstra(string origen, string destino);

        //diagnosticos
        void insertarDiagnostico(string diag, int frec);
        void insertarDiagnostico(string diag);//Inserta con valor 1
        void incrementarFrecuencia(string diag);
        void diagnosticoMasFrecuente();
        void listarDiagnosticos();
        void eliminarDiagnostico(string diag);
        void arbolDesbalanceado();

};


#endif