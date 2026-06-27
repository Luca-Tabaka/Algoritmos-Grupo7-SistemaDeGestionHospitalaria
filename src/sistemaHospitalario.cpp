#include"sistemaHospitalario.h"
#include<iostream>
using namespace std;

        void SistemaHospitalario::consultarInformacionHospital(string codHospital){
            string infoHospital = "";
            //infoHospital = listaHash.consultar(codHospital)->mostrarInformacion();
            cout<<infoHospital;
        }
        void SistemaHospitalario::agregarHospital(Hospital* hospital){
            listaHospitales.insertar(hospital);
        }
        void SistemaHospitalario::eliminarHospital(string codigoHospital){
           listaHospitales.borrar(codigoHospital);
            //eliminar hospital de memoria
            //borrar hospital de lista hash
        }
        void SistemaHospitalario::listarHospitales(){
            /*Lista<string> claves = listaHash.claves()
            for(int i = 0; i < claves.largo(); i++){
                cout<<listaHash.consultar(claves(i))->mostrarInformacion<<endl;
            }*/
        }
        //lista SistemaHospitalario::calcularRutaDerivacion(Hospital origen, Hospital destino);
        Lista<Hospital*> SistemaHospitalario::hospitalesConSobrecarga(){
        //Dijkstra
        }
        void SistemaHospitalario::listarTurnosMedico(int idMedico){
            //deberia ir en hospital?
        }
        void SistemaHospitalario::listarTurnosPaciente(int idPaciente){
            //deberia ir en hospital?
        }
        Lista<Hospital*> SistemaHospitalario::hospitalesPorEspecialidad(string especialidad){
            Lista<Hospital*> hospitales;
        }