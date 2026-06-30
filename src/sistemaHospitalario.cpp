#include"sistemaHospitalario.h"
#include<iostream>
using namespace std;
        SistemaHospitalario::SistemaHospitalario(int cantidad) : listaHospitales(cantidad) {
        }
        void SistemaHospitalario::consultarInformacionHospital(string codHospital){
            Hospital* hospital = listaHospitales.buscar(codHospital);
            if (hospital == nullptr)
            {
                cout<<"No se encontro el hospital"<<endl;
                return;
            }
            cout<<hospital->mostrarInformacion()<<endl;
        }
        void SistemaHospitalario::agregarHospital(Hospital* hospital){
            listaHospitales.insertar(hospital);
            grafoHospitales.agregarVertice(hospital->getCodigoHospital());
            //agregar al txt
            
        }
        void SistemaHospitalario::eliminarHospital(string codigoHospital){
           Hospital* hospital = listaHospitales.buscar(codigoHospital);
           if (hospital == nullptr)
           {
               cout<<"No se encontro el hospital"<<endl;
               return;
           } 
           //luego de derivar etc etc
           listaHospitales.borrar(codigoHospital);
           grafoHospitales.eliminarVertice(codigoHospital);
           delete hospital;
            //eliminar hospital de memoria
        }



        void SistemaHospitalario::listarHospitales(int opcion){
            Lista<Hospital*> hospitales;
            for(int i=0; i<listaHospitales.size(); i++){
                Hospital* hospital = listaHospitales.obtenerHospitalCelda(i);
                if (hospital != nullptr){
                    hospitales.alta(hospital);
                }
            }
            insertionSort(hospitales, opcion);
            for(int i=1; i<=hospitales.obtenerLargo(); i++){
                Hospital* hospital = hospitales.consulta(i);
                cout<<hospital->mostrarInformacion()<<endl;
            }
        }

        void SistemaHospitalario::listarHospitalesPorEspecialidad(string especialidad){
            Lista<Hospital*> hospitales;
            for(int i=0; i<listaHospitales.size(); i++){
                Hospital* hospital = listaHospitales.obtenerHospitalCelda(i);
                if (hospital != nullptr && hospital->tieneEspecialidad(especialidad)){
                    hospitales.alta(hospital);
                }
            }
            insertionSort(hospitales, 4);
            for(int i=1; i<=hospitales.obtenerLargo(); i++){
                Hospital* hospital = hospitales.consulta(i);
                cout<<hospital->mostrarInformacion()<<endl;
            }
        }





        //lista SistemaHospitalario::calcularRutaDerivacion(Hospital origen, Hospital destino);
        Lista<Hospital*> SistemaHospitalario::hospitalesConSobrecarga(){
        //Dijkstra
        }
        void SistemaHospitalario::listarTurnosMedico(int idMedico){
            //deberia ir en hospital?
        }
        void SistemaHospitalario::listarTurnosPaciente(int idPaciente){
            //deberia ir en hospital?
        }
        Lista<Hospital*> SistemaHospitalario::hospitalesPorEspecialidad(string especialidad){
            Lista<Hospital*> hospitales;
        }

        void SistemaHospitalario::verGrafoHospitales(){
            grafoHospitales.verGrafo();
        }

        void SistemaHospitalario::conectarHospitales(string origen, string destino, int tiempo){
            grafoHospitales.agregarArista(origen, destino, tiempo);
        }
        
        void SistemaHospitalario::dijkstra(string origen, string destino){
            grafoHospitales.dijkstra(origen, destino);
        }

        bool SistemaHospitalario::compararHospitales(Hospital* h1, Hospital* h2, int opcion){
            switch (opcion)
            {
            case 1: //capacidad de camas
                return h1->getCapacidadCamas() < h2->getCapacidadCamas();
            case 2: //cantidad de personal medico
                return h1->getPersonalMedico() < h2->getPersonalMedico();
            case 3: //presupuesto anual
                return h1->getPresupuestoAnual() < h2->getPresupuestoAnual();
            case 4: // por disponibilidad de camas
                return h1->cantidadDeCamasDisponibles() < h2->cantidadDeCamasDisponibles();
            }
        }

        void SistemaHospitalario::insertionSort(Lista<Hospital*>& hospitales, int opcion){// va con referencia para trabajar sobre la lista original
            int largo = hospitales.obtenerLargo();
            for(int i=2; i<=largo; i++){
                Hospital* hospital = hospitales.consulta(i);
                int j = i - 1;
                while(j >= 1 && compararHospitales(hospitales.consulta(j), hospital, opcion)){
                    hospitales.consulta(j + 1) = hospitales.consulta(j);
                    j--;
                }
                hospitales.consulta(j + 1) = hospital;
            }
        }