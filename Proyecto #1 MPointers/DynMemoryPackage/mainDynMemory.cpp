//
// Created by leahycarlos21 on 9/09/18.
//
#include <cstring>
#include <iostream>
#include "MemoryAlloc/memoryMap.h"
#include "stdlib.h"
#include "ListaEnlazada/listaEnlazada.h"
#include "MemoryServer/MemoryManage.h"

#define intSize 4  ///como solo vamos a tener int, entonces no se cambia el intSize
using namespace std;


int mainDynMemory() {
    cout << "Hello, World! DynMemory main" << endl;

    /**Esto crea el bloque de memoria, no es necesario crear varios para distintos cliente, se crea fuera del loop del server*/
    MemoryManage *memoryManage = new MemoryManage();

    ///El bloqueSize es el tamaño del bloque de memoria que se va a asignar al inicializar el server
    int bloqueSize = 100;
    memoryManage->createBloque(bloqueSize);

    ///para retornarle el id al cliente, solamente se utiliza el solicitarEspacio(int) y este devuelve un int


    ///Pasos para asignar el valor

    ///Primero se tiene que reservar, para asignarle un ID
    int idCliente1 = memoryManage->solicitarEspacio(intSize);

    ///Con el dato asignado del cliente, se utiliza la funcion almacenar dato
    int datoDelCliente = 9999;

    ///AlmacenarDato es un bool, retorna true si se logro almacenar, retorna false si no se logró almacenar
    bool almacenaje = memoryManage->almacenarDato(idCliente1, "int",
                                                  datoDelCliente); ///Primero va el idCliente, luego el tipo (no se cambia porque solo utilizamos int) y luego va el dato del cliente

    /// y Listo

    cantidadDisponible(); ///retona la cantidad disponible en memoryManage


    printLista(memoryManage->listaBlockMem); ///Imprime la lista del idCliente y el dato

    ///Si se quiere mostrar el dato para el cliente solamente se utiliza la siguiente funcin el parametro del idCliente
    int dato = memoryManage->getDato(idCliente1);


    ///Si el objecto MPointer lo llegan a eliminar, se debe de utilizar este metodo para liberar y espacio de memoria del server
    memoryManage->eliminarDato(idCliente1);
    cout << "Se elimino el dato" << endl;
    printLista(memoryManage->listaBlockMem); ///No deberia salir nada

    delete memoryManage;


    return 0;
}
