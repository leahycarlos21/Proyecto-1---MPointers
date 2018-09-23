cmake_minimum_required(VERSION 3.10)
project(Proyecto__1_MPointers)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto__1_MPointers main.cpp DynMemoryPackage/MemoryAlloc/nodoMemory.h DynMemoryPackage/MemoryAlloc/memoryMap.cpp DynMemoryPackage/MemoryAlloc/memoryMap.h DynMemoryPackage/ListaEnlazada/nodo.h DynMemoryPackage/ListaEnlazada/listaEnlazada.cpp DynMemoryPackage/ListaEnlazada/listaEnlazada.h DynMemoryPackage/MemoryServer/MemoryManage.cpp DynMemoryPackage/MemoryServer/MemoryManage.h)