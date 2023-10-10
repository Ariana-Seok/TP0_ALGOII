#include "Vector.hpp"


Vector::Vector() {
    this -> cantidadDatos = 0;
    this -> tamanioMaximo = 1;
    datos = new Item*[tamanioMaximo];
}

Item** Vector::copiarDatos(Item **vectorAuxiliar) {
    for (size_t i = 0; i < cantidadDatos; i++){
        vectorAuxiliar[i] = datos[i];
    }
    return vectorAuxiliar;
}

void Vector::redimensionar() {
    tamanioMaximo *=2;
    Item** vectorAuxiliar = new Item* [tamanioMaximo];
    vectorAuxiliar = copiarDatos(vectorAuxiliar);
    delete[] datos;
    datos = vectorAuxiliar;
}

void Vector::alta(Item *dato) {
    if(tamanioMaximo == cantidadDatos){
        redimensionar();
    }
    datos[cantidadDatos] = dato;

    cantidadDatos++;
}

void Vector::alta(Item *dato, size_t indice) {
    if(indice > cantidadDatos){
        throw VectorException();
    }

    if(cantidadDatos >= tamanioMaximo){
        redimensionar();
    }

    for(size_t i = cantidadDatos; i > indice; i--){
        datos[i] = datos[i -1];
    }
    datos[indice] = dato;
    cantidadDatos++;
}

bool Vector::vacio() {
    return cantidadDatos == 0;
}

Item* Vector::baja() {
    if(vacio()){
        throw VectorException();
    }

    Item* datoEliminado = datos[cantidadDatos - 1];
    datos[cantidadDatos - 1] = nullptr;
    cantidadDatos--;

    return datoEliminado;
}

Item *Vector::baja(size_t indice) {
    if(indice >= cantidadDatos || vacio()){
        throw VectorException();
    }

    Item* datoEliminado = datos[indice];

    for(size_t i = indice; i < cantidadDatos - 1; i++){
        datos[i] = datos[i + 1];
    }
    cantidadDatos--;

    reducirTamanio();

    return  datoEliminado;
}

size_t Vector::tamanio() {
    return cantidadDatos;
}


Vector::~Vector() {
    delete[] datos;
}

Item *&Vector::operator[](size_t indice) {
    if(indice >= cantidadDatos || vacio()){
        throw VectorException();
    }
    return datos[indice];
}

void Vector::reducirTamanio() {
    if(cantidadDatos <= tamanioMaximo / 4){
        tamanioMaximo /= 2;
    }

    Item** auxiliar = new Item*[tamanioMaximo];
    copiarDatos(auxiliar);
    delete[] datos;
    datos = auxiliar;
}













