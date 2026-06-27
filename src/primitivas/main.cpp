#include "arbol.h"
#include <iostream>

using namespace std;

int main() {
    Arbol arbol;

    // INSERTAMOS DIAGNÓSTICOS (diag, frecuencia)
    arbol.insertar("Gripe", 5);
    arbol.insertar("Covid", 10);
    arbol.insertar("Dengue", 3);
    arbol.insertar("Bronquitis", 7);
    arbol.insertar("Neumonia", 12);
    arbol.insertar("Asma", 6);

    cout << "=== Diagnósticos en orden ===" << endl;
    arbol.mostrarDiagnosticos();

    // PROBAR AUMENTO DE FRECUENCIA
    cout << "\n=== Aumentar frecuencia de 'Gripe' ===" << endl;
    arbol.aumentarFrecuencia("Gripe");

    arbol.mostrarDiagnosticos();

    // BUSCAR MÁS FRECUENTE (más a la derecha)
    cout << "\n=== Diagnóstico más frecuente ===" << endl;
    NodoArbol* maximo = arbol.diagnosticoMasFrecuente();
    if (maximo != nullptr) {
        cout << "Max: " << maximo->getDiagnostico()
             << " Frecuencia: " << maximo->getFrecuencia() << endl;
    }

    // ELIMINAR UN DIAGNÓSTICO
    cout << "\n=== Eliminar 'Covid' ===" << endl;
    arbol.eliminarDiagnostico("Covid");

    arbol.mostrarDiagnosticos();

    // PROBAR OTRO BORRADO
    cout << "\n=== Eliminar 'Dengue' ===" << endl;
    arbol.eliminarDiagnostico("Dengue");

    arbol.mostrarDiagnosticos();

    // VER SI ESTÁ DESBALANCEADO
    cout << "\n=== Estado del árbol ===" << endl;
    if (arbol.estaDesbalanceado()) {
        cout << "El árbol está desbalanceado" << endl;
    } else {
        cout << "El árbol está balanceado" << endl;
    }

    return 0;
}