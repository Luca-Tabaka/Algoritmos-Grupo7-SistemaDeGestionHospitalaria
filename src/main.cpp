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

    sistema.agregarHospital(new Hospital("H001", "Hospital A", "Ciudad A", 100, Lista<std::string>(), 50, 1000000.0));
    sistema.agregarHospital(new Hospital("H002", "Hospital B", "Ciudad B", 150, Lista<std::string>(), 75, 1500000.0));
    sistema.agregarHospital(new Hospital("H003", "Hospital C", "Ciudad C", 200, Lista<std::string>(), 100, 2000000.0));

    sistema.conectarHospitales("H001", "H002", 10);
    sistema.conectarHospitales("H001", "H003", 5);
    sistema.conectarHospitales("H002", "H003", 3);

    sistema.verGrafoHospitales();
    sistema.dijkstra("H001", "H002");

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