#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>
#include "Item.hpp"

class VectorException : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro del VectorTemplate.
    // Usar de la forma "throw VectorException();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw VectorException();
    //     }
};

class Vector {
private:
    // Atributos
    Item** datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;

    // Metodos

    //Pre: 'vectorAuxiliar' tiene que ser un puntero a un array de punteros de tipo 'Item'. Tiene que haber
    //sido asignado previamente y tener el espacio necesario para almacenar punteros que estan en 'datos'.
    //Y los objetos a los que apuntan los punteros en 'datos' tiene que ser valido y no nulos.
    // Post: La funcion copiara lo que haya dentro de 'datos' (punteros) al array 'vectorAuxiliar'.
    // La funcion devolvera el puntero 'vectorAuxiliar' como resultado.
    Item** copiarDatos(Item** vectorAuxiliar);

    // Pre: -
    // Post: Si se cumple 'cantidadDatos <= tamanioMaximo / 4'  el tamaño del vector se reducira la mitad.
    void reducirTamanio();

    // Pre: 'tamanioMaximo' debe ser un entero mayor que 0. 'cantidadDatos' debera ser mayor o igual que cero y menor o igual que 'tamanioMaximo'.
    // Post: Se duplicara el valor de 'tamanioMaximo' y se creara un nuevo array 'vectorAuxiliar' con el tamaño de 'tamanioMaximo'.
    void redimensionar();

public:
    // Constructor.
    Vector();

    // Pre: -
    // Post: Agrega el dato al final del vector.
    void alta(Item* dato);

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada, moviendo todos los elementos siguientes. Si el
    // indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(Item* dato, size_t indice);

    // Pre: El vector no puede estar vacio.
    // Post: Elimina el ultimo dato.
    Item* baja();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada, moviendo todos los elementos siguientes. Si el indice es igual a
    // la cantidad de datos - 1, simplemente elimina el ultimo dato.
    Item* baja(size_t indice);

    // Pre: -
    // Post: Devuelve true si el vector esta vacio (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    Item*& operator[](size_t indice);

    // Destructor.
    ~Vector();
};

#endif