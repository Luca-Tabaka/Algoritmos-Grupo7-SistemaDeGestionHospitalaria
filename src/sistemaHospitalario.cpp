#include"sistemaHospitalario.h"
#include<iostream>
using namespace std;
        SistemaHospitalario::SistemaHospitalario(int cantidad) : listaHospitales(cantidad) {
        }

        //-------------------Hospitales-----------------------------------
        void SistemaHospitalario::consultarInformacionHospital(string codHospital){
            Hospital* hospital = listaHospitales.buscar(codHospital);
            if (hospital == nullptr)
            {
                cout<<"No se encontro el hospital"<<endl;
                return;
            }
            cout<<hospital->mostrarInformacion()<<endl;
        }

        Hospital* SistemaHospitalario::getHospital(string codHospital){
            Hospital* hospital = listaHospitales.buscar(codHospital);
            return hospital;
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



        void SistemaHospitalario::listarHospitales(int opcion){//opciones: 1 = camas totales, 2 = personal medico, 3 = presupuesto, 4 = disponibilidad de camas
            Lista<Hospital*> hospitales;
            for(int i=0; i<listaHospitales.size(); i++){
                Hospital* hospital = listaHospitales.obtenerHospitalCelda(i);
                if (hospital != nullptr){
                    hospitales.alta(hospital);
                }
            }//se cargan los hospitales de la listaHospitales

            insertionSort(hospitales, opcion);//se ordenan con insertion sort dada la opcion

            for(int i=1; i<=hospitales.obtenerLargo(); i++){
                Hospital* hospital = hospitales.consulta(i);
                cout<<hospital->mostrarInformacion()<<endl;
            }// se imprimen los hospitales
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






        Lista<Hospital*> SistemaHospitalario::hospitalesConSobrecarga(){
            
        }
        void SistemaHospitalario::listarTurnosMedico(int idMedico){
            //deberia ir en hospital?
        }
        void SistemaHospitalario::listarTurnosPaciente(int idPaciente){
            //deberia ir en hospital?
        }
        Lista<Hospital*> SistemaHospitalario::hospitalesPorEspecialidad(string especialidad){
            Lista<Hospital*> hospitales;
            for(int i = 1;i <= listaHospitales.size();i++){
                Hospital* actual = listaHospitales.obtenerHospitalCelda(i);
                if(actual != nullptr && actual->tieneSobrecarga()){
                    hospitales.alta(actual);
                }
            }

            return hospitales;
        }

        //-------------------Grafos------------------------------------------------------------------------------
        void SistemaHospitalario::verGrafoHospitales(){
            grafoHospitales.verGrafo();
        }

        void SistemaHospitalario::conectarHospitales(string origen, string destino, int tiempo){
            grafoHospitales.agregarArista(origen, destino, tiempo);
        }
        
        void SistemaHospitalario::dijkstra(string origen, string destino){
            grafoHospitales.dijkstra(origen, destino);
        }

        //lista SistemaHospitalario::calcularRutaDerivacion(Hospital origen, Hospital destino);


        //-------------------Diagnosticos------------------------------------------------------------------------------
        void SistemaHospitalario::insertarDiagnostico(string diag, int frec){
            if(!diagnosticos.existeDiagnostico(diag)){
                diagnosticos.insertar(diag,frec);
            }
            else{
                cout<<"El diagnostico que ingresó ya tiene una frecuencia asignada"<<endl;
            }
        }
        void SistemaHospitalario::insertarDiagnostico(string diag){
            if(!diagnosticos.existeDiagnostico(diag)){
                diagnosticos.insertar(diag,1);
            }
            else{
                cout<<"El diagnostico que ingresó ya tiene una frecuencia asignada"<<endl;
            }
        }

        void SistemaHospitalario::incrementarFrecuencia(string diag){
            if(!diagnosticos.existeDiagnostico(diag)){
                cout<<"El diagnostico que ingresó no existe, no se puede incrementar frecuencia"<<endl;
            }
            else{
                diagnosticos.aumentarFrecuencia(diag);
            }
        }
        void SistemaHospitalario::diagnosticoMasFrecuente(){
            NodoArbol* diag = diagnosticos.diagnosticoMasFrecuente();
            if(diag == nullptr){
                cout<<"El arbol está vacio, no hay diagnostico mas frecuente";
                return;
            }
            cout<<"Diagnostico mas frecuente: " << diag->getDiagnostico() << " que afecta a: " << diag->getFrecuencia() << " Pacientes"<<endl;
        }
        void SistemaHospitalario::listarDiagnosticos(){
            diagnosticos.mostrarDiagnosticos();
        }
        void SistemaHospitalario::eliminarDiagnostico(string diag){
            diagnosticos.eliminarDiagnostico(diag);
        }
        void SistemaHospitalario::arbolDesbalanceado(){
            if(diagnosticos.estaDesbalanceado()){
                cout<<"Arbol desbalanceado"<<endl;
            }
            else{
                cout<<"Arbol balanceado"<<endl;
            }
        }



        //-------------------Auxiliares-----------------------------------
        bool SistemaHospitalario::compararHospitales(Hospital* h1, Hospital* h2, int opcion){
            switch (opcion)
            {
            case 1: //capacidad de camas
                return h1->getCapacidadCamas() < h2->getCapacidadCamas();
            case 2: //cantidad de personal medico
                return h1->getPersonalMedico() < h2->getPersonalMedico();
            case 3: //presupuesto anual
                return h1->getPresupuestoAnual() < h2->getPresupuestoAnual();
            case 4: // disponibilidad de camas
                return h1->cantidadDeCamasDisponibles() < h2->cantidadDeCamasDisponibles();
            }
        }

        void SistemaHospitalario::insertionSort(Lista<Hospital*>& hospitales, int opcion){// va con referencia para trabajar sobre la lista original
            int largo = hospitales.obtenerLargo();
            for(int i=2; i<=largo; i++){//arranca del segundo porque el primero ya esta ordenado, cada iteracion ordena un hospital
                Hospital* hospital = hospitales.consulta(i);//elige el primer hospital no ordenado
                int j = i - 1;//Compara desde la posicion anterior
                while(j >= 1){//Mientras no encuentra su posicion
                    Hospital* actual = hospitales.consulta(j);//guarda el hospital que se compara en esta iteracion para evitar consultar 2 veces
                    if(!compararHospitales(actual, hospital, opcion)){//si se encuentra la posicion correcta, corta
                        break;
                    } 
                    hospitales.consulta(j + 1) = actual; //si no, desplaza hospital a la derecha. Como devuelve hospital por referencia, se puede asignar.
                    j--;
                }
                hospitales.consulta(j + 1) = hospital;//Lo inserta en la posicion que corresponde
            }
        }