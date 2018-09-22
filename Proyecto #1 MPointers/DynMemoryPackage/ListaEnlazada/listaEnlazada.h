//
// Created by leahycarlos21 on 15/09/18.
//

#ifndef PROYECTO_1_MPOINTERS_LISTAENLAZADA_H
#define PROYECTO_1_MPOINTERS_LISTAENLAZADA_H

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "nodo.h"
//#include "node.cpp"

void insertar(listaEnlazada &lista,int id,void* memDir1,string typeDato);
void *buscarElemento(listaEnlazada lista, int id);
void printLista(listaEnlazada lista);
void eliminar(listaEnlazada &lista, int id);
void actualizar(listaEnlazada &lista,int id, void* memDir1,string typeDato);


#endif //PROYECTO_1_MPOINTERS_LISTAENLAZADA_H
