#include "EX_MEM.h"

// Construtores
EX_MEM::EX_MEM(){

};

EX_MEM::EX_MEM(
        int *zero, 
        unsigned int *somadorResultado, 
        unsigned int *ALUResultado, 
        unsigned int *readData2, 
        unsigned int *writeRegister, 
        int *regWrite, 
        int *memToReg, 
        int *branchSignal, 
        int *memRead, 
        int *memWrite
    ){
        this->zeroIn = zero;
        this->somadorResultadoIn = somadorResultado;
        this->ALUResultadoIn = ALUResultado;
        this->readData2In = readData2;
        this->writeRegisterIn = writeRegister;
        this->regWriteIn = regWrite;
        this->memToRegIn = memToReg;
        this->branchSignalIn = branchSignal;
        this->memReadIn = memRead;
        this->memWriteIn = memWrite;
}

// Get das saidas
int* EX_MEM::getZeroOut(){
    return &this->zeroOut;
}

unsigned int* EX_MEM::getSomadorResultadoOut(){
    return &this->somadorResultadoOut;
}

unsigned int* EX_MEM::getALUResultadoOut(){
    return &this->ALUResultadoOut;
}

unsigned int* EX_MEM::getReadDataOut(){
    return &this->readData2Out;
}

unsigned int* EX_MEM::getWriteRegisterOut(){
    return &this->writeRegisterOut;
}

int* EX_MEM::getRegWriteOut(){
    return &this->regWriteOut;
}

int* EX_MEM::getMemToRegOut(){
    return &this->memToRegOut;
}

int* EX_MEM::getBranchSignalOut(){
    return &this->branchSignalOut;
}

int* EX_MEM::getMemReadOut(){
    return &this->memReadOut;
}

int* EX_MEM::getMemWriteOut(){
    return &this->memWriteOut;
}

// Setters de registradores
void EX_MEM::setZero(int zero){
    this->zero = zero;
}

void EX_MEM::setSomadorResultado(unsigned int somadorResultado){
    this->somadorResultado = somadorResultado;
}

void EX_MEM::setALUResultado(unsigned int ALUResultado){
    this->ALUResultado = ALUResultado;
}

void EX_MEM::setReadData(unsigned int readData){
    this->readData2 = readData;
}

void EX_MEM::setWriteRegister(unsigned int writeRegister){
    this->writeRegister = writeRegister;
}

void EX_MEM::setRegistradores(int zero,unsigned int somadorResultado, int ALUResultado, int readData, int writeRegister){
    this->zero = zero;
    this->somadorResultado = somadorResultado;
    this->ALUResultado = ALUResultado;
    this->readData2 = readData;
    this->writeRegister = writeRegister;
}