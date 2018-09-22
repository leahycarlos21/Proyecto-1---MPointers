//
// Created by leahycarlos21 on 21/09/18.
//

#include "MemoryManage.h"
#include "../MemoryAlloc/memoryMap.h"
#include <string>


void MemoryManage::createBloque(int sizeTotal) {
    createPool(sizeTotal);
}

int MemoryManage::solicitarEspacio(int size) {
    void *ptr = my_malloc(size);
    idCliente++;//El idAutogenerado
    insertar(listaBlockMem, idCliente, ptr, "null");
    return idCliente;
}

//template <typename T>
bool MemoryManage::almacenarDato(int idCliente, string typeDato, int dato) {
    cout<<"getBloqueSize()-------"<<getBloqueSize()<<endl;
    cout<<"sizeof(dato)-----"<< sizeof(dato)<<endl;
    if(sizeof(dato)>cantidadDisponible()){
        cout<<"NO HAY CAMPO"<<endl;
        return false;

    }
    else if (typeDato == "int") {
        cout << "typeDato------------------"<<typeDato << endl;
        my_free(buscarElemento(listaBlockMem, idCliente));///lo libera por si el tamaño es diferente
        int *ptrAux = (int *) my_malloc(sizeof(int));
        *ptrAux = dato;
        actualizar(listaBlockMem, idCliente, ptrAux, typeDato);
    } else if (typeDato == "string") {
        cout << typeDato << endl;
    } else if (typeDato == "bool") {
        cout << typeDato << endl;
    } else if (typeDato == "float") {
        cout << typeDato << endl;
    }
    return true;

}

int MemoryManage::getDato(int idCliente) {
    void *ptrDato = buscarElemento(listaBlockMem, idCliente);
    int dato = *(static_cast<int *>(ptrDato));
    cout << "getDato(int)= " << dato << endl;
    return dato;
}

MemoryManage::~MemoryManage() {
    delete listaBlockMem;

}

MemoryManage::MemoryManage() {
    listaBlockMem = NULL;
    idCliente = 0;
}