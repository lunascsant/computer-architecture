#include "Somador.h"

Somador::Somador(int resultado){
    this->resultado = resultado;
}

int Somador::getResultado(){
    return this->resultado;
}

void Somador::setResultado(int resultado){
    this->resultado = resultado;
}

void Somador::somaValorMais4(int valor1){
    //seria +1 neh, ja que a memoria array de inteiros
    int soma = valor1 + 4;
    
    this->setResultado(soma);
}

void Somador::somaValores(int valor1, int valor2){
    int soma = valor1 + valor2;

    this->setResultado(soma);
}