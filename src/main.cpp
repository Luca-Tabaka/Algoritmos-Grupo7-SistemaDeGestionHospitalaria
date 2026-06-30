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


int menuPrincipal(){
    int eleccion;
    cout<<"Menu de gestion de hospitales: "<<endl;
    cout<<"1. Mostrar informacion de un hospital"<<endl;
    cout<<"2. Agregar hospital al sistema"<<endl;
    cout<<"3. Eliminar hospital existente"<<endl;
    cout<<"4. Listar todos los hospitales por especificacion"<<endl;
    cout<<"5. Calcular ruta de derivacion entre dos hospitales"<<endl;
    cout<<"6. Buscar hospitales por especialidad"<<endl;
    cout<<"7. Listar hospitales con sobrecarga"<<endl;
    cout<<"8. Gestionar Hospital"<<endl;
    cout<<"8. Gestionar diagnosticos"<<endl;
    cout<<"0. Volver"<<endl;
    cin>>eleccion;
    return eleccion;
}


int menuHospital(){
    int eleccion;
    cout<<"Menu de sistema hospitalario: "<<endl;
    cout<<"1. Gestionar pacientes"<<endl;
    cout<<"2. Gestionar insumos"<<endl;
    cout<<"0. Volver"<<endl;
    cin>>eleccion;
    return eleccion;    
}



int menuGestionDePacientesyTurnos(){
    int eleccion;
    cout<<"Menu de gestion de pacientes y turnos: "<<endl;
    cout<<"1. Calcular la cantidad de pacientes atendidos en un rango de fechas"<<endl;
    cout<<"2. Listar turnos de un paciente"<<endl;
    cout<<"3. Listar turnos de un medico"<<endl;
    cout<<"4. Agregar paciente a lista de espera"<<endl;
    cout<<"5. Atender paciente en lista de espera"<<endl;
    cout<<"6. Cambiar la prioridad de un paciente"<<endl;
    cout<<"0. Volver"<<endl;
    cin>>eleccion;
    return eleccion;
}

int menuGestionDeDiagnosticos(){
    int eleccion;
    cout<<"Menu de gestion de diagnosticos: "<<endl;
    cout<<"1. Agregar diagnostico"<<endl;
    cout<<"2. Eliminar diagnostico"<<endl;
    cout<<"3. Listar diagnosticos"<<endl;
    cout<<"4. Incrementar frecuencia de diagnostico"<<endl;
    cout<<"5. Diagnostico mas frecuente"<<endl;
    cout<<"6. Ver balance de arbol de diagnosticos"<<endl;
    cout<<"0. Volver"<<endl;
    cin>>eleccion;
    return eleccion;
}


int menuInsumos(){
    int eleccion;
    cout<<"Menu de gestion de insumos: "<<endl;
    cout<<"1. Calcular carga de ambulancia"<<endl;
    cout<<"2. Listar insumos"<<endl;
    cout<<"3. Comparar funciones de backtracking"<<endl;
    cout<<"0. Volver"<<endl;
    cin>>eleccion;
    return eleccion;
}

void ejecucionMenuPrincipal(SistemaHospitalario& sistemaPrincipal){
int opcion;
    do{
        opcion = menuPrincipal();
    switch (opcion)
    {    case 1:{
            string codHospital;
            cout<<"Ingrese el codigo del hospital"<<endl;
            cin>>codHospital;
            sistemaPrincipal.consultarInformacionHospital(codHospital);
            break;
        }
        case 2:{
            //(string codigoHospital, string nombre,  string ciudad, int capacidadCamas, Lista<string> especialidades,int personalMedico,double presupuestoAnual)
            string codHospital, nombre, ciudad;
            int camas, personal;
            double presupuesto;
            cout<<"Ingrese el codigo de hospital"<<endl;
            cin>>codHospital;
            cout<<"Ingrese el nombre del hospital"<<endl;
            cin>>nombre;
            cout<<"Ingrese la ciudad"<<endl;
            cin>>ciudad;
            cout<<"Ingrese la cantidad de camas"<<endl;
            cin>>camas;
            cout<<"Ingrese el cantidad de personal"<<endl;
            cin>>personal;
            cout<<"Ingrese el presupuesto anual"<<endl;
            cin>>presupuesto;
            sistemaPrincipal.agregarHospital(new Hospital(codHospital,nombre,ciudad,camas,Lista<string>(),personal,presupuesto));
            sistemaPrincipal.agregarEspecialidadesHospital(codHospital);
            break;
        }
        case 3:{
            string codHospital;
            cout<<"Ingrese el codigo del hospital"<<endl;
            cin>>codHospital;
            sistemaPrincipal.eliminarHospital(codHospital);
            break;
        }
            
        case 4:{
            int especificacion;
            cout<<"Ingrese la especificacion para listar hospitales (opciones: 1 = camas totales, 2 = personal medico, 3 = presupuesto, 4 = disponibilidad de camas)"<<endl;    
            cin>>especificacion; 
            sistemaPrincipal.listarHospitales(especificacion);   
            break;
        }
        case 5:{
            string origen;
            cout<<"Ingrese el codigo de hospital de origen"<<endl;   
            cin>>origen;
            string destino;
            cout<<"Ingrese el codigo de hospital de destino"<<endl;   
            cin>>destino;
            sistemaPrincipal.calcularCaminoHospitales(origen,destino);
            break;
        }

        case 6:{
            string especialidad;
            cout<<"Ingrese la especialidad para listar"<<endl;    
            cin>>especialidad; 
            sistemaPrincipal.listarHospitalesPorEspecialidad(especialidad);  
            break; 
        }
        case 7:{
            string fecha;
            cout<<"Ingrese la fecha para listar (AAAAMMDD)"<<endl;    
            cin>>fecha;             
            sistemaPrincipal.hospitalesConSobrecarga(fecha);
            break;
        }    
        case 8:{
            menuHospital();
            break;
        }    
        case 9:{
            menuGestionDeDiagnosticos();
            break;
            
        }
    case 0:
        cout<<"Salio del sistema"<<endl;
        break;
    default:
        cout<<"Opcion no valida, elija nuevamente."<<endl;
        break;
    }
} while (opcion != 0);
}


//Hospital
void ejecucionMenuHospital(SistemaHospitalario& sistemaPrincipal){
    string codHospital;
    cout<<"Ingrese el hospital a gestionar"<<endl;
    cin>>codHospital;
    Hospital* hospital = sistemaPrincipal.getHospital(codHospital);
    if (hospital==nullptr)
    {
        cout<<"No se encontro el hospital a gestionar."<<endl;
        return;
    }
    int opcion;
    do{
    opcion = menuHospital();
     switch (opcion)
     {
     case 1:{
         
         break;
     }
        
     
    case 0:
        cout<<"Volviendo al menu principal."<<endl;
        break;
    default:
        cout<<"Opcion no valida, elija nuevamente."<<endl;
        break;
     }   
    } while (opcion != 0);
    
}

void ejecucionMenuGestionDePacientesyTurnos(SistemaHospitalario& sistemaPrincipal, Hospital* hospital){
    int opcion;
    do{
    opcion = menuGestionDePacientesyTurnos();
     switch (opcion)
     {
     case 1:{
         
         break;
     }
        
     
    case 0:
        cout<<"Volviendo al menu de hospital."<<endl;
        break;
    default:
        cout<<"Opcion no valida, elija nuevamente."<<endl;
        break;
     }   
    } while(opcion != 0);
}
void ejecucionMenuInsumos(SistemaHospitalario& sistemaPrincipal, Hospital* hospital){
// fin hospital



    int opcion;
    do{
    opcion = menuInsumos();
     switch (opcion)
     {
     case 1:{
         
         break;
     }
        
     
    case 0:
        cout<<"Volviendo al menu de hospital."<<endl;
        break;
    default:
        cout<<"Opcion no valida, elija nuevamente."<<endl;
        break;
     }   
    } while(opcion != 0);
}

// fin hospital


void ejecucionMenuGestionDeDiagnosticos(SistemaHospitalario& sistemaPrincipal){
    int opcion;
    do{
    opcion = menuGestionDeDiagnosticos();
     switch (opcion)
     {
     case 1:{
        string diagnostico;
        cout<<"Ingrese un diagnostico:"<<endl;
        cin>>diagnostico;
        int frecuencia;
        cout<<"Ingrese la frecuencia:"<<endl;
        cin>>frecuencia;

        sistemaPrincipal.insertarDiagnostico(diagnostico,frecuencia);
        break;
     }

    case 2:
        
     
    case 0:
        cout<<"Volviendo al menu de hospital."<<endl;
        break;
    default:
        cout<<"Opcion no valida, elija nuevamente."<<endl;
        break;
     }   
    } while(opcion != 0);
}


int main(){
    SistemaHospitalario sistemaPrincipal(100);
    
    ejecucionMenuPrincipal(sistemaPrincipal);
}