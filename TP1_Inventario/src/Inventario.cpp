#include "Inventario.h"
using namespace std;

const string nombreArchivo = "./save_file.csv";

Inventario::Inventario() {
    this -> nombreItem = "";
    this -> tipoItem = "";
    this -> esLineaValida = false;
    cargarArchivo();
}

void Inventario::realizarOpcionElegida(string& opcionElegida) {
    opcionElegida = cadenaAMayuscula(opcionElegida);
    if(opcionElegida == "CONSULTA"){
        mostrarContenido();
    } else if(opcionElegida == "ALTA"){
        realizarAlta();
    } else if(opcionElegida == "BAJA"){
        realizarBaja();
    } else if (opcionElegida != "SALIR"){
        cout << "Opcion invalida." << endl;
    }
}

void Inventario::consultarAccion() {
    cout << endl <<"Accion sobre el inventario: ";
}

void Inventario::realizarAlta() {
    size_t cantidadDatos = vector.tamanio();
    if(cantidadDatos < static_cast<size_t>(LIMITE_ITEM)){
        Item* item = new Item(cargarDatosItem());
        vector.alta(item);

    } else{
        cout << "Se ha superado la cantidad items.";
    }
}

Item Inventario::cargarDatosItem() {
    cout << "Nombre del item: ";
    getline(cin>>ws, nombreItem);
    cout << "Tipo del item: ";
    getline(cin>>ws, tipoItem);
    tipoItem = cadenaAMayuscula(tipoItem);
    cargarTipoValido();

    Item itemDatos(nombreItem, tipoItem);

    return itemDatos;
}

std::string Inventario::cargarItemDeBaja() {
    string item;
    cout << "Indique el item a eliminar: ";
    getline(cin>>ws, item);
    return item;
}

void Inventario::mostrarContenido() {
    for(size_t i = 0; i < vector.tamanio(); i++){
        cout << i + 1 << ": ";
        vector[i]->listarInformacion();
        cout << endl;
    }
}

void Inventario::realizarBaja() {
    string palabra = cargarItemDeBaja();
    bool esigual = false;
    size_t i = 0;

    while (i < vector.tamanio() && !esigual) {
        if (*(vector[i]) == palabra) {
            esigual = true;
            Item* itemEliminado = vector.baja(i);
            delete itemEliminado;
            cout << "Se utilizo el item: " << palabra;
        }
        i++;
    }

    if(!esigual){
        cout << "Error de inventario! No se dispone de ese item" << endl;
    }

}

void Inventario::guardarArchivo() {
    ofstream archivoCSV(nombreArchivo);
    if(!archivoCSV.is_open()){
        cout << "No se ha podido abrir el archivo CSV" << endl;
    } else{
        for(size_t i = 0; i < vector.tamanio(); i++){
            archivoCSV << *vector[i] << endl;
        }
    }

    archivoCSV.close();
}


bool Inventario::esTipoValido() {
    bool esTipoValido = false;

    if(tipoItem == TIPO_CURATIVO || tipoItem == TIPO_MUNICION || tipoItem == TIPO_PUZZLE){
        esTipoValido = true;
    }
    return esTipoValido;
}

void Inventario::cargarTipoValido() {
    while (!esTipoValido()){
        cout << "Los tipos de items validos son: 'CURATIVO' - 'MUNICION' - 'PUZZLE'" << endl;
        cout << "Tipo del item: ";
        getline(cin>>ws, tipoItem);
        tipoItem = cadenaAMayuscula(tipoItem);
    }
}

void Inventario::analizarArchivo(string& linea, string& nombre, string &tipo) {
    istringstream ss(linea);
    if(getline(ss, nombre, ',') && getline(ss, tipo)){
        esLineaValida = true;
    }
}

void Inventario::cargarArchivo() {
    ifstream archivoCSV(nombreArchivo);
    if(!archivoCSV.is_open()){
        cout << "No se ha podido abrir el archivo";
    }

    string linea, nombre, tipo;
    while(getline(archivoCSV, linea)){
        analizarArchivo(linea, nombre, tipo);
        if(esLineaValida){
            Item* item = new Item(nombre, tipo);
            vector.alta(item);
        }
    }
    archivoCSV.close();
}

Inventario::~Inventario() {
    for(size_t i = 0; i < vector.tamanio(); i++){
        delete vector[i];
    }
}

string Inventario::cadenaAMayuscula(string cadena) {
    for(char& caracter: cadena){
        caracter = char(toupper(caracter));
    }
        return cadena;
    }







