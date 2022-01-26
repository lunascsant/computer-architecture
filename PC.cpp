#include "PC.h"

PC::PC(unsigned int* valorPC){
    this->valorPCIn = valorPC;
}

PC::PC(){
    this->valorPCIn = 0;
}

unsigned int* PC::getValorPCOut(){
    return &this->valorPCOut;
}

void PC::setValorPCOut(unsigned int valorPCOut){
    this->valorPCOut = valorPCOut;
}