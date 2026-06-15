#include"sistemaHospitalario.h"
#include<iostream>

        void SistemaHospitalario::consultarInformacionHospital(std::string codHospital){
            std::string infoHospital = "";
            //infoHospital = listaHash.consultar(codHospital)->mostrarInformacion();
            std::cout<<infoHospital;
        }
        void SistemaHospitalario::agregarHospital(Hospital hospital){
            //listaHash.agregar(hospital);
        }
        void SistemaHospitalario::eliminarHospital(std::string codigoHospital){
            //derivarPacientes del hospital
            //eliminar hospital de memoria
            //borrar hospital de lista hash
        }
        void SistemaHospitalario::listarHospitales(){
            /*Lista<std::string> claves = listaHash.claves()
            for(int i = 0; i < claves.largo(); i++){
                std::cout<<listaHash.consultar(claves(i))->mostrarInformacion<<std::endl;
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
        Lista<Hospital*> SistemaHospitalario::hospitalesPorEspecialidad(std::string especialidad){
            Lista<Hospital*> hospitales;
            /*Lista<std::string> claves = listaHash.claves()
            for(int i = 0; i < claves.largo(); i++){
                if(listaHash.consultar(claves(i))-> tieneEspecialidad(especialidad)){
                    std::cout<<listaHash.consultar(claves(i))->mostrarInformacion<<std::endl;
                }
                
            }
            ordenar hospitales por capacidad de camas    
            */
        }