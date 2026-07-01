#ifndef INSUMO_H_INCLUDED
#define INSUMO_H_INCLUDED
#include<string>
using namespace std;

class Insumo{
    private:
        int idInsumo;
        string nombre;
        string codigoHospital;
        float peso;
        int prioridad;
    public:
        Insumo(int id, string nom, string codHos,float p,int pri);
        int getId();
        string getNombre();
        string getCodigoHospital();
        float getPeso();
        int getPrioridad();
};
#endif