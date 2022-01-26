#include "Somador.h"

Somador::Somador(unsigned int* valor1, unsigned int* valor2){
    this->valor1 = valor1;
    this->valor2 = valor2;
}

unsigned int* Somador::getResultado(){
    return &this->resultado;
}

void Somador::setResultado(unsigned int resultado){
    this->resultado = resultado;
}

void Somador::somaValores(){
    unsigned int soma = *this->valor1 + *this->valor2;

    this->resultado = soma;
}