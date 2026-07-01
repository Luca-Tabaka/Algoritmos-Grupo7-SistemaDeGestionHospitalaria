#include"sistemaHospitalario.h"
#include<iostream>
#include<ctime>
#include <fstream>
using namespace std;
        SistemaHospitalario::SistemaHospitalario(int cantidad) : listaHospitales(cantidad) {
        }

        SistemaHospitalario::~SistemaHospitalario(){
            for (int i = 0; i < listaHospitales.size(); i++)
            {
                Hospital* h = listaHospitales.obtenerHospitalCelda(i);
                if (h!=nullptr)
                {
                    delete h;
                }
            }
            

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

        void SistemaHospitalario::agregarEspecialidadesHospital(string codHospital){
            Hospital* hospital = listaHospitales.buscar(codHospital);
            if (hospital == nullptr)
            {
                cout<<"No se encontro el hospital"<<endl;
                return;
            }            
            string especialidad;
            while(true){
                cout<<"Ingrese la especialidad a agregar (con x termina)"<<endl;
                cin>>especialidad;
                if (especialidad!="x")
                {
                    hospital->agregarEspecialidad(especialidad);
                }else{
                    break;
                }
            }
        }
        void SistemaHospitalario::eliminarHospital(string codigoHospital){
           Hospital* hospital = listaHospitales.buscar(codigoHospital);
           if (hospital == nullptr)
           {
               cout<<"No se encontro el hospital"<<endl;
               return;
           }
            reasignarPacientes(codigoHospital);
           listaHospitales.borrar(codigoHospital);
           grafoHospitales.eliminarVertice(codigoHospital);
           delete hospital;
        }



        void SistemaHospitalario::listarHospitales(int opcion){//opciones: 1 = camas totales, 2 = personal medico, 3 = presupuesto, 4 = disponibilidad de camas
            Lista<Hospital*> hospitales;
            for(int i=0; i<listaHospitales.size(); i++){
                Hospital* hospital = listaHospitales.obtenerHospitalCelda(i);
                if (hospital != nullptr){
                    hospitales.alta(hospital);
                }
            }//se cargan los hospitales de la listaHospitales

            if (hospitales.esVacia())
            {
                cout<<"No se encontraron hospitales a listar"<<endl;
                return;
            }
            
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
            if (hospitales.esVacia())
            {
                cout<<"No se encontraron hospitales con esa especialidad."<<endl;
                return;
            }
            
            insertionSort(hospitales, 4);
            for(int i=1; i<=hospitales.obtenerLargo(); i++){
                Hospital* hospital = hospitales.consulta(i);
                cout<<hospital->mostrarInformacion()<<endl;
            }
        }
        void SistemaHospitalario::hospitalesConSobrecarga(string fecha){
            cout<<"Hospitales con sobrecarga: "<<endl;
            bool haySobrecarga = false;
            for(int i = 1;i <= listaHospitales.size();i++){
                Hospital* actual = listaHospitales.obtenerHospitalCelda(i);
                if(actual != nullptr && actual->tieneSobrecarga(fecha)){
                    cout<< actual->mostrarInformacion();
                    haySobrecarga = true;
                }
            }
            if(!haySobrecarga){
            cout<<"No hay hospitales con sobrecarga"<<endl;
            }
        }


        void SistemaHospitalario::reasignarPacientes(string origen){
            Lista<string> hospitales = hospitalesMasCercanos(origen);
            Hospital* hospital = getHospital(origen);
            if(hospitales.esVacia()){
                cout<<"El hospital no tiene conexion con otros hospitales"<<endl;
                return;
            }
            int pos = 1;
            Hospital* actual = listaHospitales.buscar(hospitales.consulta(1));
            while(hospital->cantidadPacientes()>0){
                if(actual->cantidadDeCamasDisponibles() > 0){
                    trasladarPaciente(origen,actual->getCodigoHospital());
                }
                else{
                    pos++;
                    if( pos > hospitales.obtenerLargo()){
                        cout << "No hay mas hospitales disponibles" << endl;
                        return;
                    }
                    actual = listaHospitales.buscar(hospitales.consulta(pos));
                }
                
            }

        }

        void SistemaHospitalario::trasladarPaciente(string origen, string destino){
            Hospital* o = getHospital(origen);
            Hospital* d = getHospital(destino);
            Paciente* paciente = o->quitarPaciente();
            paciente->setCodigoHospital(destino);
            d->agregarPaciente(paciente);
            //cambiar paciente en archivo txt
        }

        //-------------------Grafos------------------------------------------------------------------------------
        void SistemaHospitalario::verGrafoHospitales(){
            grafoHospitales.verGrafo();
        }

        void SistemaHospitalario::conectarHospitales(string origen, string destino, int tiempo){
            grafoHospitales.agregarArista(origen, destino, tiempo);
        }
        
        void SistemaHospitalario::calcularCaminoHospitales(string origen, string destino){
            grafoHospitales.calcularCamino(origen, destino);
        }

        Lista<string> SistemaHospitalario::hospitalesMasCercanos(string origen){
            return grafoHospitales.hospitalesMasCercanos(origen);
        }
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
                diagnosticos.aumentarFrecuencia(diag);
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
            default:
                return false;
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

    void SistemaHospitalario::insertarDerivacionesATXT(){
            grafoHospitales.cargarDerivacionesATXT();
        }

    void SistemaHospitalario::agregarDerivacionesDesdeTXT(){
        ifstream derivaciones("archivosDeEntrada/derivaciones.txt");
        if (derivaciones.fail()) {
            cerr << "No se pudo abrir el archivo de derivaciones." << endl;
            return;
        }       
        
        string origen,destino;
        int tiempo;
        while(derivaciones>>origen>>destino>>tiempo){
            grafoHospitales.agregarArista(origen,destino,tiempo);
        }
    }

    void SistemaHospitalario::agregarPacientesDesdeTXT(){
        ifstream pacientes("archivosDeEntrada/pacientes.txt");
        if (pacientes.fail()) {
            cerr << "No se pudo abrir el archivo de pacientes." << endl;
            return;
        }            
        //HGA 8001 30123456 20250310 Fractura 3 72.5
        //Paciente(string codigoHospital, int idPaciente, string dni, string fechaIngreso, string diagnostico, int prioridad, float peso)
        string codHospital,dni,fecha,diagnostico;
        int id,prioridad;
        float peso;
        while (pacientes>>codHospital>>id>>dni>>fecha>>diagnostico>>prioridad>>peso)
        {
            Hospital* h = listaHospitales.buscar(codHospital);
            Paciente* paciente = new Paciente (codHospital,id, dni, fecha, diagnostico, prioridad, peso);
            h->agregarPaciente(paciente);
            insertarDiagnostico(diagnostico);
        }
    }

    void SistemaHospitalario::agregarTurnosDesdeTXT(){
        ifstream turnos("archivosDeEntrada/turnos.txt");
        if (turnos.fail()) {
            cerr << "No se pudo abrir el archivo de turnos." << endl;
            return;
        }            
        int id,idp,idm, tiempo;
        string codh, fecha, especialidad;
        while (turnos>>codh>>id>>idp>>idm>>fecha>>especialidad>>tiempo)
        {
            Hospital* h = listaHospitales.buscar(codh);
            Turno* turno = new Turno(id, codh, idp, idm, fecha, especialidad, tiempo);
            h->agregarTurno(turno);
        }
    }    
        int SistemaHospitalario::obtenerLargoTablaHash(){
            return listaHospitales.size();
        }

        Hospital* SistemaHospitalario::obtenerHospitalCelda(int pos){
            return listaHospitales.obtenerHospitalCelda(pos);
        }

    void SistemaHospitalario::agregarInsumosDesdeTXT(){
        ifstream insumos("archivosDeEntrada/insumos.txt");
        if (insumos.fail()) {
            cerr << "No se pudo abrir el archivo de insumos." << endl;
            return;
        }            
        //int id, string nom, string codHos,float p,int pri
        int id,pri;
        string nombre, codh;
        float peso;
        while (insumos>>id>>nombre>>codh>>peso>>pri)
        {
            Hospital* h = listaHospitales.buscar(codh);
            Insumo* insumo = new Insumo(id,nombre,codh,peso,pri);
            h->agregarInsumo(insumo);
        }
    }    
 