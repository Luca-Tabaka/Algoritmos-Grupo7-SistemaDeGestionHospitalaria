# Sistema De Gestion Hospitalaria Algoritmos - Grupo 7

 
Link a Diagrama UML del sistema https://drive.google.com/file/d/1K96sYhcFSTCkeDkG7KSO9QCaZsIUWYXC/view?usp=sharing


## Instrucciones de complilacion
Abrir una terminal en la carpeta **src**
Ejecutar el siguiente comando: **g++ -std=c++17 -Wall -Wextra src/.cpp src/primitivas/.cpp 
-o main**

## Modulos

### Gestion del sistema hospitalario
Modulo encargado de la gestion del sistema hospitalario, esto incluye:
- Mostrar informacion de hospitales segun distintos filtros.
- calcular rutas de derivacion entre hospitales.
- Crear, administrar y eliminar hospitales.

#### Gestion de hospitales
La funcion de este modulo es la de administrar los datos de un hospital.
Dentro de este modulo se puede:
- Gestionar pacientes y turnos.
  - Listar turnos de pacientes
  - Listar turnos de medicos
  - gestionar pacientes en lista de espera
- Gestionar insumos
  - Calcular la carga óptima de una ambulancia
  - realizar prueba de backtracking con poda y sin poda


#### Gestion de diagnosticos
Arbol binario que permite el registro y visualizacion de los diagnosticos que reciben los pacientes ordenados por la frecuencia con la que ocurren.

Este modulo permite:

- Mostrar todos los diagnosticos en orden de frecuencia.
- Ingresar diagnosticos que no existen al sistema.
- Incrementar la frecuencia con la que ocurre un diagnostico ya ingresado.
- Eliminar un diagnostico del sistema.
- Listar el diagnostico mas frecuente.
- Indicar si el arbol esta balanceado.


