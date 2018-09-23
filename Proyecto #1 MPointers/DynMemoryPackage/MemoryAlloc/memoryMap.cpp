//
// Created by leahycarlos21 on 13/09/18.
//

#include "memoryMap.h"
#include "nodoMemory.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
static NodoMemory *inicio = NULL;

void createPool(int byteSize) {

    void *memDireccion = malloc(byteSize);
    if (inicio) {
        free(inicio->memDireccion);
        free(inicio);
        inicio = NULL;
        cout << "primera parte" << endl;
    }
    if (memDireccion != NULL) {
        inicio = (NodoMemory *) malloc(sizeof(memDireccion));
        inicio->siguiente = NULL;
        inicio->allocated = 0;
        inicio->bloqueSize = byteSize;
        inicio->memDireccion = memDireccion;
        cout << "segunda parte" << endl;

    }
}

void *my_malloc(int bytes_requested) {
    nodoMemory *auxNodo, *actualNodo;
    actualNodo = inicio;

    ///Se detiene hasta encontrar un bloque disponible
    while (actualNodo != NULL &&
           ((actualNodo->allocated) ||
            (actualNodo->bloqueSize < bytes_requested))) {
        actualNodo = actualNodo->siguiente;
    }


    ///Si aparece un bloque grande, lo parte en los bytes solicitados
    if (actualNodo != NULL && actualNodo->bloqueSize >= bytes_requested) {
        cout << "bloqueSize es " << actualNodo->bloqueSize << endl;


        if (actualNodo->bloqueSize > bytes_requested) {

            auxNodo = (nodoMemory *) malloc(sizeof(nodoMemory));
            auxNodo->siguiente = actualNodo->siguiente;
            auxNodo->allocated = 0;
            auxNodo->bloqueSize = actualNodo->bloqueSize - bytes_requested;
            auxNodo->memDireccion = (void *) (bytes_requested + (char *) actualNodo->memDireccion);
            actualNodo->siguiente = auxNodo;//remaining memblock is now after current
        }
        actualNodo->allocated = 1;
        actualNodo->bloqueSize = bytes_requested;
        cout << "la direccion de memoria del malloc es" << actualNodo->memDireccion << endl;
        return actualNodo->memDireccion;
    } else {
        cout << "NULL" << endl;

        return NULL;//Requested memory block unavailable
    }
}


void my_free(void *block) {

    NodoMemory *anteriorNodo, *actualNodo, *siguienteNodo;
    anteriorNodo = NULL;
    actualNodo = inicio;

    while (actualNodo != NULL && actualNodo->memDireccion != block) {
        anteriorNodo = actualNodo;
        actualNodo = actualNodo->siguiente;

    }
    if (actualNodo == NULL) {
        return;
    }
    actualNodo->allocated = 0;
    ///Mezcla bloques de memorias que esten antes
    if (anteriorNodo != NULL && !anteriorNodo->allocated) {
        anteriorNodo->bloqueSize += actualNodo->bloqueSize;
        actualNodo->siguiente = actualNodo->siguiente;
        free(actualNodo);
        actualNodo = anteriorNodo;
    }
    siguienteNodo = actualNodo->siguiente;

    if (siguienteNodo != NULL && !siguienteNodo->allocated) {
        actualNodo->bloqueSize += siguienteNodo->bloqueSize;
        actualNodo->siguiente = siguienteNodo->siguiente;
        free(siguienteNodo);
    }

}

int cantidadDisponible() {
    nodoMemory *auxNodo, *actualNodo;
    actualNodo = inicio;

    ///Se detiene hasta encontrar un bloque disponible
    while (actualNodo->siguiente != NULL &&
           ((actualNodo->allocated))) {
        actualNodo = actualNodo->siguiente;
    }
    cout << "\ncantidad Disponibles " << actualNodo->bloqueSize << endl;
    return actualNodo->bloqueSize;

}

int getBloqueSize(){
    return inicio->bloqueSize;

}

template<typename T>
T cambiarVoidToType(void *ptr) {


}; //retorna el dato para el server




