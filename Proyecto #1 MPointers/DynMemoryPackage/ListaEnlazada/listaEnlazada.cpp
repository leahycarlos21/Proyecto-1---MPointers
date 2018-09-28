//
// Created by leahycarlos21 on 15/09/18.
//

#include "listaEnlazada.h"
void insertar(listaEnlazada &lista,int id,void* memDir1,string typeDato){
    listaEnlazada listis;
    listis=new(struct nodo);
    listis->idCliente=id;
    listis->memDir=memDir1;
    listis->tipoDato=typeDato;
    listis->siguiente=lista;
    lista=listis;
}

void* buscarElemento(listaEnlazada lista, int id){
    listaEnlazada listis = lista;
    int i=1, encontrado =0;

    while(listis!=NULL){
        if(listis->idCliente==id){
            cout<<endl<<"EL idCliente es "<<id<<endl;
            int* aux = static_cast<int *>(listis->memDir);
            cout<<"EL dato es"<<*aux<<endl;
            encontrado=1;
            return listis->memDir;
        }
        listis=listis->siguiente;
        i++;

    }
    if(encontrado==0)
        cout<<"No se encontro el id Prro"<<endl;
        return nullptr;
}
void printLista(listaEnlazada lista){
    int i=0;
    while(lista!=NULL){
        cout<<i+1<<") "<<lista->idCliente<<endl;
        cout<<"Dir de memoria"<<lista->memDir<<endl;
        cout<<"Tipo de dato: "<<lista->tipoDato<<endl;

        lista=lista->siguiente;
        i++;
    }
}
void eliminar(listaEnlazada &lista, int id){
    listaEnlazada listis, anterior;
    listis=lista;

    if(lista!=NULL){
        while(listis!=NULL){
            if(listis->idCliente==id){
                if(listis==lista)
                    lista=lista->siguiente;
                else
                    anterior->siguiente=listis->siguiente;
                delete(listis);
                return;
            }
            anterior=listis;
            listis=listis->siguiente;
        }
    }
    else
        cout<<"Lista vacia"<<endl;
}
void actualizar(listaEnlazada &lista,int id, void* memDir1,string typeDato){
    listaEnlazada listis, anterior;
    listis=lista;

    if(lista!=NULL){
        while(listis!=NULL){
            if(listis->idCliente==id){
                listis->memDir=memDir1;
                listis->tipoDato=typeDato;
            }
            anterior=listis;
            listis=listis->siguiente;
        }
    }
    else
        cout<<"Lista vacia"<<endl;
}
