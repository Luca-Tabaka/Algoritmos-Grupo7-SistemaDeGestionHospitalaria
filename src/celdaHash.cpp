#include"celdaHash.h"

void CeldaHash::addHospital(Hospital* hos){
    hospital = hos;
    fueOcupada = true;
}

Hospital* CeldaHash::getHospital(){
    return hospital;
}

bool CeldaHash::getEstado(){
    return fueOcupada;
}