#include"tablaHash.h"
TablaHash::TablaHash(int size){
    capacidad = size;
    tabla = new CeldaHash[size];
}

int TablaHash::hash(std::string clave){
    int c1 = (int) clave[1];
    int c2 = (int) clave[2];

    return((c1 * 128 + c2) % capacidad);
}

TablaHash::~TablaHash()
{
    delete[] tabla;
}

void TablaHash::insertar(Hospital* hos){
    std::string clave = hos-> getCodigoHospital();
    int pos = hash(clave);
    int inicio = pos;
    while(tabla[pos].getHospital() != nullptr){
        pos = (pos + 1) % capacidad;
        if(pos == inicio){
            std::cout<<"Tabla llena, no se pudo insertar un nuevo hospital";
            return;
        }
    }
    tabla[pos].addHospital(hos);
}
Hospital* TablaHash::buscar(std::string clave){
    int pos = hash(clave);
    int inicio = pos;
    CeldaHash actual = tabla[pos];
    while(actual.getEstado()){//mientras encuentre posiciones que estan/fueron ocupadas sigue
        if(actual.getHospital() != nullptr &&  actual.getHospital()->getCodigoHospital() == clave){//si encuentra el hospital, lo devuelve
            return actual.getHospital();
        }
        pos = (pos+1) % capacidad;
        if(pos == inicio){//si vuelve a inicio, la tabla esta llena y no lo encontró. devuelve nullptr
            return nullptr;
        }
        actual = tabla[pos];
    }   
    return nullptr;
}