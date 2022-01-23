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

unsigned int* MemoriaInstrucoes::getInstrucao(int endereco){
    unsigned int palavra=0;
    palavra += memoriaDeInstrucoes[endereco]<<24;
    palavra += memoriaDeInstrucoes[endereco+1]<<16;
    palavra += memoriaDeInstrucoes[endereco+2]<<8;
    palavra += memoriaDeInstrucoes[endereco+3];

    this->ultimaPalavraLida = palavra;

    return &this->ultimaPalavraLida;
}

void MemoriaInstrucoes::adicionaInstrucao(char instrucao){
    if (this->posicao < this->tamanho) {
        this->memoriaDeInstrucoes[this->posicao] = instrucao;
        this->posicao++;
    } else {
        cout << "\nMemoria cheia. Nao foi possivel adicionar nova instrucao" << endl;
    }
}