#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include<string>
#include<vector>

class Hospital{
    private:
        std:: string codigoHospital;
        std:: string nombre;
        std:: string ciudad;
        int capacidadCamas;
        std::vector<std::string> especialidades;
        int personalMedico;
        double presupuestoAnual;

    public:
        Hospital(std:: string codigoHospital,std:: string nombre, std:: string ciudad, int capacidadCamas, std::vector<std::string> especialidades,int personalMedico,double presupuestoAnual);
        std:: string mostrarInformacion();
        //listaPacientes(); este sera de tipo vector con la lista de pacientes
        void derivarPaciente();
        int pacientesAtendidos();
        int cantidadDeCamasDisponibles();
        bool tieneSobrecarga();
};




#endif