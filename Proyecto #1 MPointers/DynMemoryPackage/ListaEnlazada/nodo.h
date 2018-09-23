//
// Created by leahycarlos21 on 15/09/18.
//

#ifndef PROYECTO_1_MPOINTERS_NODO_H
#define PROYECTO_1_MPOINTERS_NODO_H


#include <iostream>
#include <stdlib.h>
using namespace std;

struct nodo{

    void *memDir;
    int  idCliente;
    string tipoDato;
    struct nodo *siguiente;
};
typedef struct nodo*listaEnlazada;












#endif //PROYECTO_1_MPOINTERS_NODO_H
