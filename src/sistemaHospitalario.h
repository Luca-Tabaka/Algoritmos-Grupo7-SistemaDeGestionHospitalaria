#ifndef SISTEMAHOSPITALARIO_H_INCLUDED
#define SISTEMAHOSPITALARIO_H_INCLUDED
#include"turno.h"
#include"tablaHash.h"
#include"primitivas/lista.h"
#include"primitivas/Grafo.h"
#include"hospital.h"
#include "primitivas/arbol.h"
using namespace std;

class SistemaHospitalario{
    private:
        TablaHash listaHospitales;
        Arbol diagnosticos;
        Grafo grafoHospitales;
        bool compararHospitales(Hospital* h1, Hospital* h2, int opcion);
        void insertionSort(Lista<Hospital*>& hospitales, int opcion);
        void reasignarPacientes(string origen);
        void trasladarPaciente(string origen,string destino);

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
        void hospitalesConSobrecarga(string fecha);
        void agregarEspecialidadesHospital(string codHospital);
        int obtenerLargoTablaHash();
        Hospital* obtenerHospitalCelda(int pos);
        void agregarPacientesDesdeTXT();
        void agregarTurnosDesdeTXT();
        void agregarInsumosDesdeTXT();

        //grafos
        void verGrafoHospitales();
        void conectarHospitales(string origen, string destino, int tiempo);
        void calcularCaminoHospitales(string origen, string destino);
        Lista<string> hospitalesMasCercanos(string origen);
        void insertarDerivacionesATXT();
        void agregarDerivacionesDesdeTXT();

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