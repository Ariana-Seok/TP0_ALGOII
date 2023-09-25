#ifndef FANTASMA_H
#define FANTASMA_H
#include <vector>
#include <string>
#include <iostream>

class Fantasma {
private:
    // Atributos
    std::vector<std::string> preguntasReservadas;
    std::vector<std::string> palabrasReservadas;

    std::string respuesta;
    std::string respuestaInvertida;

    int cantidadPreguntasRecibidas;
    int cantidadMaximaPreguntas;

    bool recibioPreguntaReservada;
    bool recibioPalabraReservada;
    bool recibioPalabraMiedo;

    // Metodos

    //PRE: La cadena 'preguntaIngresada' debera ser un texto que no contenga '¡', '¿', 'Ñ'.
    //POST: La cadena 'preguntaIngresada' se convertira en minusculas.
    void cambiarCadenaMinuscula(std::string &preguntaIngresada);

    //PRE: La cadena 'preguntaIngresada' debera ser un texto que no contenga '¡', '¿', 'Ñ'.
    //POST: El metodo mostrara un mensaje en la terminal respondiendo a lo que contenga
    // 'preguntaIngresada' o no realizara nada si no coincide con ninguna de las preguntas ya reservadas.
    void responderPreguntaReservada(std::string &preguntaIngresada);

    //PRE: La cadena 'preguntaIngresada' debera ser un texto que no contenga '¡', '¿', 'Ñ'.
    //POST: El metodo se encargara de verificar si contiene alguna de la palabras reservadas,
    // en caso de que si haya alguna palabra reservada este metodo cambiara el contenido de las variables
    // recibioPalabraReservada o recibioPalabraMiedo a true.
    void buscarPalabraReservada(std::string &preguntaIngresada);

    //PRE: La cadena 'preguntaIngresada' debera ser un texto que no contenga '¡', '¿', 'Ñ'.
    //POST: El metodo se encargara de invertir las palabras de la cadena cargada en
    // 'preguntaIngresada' y almacenara el resultado en la variable 'respuestaInvertida' convertida en minusculas.
    void invertirMensajeRecibido(std::string &preguntaIngresada);

    //PRE: La cadena 'palabra' debera contener almenos un texto valido.
    //POST: La cadena 'palabra' invertira su orden y la devolvera.
    std::string invertirPalabra(std::string palabra);


public:
    //PRE: 'mensajeRecibido' tiene que almacenar algo de tipo string
    //POST: Crea un objeto Fantasma.
    Fantasma();

    //PRE: -
    //POST: El metodo mostrara un mensaje de bienvenida en la terminal.
    void Bienvenida();

    //PRE: La cadena 'preguntaIngresada' debera ser un texto que no contenga '¡', '¿', 'Ñ', ni numeros.
    //POST: El metodo procesara 'preguntaIngresada' y dependiendo de su contenido se
    // imprimira en la terminal un mensaje correspondiente a ello.
    void recibirPregunta(std::string &preguntaIngresada);

    //PRE: -
    //POST: El metodo mostrara un mensaje de saludo en la terminal.
    void Saludo();




};


#endif
