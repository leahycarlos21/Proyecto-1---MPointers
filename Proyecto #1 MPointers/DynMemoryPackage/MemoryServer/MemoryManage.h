//
// Created by leahycarlos21 on 21/09/18.
//

#ifndef PROYECTO_1_MPOINTERS_MEMORYMANAGE_H
#define PROYECTO_1_MPOINTERS_MEMORYMANAGE_H


#include "../ListaEnlazada/listaEnlazada.h"

class MemoryManage {
private:
    //  listaEnlazada listaBlockMem;
    int idCliente;


public:
    listaEnlazada listaBlockMem;

    void createBloque(int sizeTotal);

    int solicitarEspacio(int size);

    bool almacenarDato(int idCliente, string typeDato, int dato);

    int getDato(int idCliente);

    void eliminarDato(int idCliente);

    MemoryManage();

    virtual ~MemoryManage();


};


#endif //PROYECTO_1_MPOINTERS_MEMORYMANAGE_H
