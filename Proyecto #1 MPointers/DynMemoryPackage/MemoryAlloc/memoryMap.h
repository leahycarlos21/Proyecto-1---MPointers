//
// Created by leahycarlos21 on 13/09/18.
//

#ifndef PROYECTO_1_MPOINTERS_MEMORYMAP_H
#define PROYECTO_1_MPOINTERS_MEMORYMAP_H

#include "nodoMemory.h"

void createPool(int byteSize);

void *my_malloc(int size);

void my_free(void *block);

int cantidadDisponible();
int getBloqueSize();
template <typename T>
T cambiarVoidToType(void *ptr); //retorna el dato para el server



#endif //PROYECTO_1_MPOINTERS_MEMORYMAP_H
