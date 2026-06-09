#ifndef INSUMO_H_INCLUDED
#define INSUMO_H_INCLUDED
#include<string>

class Insumo{
    private:
        int idInsumo;
        std::string nombre;
        std::string codigoHospital;
        float peso;
        int prioridad;
    public:
        int getId();
        std::string getNombre();
        std::string getCodigoHospital();
        float getPeso();
        int getPrioridad();
};
#endif