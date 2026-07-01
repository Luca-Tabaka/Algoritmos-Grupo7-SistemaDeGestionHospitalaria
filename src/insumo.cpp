#include"insumo.h"
        Insumo::Insumo(int id, string nom, string codHos,float p,int pri){
            idInsumo = id;
            nombre = nom;
            codigoHospital = codHos;
            peso = p;
            prioridad = pri;
        }
    int Insumo::getId(){
        return idInsumo;
    }
    string Insumo::getNombre(){
        return nombre;
    }
    string Insumo::getCodigoHospital(){
        return  codigoHospital;
    }
    float Insumo::getPeso(){
        return peso;
    }
    int Insumo::getPrioridad(){
        return prioridad;
    }