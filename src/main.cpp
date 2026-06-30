#include "sistemaHospitalario.h"
#include "primitivas/grafo.h"
using namespace std; 
#include <iostream>
#include <fstream>


void agregarHospitalesDesdeTXT(TablaHash& listaHospitales) {
    ifstream hospitales("archivosDeEntrada/hospitales.txt");
    if (hospitales.fail()) {
        cerr << "No se pudo abrir el archivo de hospitales." << endl;
        return;
    }
    // armo variables para guardar los datos de la linea
    string codigo, nombre, ciudad, especialidades;
    int capacidadCamas, personalMedico;
    double presupuesto;
    //va leyendo el archivo hasta encontrar espacios y los agrega a las variables
    while(hospitales>>codigo>>nombre>>ciudad>>capacidadCamas>>especialidades>>personalMedico>>presupuesto){
        
        Hospital* hospital = new Hospital(codigo, nombre, ciudad, capacidadCamas, Lista<std::string>(), personalMedico, presupuesto);
        listaHospitales.insertar(hospital);

    }
}

void insertarHospitalesEnTxt(TablaHash& listaHospitales) {
    ofstream archivo("archivosDeEntrada/hospitales.txt", ios::app); 
    if (archivo.fail()) {
        cerr << "No se pudo abrir el archivo de hospitales." << endl;
        return;
    }

    for (int i = 0; i < listaHospitales.size(); i++) {
        Hospital* hos = listaHospitales.obtenerHospitalCelda(i);
        if (hos != nullptr) {
            archivo << hos->getCodigoHospital() << " " << hos->getNombre() << " " << hos->getCiudad() << " " << hos->getCapacidadCamas() << " " << hos->getPersonalMedico() << " " << hos->getPresupuestoAnual() << endl;
        }
    }
    archivo.close();
}


int main(){
    SistemaHospitalario sistema(100);
/* 
    sistema.agregarHospital(new Hospital("H001", "Hospital A", "Ciudad A", 100, Lista<std::string>(), 50, 1000000.0));
    sistema.agregarHospital(new Hospital("H002", "Hospital B", "Ciudad B", 150, Lista<std::string>(), 75, 1500000.0));
    sistema.conectarHospitales("H001", "H002", 10);
    sistema.verGrafoHospitales(); */
    
    Paciente* paciente1 = new Paciente("H001", 101, "12345678", "20250304", "Consultas", 1, 70.5);
    Paciente* paciente2 = new Paciente("H001", 102, "87654321", "20250305", "Examen", 2, 65.0);


    // creacion de listas para hospital
    Lista<string> especialidad;
    especialidad.alta("Cardiologia");
    especialidad.alta("Neurologia");
    Lista<string> especialidad2;
    especialidad2.alta("Pediatria");
    Lista<string> especialidad3;
    especialidad3.alta("Cardiologia");
    especialidad3.alta("Pediatria");

    Hospital *hospital1 = new Hospital("H001", "Hospital A", "Ciudad A", 100, especialidad, 50, 1000000.0);

    hospital1->agregarPaciente(paciente1);
    hospital1->agregarPaciente(paciente2);

    sistema.agregarHospital(hospital1);
    sistema.agregarHospital(new Hospital("H002", "Hospital B", "Ciudad B", 150, especialidad2, 75, 1500000.0));
    sistema.agregarHospital(new Hospital("H003", "Hospital C", "Ciudad C", 200, especialidad3, 100, 2000000.0));

    sistema.conectarHospitales("H001", "H002", 10);
    sistema.conectarHospitales("H001", "H003", 5);
    sistema.conectarHospitales("H002", "H003", 3);


    hospital1->agregarTurno(new Turno(1, "H001", 101, 201, "20250506", "Cardiologia", 30));
    hospital1->agregarTurno(new Turno(2, "H001", 101, 201, "20250708", "Pediatria", 60));
    hospital1->agregarTurno(new Turno(3, "H001", 101, 201, "20251008", "Control", 60));


    hospital1->agregarTurno(new Turno(2, "H001", 102, 202, "20250507", "Neurologia", 45));

    hospital1->listarTurnosPaciente("87654321");

    sistema.verGrafoHospitales();

    sistema.dijkstra("H001", "H002");
    //hospital1->agregarTurno(new Turno(3, "H001", 103, 203, "20270508", "Pediatria", 60));
    
    //cout << hospital1->pacientesAtendidos("20250101", "20260512") << endl;
    //sistema.consultarInformacionHospital("H001");

/*     sistema.verGrafoHospitales();
    sistema.eliminarHospital("H001");
    sistema.verGrafoHospitales(); */

    //sistema.listarHospitales(1); // Ordenar por capacidad de camas
    //sistema.listarHospitalesPorEspecialidad("Pediatria");
}

/* int main() {
    TablaHash listaHospitales(100);
    Grafo grafoHospitales;
    Hospital* hospital1 = new Hospital("H001", "Hurlingham", "Ciudad A", 100, Lista<std::string>(), 50, 1000000.0);
    Hospital* hospital2 = new Hospital("H002", "Moron", "Ciudad B", 150, Lista<std::string>(), 75, 1500000.0);

    grafoHospitales.agregarVertice(hospital1->getCodigoHospital());
    grafoHospitales.agregarVertice(hospital2->getCodigoHospital());

    grafoHospitales.agregarArista(hospital1->getCodigoHospital(), hospital2->getCodigoHospital(), 10);
    grafoHospitales.agregarArista(hospital2->getCodigoHospital(), hospital1->getCodigoHospital(), 10);

    grafoHospitales.verGrafo();

    listaHospitales.insertar(hospital1);
    listaHospitales.insertar(hospital2);

    insertarHospitalesEnTxt(listaHospitales);
    agregarHospitalesDesdeTXT(listaHospitales);
    for (int i = 0; i < listaHospitales.size(); i++) {

        Hospital* hos = listaHospitales.obtenerHospitalCelda(i);

        

        if (hos != nullptr) {

            cout << hos->mostrarInformacion() << endl;

        }

    }
return 0;
}
 */