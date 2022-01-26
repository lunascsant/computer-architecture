#include "ALU.h"

ALU::ALU(unsigned int resultado, int zero){
    this->resultado = resultado;
    this->zero = zero;
}

ALU::ALU(){
    this->resultado = 0;
    this->zero = 0;
}

// Valores
unsigned int ALU::getResultado(){
    return this->resultado;
}

int ALU::getZero(){
    return this->zero;
}

void ALU::setResultado(unsigned int resultado){
    this->resultado = resultado;
}

void ALU::setZero(int zero){
    this->zero = zero;
}

// Getters das saidas
int* ALU::getZeroOut(){
    return &this->zeroOut;
}

unsigned int* ALU::getResultadoOut(){
    return &this->resultadoOut;
}

// Funcoes da ALU
void ALU::soma(){
    unsigned int soma = *this->entrada1 + *this->entrada2;
    
    this->setResultado(soma);
}

void ALU::subtracao(){
    unsigned int subtracao = *this->entrada1 - *this->entrada2;

    this->setResultado(subtracao);
}