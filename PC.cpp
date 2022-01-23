#include "PC.h"

PC::PC(int valorPC){
    //interessante inicializar com 0
    this->valorPC = valorPC;
}

unsigned int* PC::getValorPC(){
    return &this->valorPC;
}

void PC::setValorPC(unsigned int* valor){
    this->valorPC = *valor;
}