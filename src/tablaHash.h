#ifndef TABLAHASH_H_
#define TABLAHASH_H_
#include"celdaHash.h"


class TablaHash{
    private:
        CeldaHash* tabla;
        int capacidad;
        int hash(std::string clave);
    public:
        TablaHash(int cap);
        ~TablaHash();

        void insertar(Hospital* hospital);
        Hospital* buscar(std::string clave);
};


#endif