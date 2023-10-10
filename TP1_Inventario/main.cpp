#include <iostream>
#include "Inventario.h"

using namespace std;
int main() {
    string opcion;
    Inventario inventario;
    do {
        inventario.consultarAccion();
        getline(cin>>ws, opcion);
        inventario.realizarOpcionElegida(opcion);
    } while(opcion != "SALIR");
    inventario.guardarArchivo();

    return 0;
}