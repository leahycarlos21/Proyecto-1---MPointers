//
// Created by leahycarlos21 on 9/09/18.
//
#include <cstring>
#include <iostream>
#include "MemoryAlloc/memoryMap.h"
#include "stdlib.h"
#include "ListaEnlazada/listaEnlazada.h"
#include "MemoryServer/MemoryManage.h"

using namespace std;


int mainDynMemory() {
    cout << "Hello, World! DynMemory main" << endl;

    MemoryManage *memoryManage = new MemoryManage();
    int bloquePrueba = 100;
    memoryManage->createBloque(bloquePrueba);

    int idCliente1 = memoryManage->solicitarEspacio(10);
    cout << "99-****-----------------" << endl;
    cantidadDisponible();


    printLista(memoryManage->listaBlockMem);

    memoryManage->almacenarDato(1, "int", 100);
    cout << sizeof(int) << endl;
    printLista(memoryManage->listaBlockMem);
    buscarElemento(memoryManage->listaBlockMem, 1);

    int dato = memoryManage->getDato(1);
    cantidadDisponible();

    memoryManage->eliminarDato(1);
    printLista(memoryManage->listaBlockMem);

    delete memoryManage;


    return 0;
}

//https://embeddedartistry.com/blog/2017/2/28/c-casting-or-oh-no-we-broke-malloc
//https://github.com/bdubchambers/MemoryHeap_LinkedList/blob/master/mallok.h#L8
//https://gist.github.com/martincruzot/16f1c181b38743e06449
