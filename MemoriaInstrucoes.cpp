#include "MemoriaInstrucoes.h"
#include <iostream>

using namespace std;

MemoriaInstrucoes::MemoriaInstrucoes(){
    //Vetor da memoria de instrucoes inicializado com 0's no arquivo .h
    this->tamanho = 0;
}

int MemoriaInstrucoes::getTamanho(){
    return this->tamanho;
}

int MemoriaInstrucoes::getInstrucao(int endereco){
    return this->memoriaDeInstrucoes[endereco];
}

void MemoriaInstrucoes::adicionaInstrucao(int instrucao){
    if (this->tamanho < 128) {
        this->memoriaDeInstrucoes[this->tamanho] = instrucao;
        this->tamanho++;
    } else {
        cout << "\nMemoria cheia. Nao foi possivel adicionar nova instrucao" << endl;
    }
}