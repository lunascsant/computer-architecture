#include "ALU.h"

ALU::ALU(unsigned int resultado, int zero){
    this->resultado = resultado;
    this->zero = zero;
}

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

void ALU::soma(unsigned int valor1, unsigned int valor2){
    unsigned int soma = valor1 + valor2;
    
    this->setResultado(soma);
}

void ALU::subtracao(unsigned int valor1, unsigned int valor2){
    unsigned int subtracao = valor1 - valor2;

    this->setResultado(subtracao);
}