#include <iostream>
#include "MPointerPackage/mainMPointer.cpp"
#include "DynMemoryPackage/mainDynMemory.cpp"
#include "ServerPackage/mainServer.cpp"
int main() {
    std::cout << "Hello, World!" << std::endl;
    mainMPointer();
    mainDynMemory();
    mainServer();
    return 0;
}