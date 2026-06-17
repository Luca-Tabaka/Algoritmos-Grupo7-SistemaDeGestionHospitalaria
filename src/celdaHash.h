#ifndef CELDAHASH_H_
#define CELDAHASH_H_
#include "hospital.h"
class CeldaHash{
    private:
        Hospital* hospital = nullptr;
        bool fueOcupada = false;

    public:
        void addHospital(Hospital* hos);
        Hospital* getHospital();
        bool getEstado();

};

#endif