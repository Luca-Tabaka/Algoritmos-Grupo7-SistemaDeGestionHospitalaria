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

        //ABB diagnosticos;
    public:
        SistemaHospitalario(int cantidad);
        void consultarInformacionHospital(string codHospital);
        void agregarHospital(Hospital* hospital);
        void eliminarHospital(string codigoHospital);
        void listarHospitales(int opcion);
        void listarHospitalesPorEspecialidad(string especialidad);
        //lista calcularRutaDerivacion(string HospitalOrigen, string Hospitaldestino);
        Lista<Hospital*> hospitalesConSobrecarga();
        void listarTurnosMedico(int idMedico);
        void listarTurnosPaciente(int idPaciente);
        Lista<Hospital*> hospitalesPorEspecialidad(string especialidad);
        void verGrafoHospitales();
        void conectarHospitales(string origen, string destino, int tiempo);
        void dijkstra(string origen, string destino);
};


#endif