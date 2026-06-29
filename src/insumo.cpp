#include"insumo.h"

        Insumo::Insumo(int id, std::string nom, std::string codHos,float p,int pri){
            idInsumo = id;
            nombre = nom;
            codigoHospital = codHos;
            peso = p;
            prioridad = pri;
        }
    int Insumo::getId(){
        return idInsumo;
    }
    std::string Insumo::getNombre(){
        return nombre;
    }
    std::string Insumo::getCodigoHospital(){
        return  codigoHospital;
    }
    float Insumo::getPeso(){
        return peso;
    }
    int Insumo::getPrioridad(){
        return prioridad;
    }