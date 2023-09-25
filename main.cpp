#include <iostream>
#include "Fantasma.h"

using namespace std;

int main() {
    // Para finalizar la interaccion con el fantasma se debera escribir 'salir'
    string preguntaIngresada;
    Fantasma fantasma;
    fantasma.Bienvenida();
    do{
        getline(cin>>ws, preguntaIngresada);
        fantasma.recibirPregunta(preguntaIngresada);
    }while (preguntaIngresada != "salir");

    fantasma.Saludo();
    return 0;
}
