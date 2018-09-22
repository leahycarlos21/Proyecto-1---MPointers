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
/*
    int i, k, size = 1000;

    int a = 100;
    int *ptr11 = &a;

    cout << "a " << a << endl;
    cout << "&a " << &a << endl;
    cout << "&ptr11 " << ptr11 << endl;
    cout << "*ptr11 " << *ptr11 << endl;


    createPool(100);
    void *ptr = my_malloc(90);
    cout << endl;
    cout << "ptr  " << ptr << endl; //direccion del my_malloc
    cout << endl;


    cout << "-----------------" << endl;
    char *ptr2 = (char *) my_malloc(7);

    cout << "------------El ptr2 es " << *ptr2 << endl;
    strcpy(ptr2, "cscs");
    printf("Address: %s\n", ptr2);
    // printf("my_malloc(10)~assert:%p",*ptr2);

    int *ptr5 = (int *) my_malloc(1);
    *ptr5 = 1;
    printf("%ld bytes per pointer\n", sizeof(*ptr5));

    void *ptrAUX = (void *) ptr5;

    int *AAA = (int *) ptrAUX;
    cout << "AAAAAAAAAAAAAAAAAAA  " << *AAA << endl;

    cout << endl;

    cout << "El numero de ptr5 " << *ptr5 << endl;

    my_free(ptr);
    my_free(ptr2);
    my_free(ptr5);
    my_free(ptr11);
    cantidadDisponible();

    listaEnlazada lista = NULL;

    int *ptrPrueba = (int *) my_malloc(1);
    *ptrPrueba = 222;

    void *ptrAuxiliar = (void *) ptrPrueba;

    cout << "-------------" << endl;

    //insertar(listaE &lista,int id,voivoid insertar(listaE &lista,int id,void *ptr,char tipoDato);d* memDir1,char typeDato)
    insertar(lista, 1, ptrAuxiliar, "int");

    printLista(lista);
    cout << endl;
    actualizar(lista, 1, ptrAUX, "kkk");
    printLista(lista);
    // cout<<"tipoDato: "<<lista->tipoDato <<endl;
    //   cout<<"id del Cliente: "<<lista->idCliente<<endl;
    //  cout<<"Direccion de memoria: "<<lista->memDir<<endl;
*/
    MemoryManage* memoryManage= new MemoryManage();
    int bloquePrueba = 100;
    memoryManage->createBloque(bloquePrueba);

    int idCliente1 = memoryManage->solicitarEspacio(10);
cout<<"99-****-----------------"<<endl;
cantidadDisponible();


    printLista(memoryManage->listaBlockMem);

    memoryManage->almacenarDato(1, "int", 100);
    cout<< sizeof(int)<<endl;
    printLista(memoryManage->listaBlockMem);
    buscarElemento(memoryManage->listaBlockMem,1);

    int dato=memoryManage->getDato(1);
    cantidadDisponible();


    delete memoryManage;


    return 0;
}

//https://embeddedartistry.com/blog/2017/2/28/c-casting-or-oh-no-we-broke-malloc
//https://github.com/bdubchambers/MemoryHeap_LinkedList/blob/master/mallok.h#L8
//https://gist.github.com/martincruzot/16f1c181b38743e06449
