#ifndef TABLAHASH_H_
#define TABLAHASH_H_
#include"celdaHash.h"


class TablaHash{
    private:
        CeldaHash* tabla;
        int capacidad;
        int hash(std::string clave);
        int primerPrimoSuperior(int num);
        bool esPrimo(int num);
    public:
        TablaHash(int cap);
        ~TablaHash();
        void vaciar();
        void borrar(std::string clave);
        void insertar(Hospital* hospital);
        Hospital* buscar(std::string clave);
};


#endif