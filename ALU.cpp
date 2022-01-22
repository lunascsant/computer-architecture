#include "ALU.h"

ALU::ALU(int resultado, bool zero){
    this->resultado = resultado;
    this->zero = zero;
}

int ALU::getResultado(){
    return this->resultado;
}

bool ALU::getZero(){
    return this->zero;
}

void ALU::setResultado(int resultado){
    this->resultado = resultado;
}

void ALU::setZero(bool zero){
    this->zero = zero;
}

void ALU::soma(int valor1, int valor2){
    int soma = valor1 + valor2;
    
    this->setResultado(soma);
}

void ALU::subtracao(int valor1, int valor2){
    int subtracao = valor1 - valor2;

    this->setResultado(subtracao);
}