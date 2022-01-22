#include "PC.h"

PC::PC(int valorPC){
    //interessante inicializar com 0
    this->valorPC = valorPC;
}

int PC::getValorPC(){
    return this->valorPC;
}

void PC::setValorPC(int valor){
    this->valorPC = valor;
}