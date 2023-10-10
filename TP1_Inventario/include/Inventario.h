#ifndef INVENTARIO_H
#define INVENTARIO_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "Vector.hpp"
#include "Item.hpp"
#include "string"


class Inventario {
private:
    const size_t LIMITE_ITEM = 15;
    Vector vector;
    std::string nombreItem;
    std::string tipoItem;
    bool esLineaValida;

    // Metodos

    // PRE: -
    // POST: Se encargara de analizar una linea de texto separada por comas y
    // guardara los valores de nombre y tipo en las variable 'nombre' y 'tipo'.
    // Si se cumple, 'esLineaValida' pasara a guardar el valor 'true'
    void analizarArchivo(std::string& linea, std::string& nombre, std::string& tipo);

    // PRE: -
    // POST: Se solicitara al usuario que ingrese el nombre y el tipo de Item, con los cuales
    // se creara un objeto 'Item' el cual sera retornado.
    Item cargarDatosItem();

    // PRE: La cantidad de elementos en el vector 'vector' no tiene que supera el limite de 'LIMITE_ITEM'
    // POST: Si la cantidad de elementos que hay en el vector es menor a 'LIMITE_ITEM' se creara un nuevo objeto
    // de tipo 'Item' con los datos ingresados por el usuario y se los cargara al 'vector'.
    void realizarAlta();

    // PRE: -
    // POST: Muestra por pantalla la informacion de los elementos que estan dentro del vector 'vector'.
    void mostrarContenido();

    // PRE: -
    // POST: Buscara un elemento en el vector 'vector' con el mismo nombre ingresado y lo eliminara si lo encuentra.
    //TIENE QUE SE IGUAL COMO SE ALMACENO DICHO DATO. Ademas se libera la memoria del objeto 'Item' eliminado.
    void realizarBaja();

    // PRE: -
    // POST: Se solicitara al usuario que ingrese el nombre del item que desea eliminar y
    // se retornara dicha cadena. Esta cadena tiene estar escrita, tal como se dio de alta.
    // Respetando las respectivas mayusculas. NO SE PERMITE INGRESAR LETRAS CON ACENTOS.
    std::string cargarItemDeBaja();

    // PRE: -
    // POST: Devolvera 'true' si el tipo del item es uno de los tipos validos (CURATIVO,
    // MUNICION O PUZZLE), de lo contrario devolvera 'false'
    bool esTipoValido();

    // PRE: -
    // POST: Le solicitara al usuario que ingrese un tipo de imte hasta que este sea un tipo valido (CURATIVO, MUNICION o PUZZLE).
    void cargarTipoValido();

    // PRE: Debera recibir una cadena valida.
    // POST: Convertira todos los caracteres de la cadena recibida a mayusculas y la devolvera modificada.
    std::string cadenaAMayuscula(std::string cadena);

public:
    // Constructor
    // PRE: -
    // POST: El objeto se inicializa con valores predeterminados.
    Inventario();

    // Metodos

    // PRE: -
    // POST: Muestra por pantalla 'Accion sobre le inventario'.
    void consultarAccion();

    // PRE: 'opcionElegida' debe ser una cadena valida(NO SE PERMITE INCLUIR SIMBOLOS NI NUMEROS).
    // POST: Se realizara alguna de las opciones que hay en la funcion, tales son como 'consulta',
    // 'baja', 'alta' o se mostrara un mensaje de 'Opcion invalida'.
    void realizarOpcionElegida(std::string &opcionElegida);

    // PRE: -
    // ṔOST: Abrira el archivo './save_file.csv' para leer sus lineas, analizando cada una de ellas
    // utilzando 'analizarArchivo', posteriormente se agrega objetos 'Item' validos al vector
    // 'vector'. Por ultimo se cierra el archivo.
    void cargarArchivo();


    // PRE: -
    // POST: Se abrira el archivo './save_file.csv', posteriormente se escribira la informacion
    // de los elementos que haya en el vector 'vector' en el archivo y finalmente cierra el archivo.
    void guardarArchivo();

    // PRE: -
    // POST: El destructor se encarga de liberar la memoria de todos los objeto 'Item' que estan
    // almacenados en el vector 'vector' antes de destruir la instancia de la clase 'Inventario'.
    ~Inventario();
};


#endif
