#include "MemoriaInstrucoes.h"
#include <iostream>

using namespace std;

MemoriaInstrucoes::MemoriaInstrucoes(int tamanhoMemoria){
    this->memoriaDeInstrucoes = new char[tamanhoMemoria];
    this->tamanho = tamanhoMemoria;
    this->posicao = 0;
}

MemoriaInstrucoes::MemoriaInstrucoes(){
   // this->memoriaDeInstrucoes = new char[tamanhoMemoria];
    this->tamanho = 0;
    this->posicao = 0;
}

void MemoriaInstrucoes::alocaMemoria(int tamanhoMemoria) {
    this->memoriaDeInstrucoes = new char[tamanhoMemoria];
    this->tamanho = tamanhoMemoria;
    this->posicao = 0;
}

MemoriaInstrucoes::~MemoriaInstrucoes() {
    delete [] this->memoriaDeInstrucoes;
}

int MemoriaInstrucoes::getTamanho(){
    return this->tamanho;
}

int MemoriaInstrucoes::getInstrucao(int endereco){
    return this->memoriaDeInstrucoes[endereco];
}

void MemoriaInstrucoes::adicionaInstrucao(char instrucao){
    if (this->posicao < this->tamanho) {
        this->memoriaDeInstrucoes[this->posicao] = instrucao;
        this->posicao++;
    } else {
        cout << "\nMemoria cheia. Nao foi possivel adicionar nova instrucao" << endl;
    }
}