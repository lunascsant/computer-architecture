#include "ALU.h"

ALU::ALU(){
    this->resultadoOut = 0;
    this->zeroOut = 0;
}

// Getters das saidas
int* ALU::getZeroOut(){
    return &this->zeroOut;
}

unsigned int* ALU::getResultadoOut(){
    return &this->resultadoOut;
}

// Setters das saidas
void ALU::setResultadoOut(unsigned int resultado){
    this->resultadoOut = resultado;
}

void ALU::setZeroOut(int zero){
    this->zeroOut = zero;
}

// Funcoes da ALU
void ALU::soma(){
    unsigned int soma = *this->entrada1 + *this->entrada2;
    
    this->setResultadoOut(soma);
}

void ALU::subtracao(){
    unsigned int subtracao = *this->entrada1 + (~*this->entrada2 + 1);

    this->setResultadoOut(subtracao);
}

void ALU::andOperation(){
    unsigned int andResultado = *this->entrada1 & *this->entrada2;

    this->setResultadoOut(andResultado);
}

void ALU::orOperation(){
    unsigned int orResultado = *this->entrada1 | *this->entrada2;

    this->setResultadoOut(orResultado);
}

void ALU::setOnLessThan(){
    unsigned int setOnLessThan = 0;
    if (*this->entrada1 < *this->entrada2) {
        setOnLessThan = 1;
    }

    this->setResultadoOut(setOnLessThan);
}

void ALU::shiftLeftLogical(){
    //shift left usando o campo shamt

}