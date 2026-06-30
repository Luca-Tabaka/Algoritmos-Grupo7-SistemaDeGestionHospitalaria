#include"tablaHash.h"
using namespace std;

TablaHash::TablaHash(int cap){
    int size = primerPrimoSuperior(cap/0.8);
    capacidad = size;
    tabla = new CeldaHash[size];
}

int TablaHash::hash(string clave){
    int c2 = (int) clave[1];
    int c3 = (int) clave[2];

    return((c2 * 128 + c3) % capacidad);
}

void TablaHash::vaciar(){
    for(int i = 0; i < capacidad;i++){
        Hospital* hos = tabla[i].getHospital();
        if( hos != nullptr){
            delete(hos);
        }
    }
}

TablaHash::~TablaHash()
{
    vaciar();
    delete[] tabla;
}

void TablaHash::insertar(Hospital* hos){
    string clave = hos-> getCodigoHospital();
    int pos = hash(clave);
    int inicio = pos;
    while(tabla[pos].getHospital() != nullptr){
        pos = (pos + 1) % capacidad;
        if(pos == inicio){
            cout<<"Tabla llena, no se pudo insertar un nuevo hospital";
            return;
        }
    }
    tabla[pos].addHospital(hos);
}
Hospital* TablaHash::buscar(string clave){
    int pos = hash(clave);
    int inicio = pos;

    while(tabla[pos].getEstado()){//mientras encuentre posiciones que estan/fueron ocupadas sigue
        if(tabla[pos].getHospital() != nullptr &&  tabla[pos].getHospital()->getCodigoHospital() == clave){//si encuentra el hospital, lo devuelve
            return tabla[pos].getHospital();
        }
        pos = (pos+1) % capacidad;
        if(pos == inicio){//si vuelve a inicio, la tabla esta llena y no lo encontró. devuelve nullptr
            return nullptr;
        }
    }   
    return nullptr;
}

void TablaHash::borrar(string clave){
    int pos = hash(clave);
    int inicio = pos;
    while(tabla[pos].getEstado()){//mientras encuentre posiciones que estan/fueron ocupadas sigue
        if(tabla[pos].getHospital() != nullptr &&  tabla[pos].getHospital()->getCodigoHospital() == clave){//si encuentra el hospital, lo elimina
            tabla[pos].borrar();
            return;
        }
        pos = (pos+1) % capacidad;
        if(pos == inicio){//si vuelve a inicio, la tabla esta llena y no lo encontró. devuelve nullptr
            return;
        }
    }
    return;//si encuentra una posicion vacia y no lo encontro, termina.
}
Hospital* TablaHash::obtenerHospitalCelda(int pos){
    if(pos < 0 || pos >= capacidad){
        return nullptr;
    }
    return tabla[pos].getHospital();
}

int TablaHash::size(){
    return capacidad;
}

int TablaHash::primerPrimoSuperior(int num){
    while(!esPrimo(num)){
        num++;
    }
    return num;
}

bool TablaHash::esPrimo(int num){
    if(num == 1) return false;
    if(num == 2) return true;
    if(num%2 == 0)return false;
    for(int i = 3;i*i <= num; i+=2){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}