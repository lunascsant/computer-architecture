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

void Somador::somaValores(int valor1, int valor2){
    int soma = valor1 + valor2;

    this->setResultado(soma);
}