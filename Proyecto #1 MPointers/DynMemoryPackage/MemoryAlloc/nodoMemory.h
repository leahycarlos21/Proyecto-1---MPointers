//
// Created by leahycarlos21 on 13/09/18.
//

#ifndef PROYECTO_1_MPOINTERS_NODOMEMORY_H
#define PROYECTO_1_MPOINTERS_NODOMEMORY_H

#include <stdlib.h>

using namespace std;

struct nodoMemory {
    void *memDireccion;
    int bloqueSize;
    int allocated;
    struct nodoMemory *siguiente;
};
typedef struct nodoMemory NodoMemory;

    
#endif //PROYECTO_1_MPOINTERS_NODOMEMORY_H
