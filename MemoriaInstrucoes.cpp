#include "MemoriaInstrucoes.h"
#include <iostream>

using namespace std;

MemoriaInstrucoes::MemoriaInstrucoes(int tamanhoMemoria){
    this->memoriaDeInstrucoes = new unsigned char[tamanhoMemoria];
    this->tamanho = tamanhoMemoria;
    this->posicao = 0;
    this->ultimaPalavraLida=0;
}

MemoriaInstrucoes::MemoriaInstrucoes(){
   // this->memoriaDeInstrucoes = new char[tamanhoMemoria];
    this->tamanho = 0;
    this->posicao = 0;
    this->ultimaPalavraLida=0;

}

MemoriaInstrucoes::MemoriaInstrucoes(unsigned int* endereco){
    this->endereco = endereco;
    this->tamanho = 0;
    this->posicao = 0;
    this->ultimaPalavraLida=0;

}

void MemoriaInstrucoes::alocaMemoria(int tamanhoMemoria) {
    this->memoriaDeInstrucoes = new unsigned char[tamanhoMemoria];
    this->tamanho = tamanhoMemoria;
    this->posicao = 0;
}

MemoriaInstrucoes::~MemoriaInstrucoes() {
    delete [] this->memoriaDeInstrucoes;
}

int MemoriaInstrucoes::getTamanho(){
    return this->tamanho;
}

void MemoriaInstrucoes::setInstrucaoOut(){
    unsigned int palavra=0;
    unsigned int endereco = *this->endereco;

    if(endereco >this->tamanho-4){
        this->ultimaPalavraLida=0;
        this->preTermino=1;

        if(endereco-(this->tamanho-4) >= 5*4){
            fimInstrucoes=1;
        }

        return;
    }

    palavra += ((unsigned int)memoriaDeInstrucoes[endereco])<<24;
    palavra += ((unsigned int)memoriaDeInstrucoes[endereco+1])<<16;
    palavra += ((unsigned int)memoriaDeInstrucoes[endereco+2])<<8;
    palavra += (unsigned int)memoriaDeInstrucoes[endereco+3];

    this->ultimaPalavraLida = palavra;

    //return &this->ultimaPalavraLida;
}

void MemoriaInstrucoes::adicionaByte(unsigned char byte){
    if (this->posicao < this->tamanho) {
        this->memoriaDeInstrucoes[this->posicao] = byte;
        this->posicao++;
    } else {
        cout << "\nMemoria cheia. Nao foi possivel adicionar nova instrucao" << endl;
    }
}


