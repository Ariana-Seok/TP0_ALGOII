#include "Fantasma.h"

using namespace std;

Fantasma::Fantasma() {
    this ->preguntasReservadas = {"hola, como te llamas?", "hola, como te llamas", "como te llamas?", "como te llamas", "cuantos años tenes?", "cuantos anios tenes?", "cuantos años tenes", "cuantos anios tenes", "donde estas", "donde estas?", "como estas", "como estas?"};
    this ->palabrasReservadas = {"abrir", "abre", "abro", "miedo"};
    this ->recibioPalabraReservada = false;
    this ->recibioPalabraMiedo = false;
    this ->recibioPreguntaReservada = false;
    this ->cantidadPreguntasRecibidas = 1;
    this ->cantidadMaximaPreguntas = 5;
}

void Fantasma::cambiarCadenaMinuscula(string &preguntaIngresada) {
    for(size_t i = 0; i < preguntaIngresada.length(); i++){
        preguntaIngresada[i] = static_cast<char>(tolower(preguntaIngresada[i]));
    }
}

void Fantasma::responderPreguntaReservada(string &preguntaIngresada) {
    if(preguntaIngresada == preguntasReservadas[0] || preguntaIngresada == preguntasReservadas[1] || preguntaIngresada == preguntasReservadas[2] || preguntaIngresada == preguntasReservadas[3]){
        cout << "Mi nombre...No recuerdo mi nombre..." <<endl;
        recibioPreguntaReservada = true;
    }
    if(preguntaIngresada == preguntasReservadas[4] || preguntaIngresada == preguntasReservadas[5] || preguntaIngresada == preguntasReservadas[6] || preguntaIngresada == preguntasReservadas[7]){
        cout << "Llevo 109 años acá...Creo que morí hace bastante..." << endl;
        recibioPreguntaReservada = true;
    }
    if(preguntaIngresada == preguntasReservadas[8] || preguntaIngresada == preguntasReservadas[9]){
        cout << "Me encuentro en un limbo entre la vida y la muerte..." << endl;
        recibioPreguntaReservada = true;
    }
    if(preguntaIngresada == preguntasReservadas[10] || preguntaIngresada == preguntasReservadas[11]){
        cout << "/silencio/" << endl;
        recibioPreguntaReservada = true;
    }
}

void Fantasma::buscarPalabraReservada(string &preguntaIngresada) {
    string palabraReservada;
    size_t posicion;
    auto it = palabrasReservadas.cbegin();
    while(!recibioPalabraReservada && it != palabrasReservadas.cend()){
        palabraReservada = *it;
        posicion = preguntaIngresada.find(palabraReservada);
        if(posicion != string::npos){
            recibioPalabraReservada = true;
        }
        if(posicion != string::npos && palabraReservada == palabrasReservadas[3]){
            recibioPalabraMiedo = true;
        }
        ++it;
    }
}

std::string Fantasma::invertirPalabra(std::string palabra) {
    size_t posicionInicial = 0;
    size_t posicionFinal = palabra.length() - 1;

    while(posicionFinal > posicionInicial){
        swap(palabra[posicionFinal], palabra[posicionInicial]);
        posicionInicial++;
        posicionFinal--;
    }
    return palabra;
}

void Fantasma::invertirMensajeRecibido(string &preguntaIngresada) {
    string palabra = "", palabraInvertida = "";
    respuestaInvertida.clear();
    for (size_t i = 0; i < preguntaIngresada.length(); i ++){
        if(preguntaIngresada[i] != ' '){
            palabra += preguntaIngresada[i];
        } else if(!palabra.empty()){
            palabraInvertida = invertirPalabra(palabra);
            respuestaInvertida += palabraInvertida + ' ';
            palabra.clear();
        }
    }
    if (!palabra.empty()){
        palabraInvertida = invertirPalabra(palabra);
        respuestaInvertida += palabraInvertida;
    }
}

void Fantasma::recibirPregunta(string &preguntaIngresada) {
    cambiarCadenaMinuscula(preguntaIngresada);

    size_t maxCaracteres = 50;
    responderPreguntaReservada(preguntaIngresada);
    if(recibioPalabraMiedo || cantidadPreguntasRecibidas > cantidadMaximaPreguntas || preguntaIngresada.length() >= maxCaracteres){
        cout << "..." << endl;
    } else{
        buscarPalabraReservada(preguntaIngresada);
        if (recibioPalabraMiedo) {
            cout << "/abrir_puerta/ /risa_demoníaca/" << endl;
        } else if (recibioPalabraReservada) {
            cout << "/agitar_puerta/" << endl;
        } else if(!recibioPreguntaReservada){
            invertirMensajeRecibido(preguntaIngresada);
            cout << respuestaInvertida << endl;
        }
        recibioPalabraReservada = false;
        recibioPreguntaReservada = false;
        cantidadPreguntasRecibidas++;

    }
}

void Fantasma::Saludo() {
    cout << "No me juzgues por ser silenciosa, nadie planea un asesinato en voz alta..." << endl;
}

void Fantasma::Bienvenida() {
    cout << "Bienvenido a mi pesadilla, creo que te va a gustar... "<< endl;
}







