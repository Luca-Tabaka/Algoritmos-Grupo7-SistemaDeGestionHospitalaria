#include"insumo.h"

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