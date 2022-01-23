#include "EX_MEM.h"

EX_MEM::EX_MEM(
        bool zero, 
        int somadorResultado, 
        unsigned int ALUResultado, 
        unsigned int readData, 
        unsigned int writeRegister, 
        int *regWrite, 
        int *memToReg, 
        int *branchSignal, 
        int *memRead, 
        int *memWrite
    ){
        this->zeroIn = zero;
        this->somadorResultadoIn = somadorResultado;
        this->ALUResultadoIn = ALUResultado;
        this->readDataIn = readData;
        this->writeRegisterIn = writeRegister;
        this->regWriteIn = regWrite;
        this->memToRegIn = memToReg;
        this->branchSignalIn = branchSignal;
        this->memReadIn = memRead;
        this->memWriteIn = memWrite;
}

bool EX_MEM::getZeroOut(){
    return this->zeroOut;
}

int EX_MEM::getSomadorResultadoOut(){
    return this->somadorResultadoOut;
}

unsigned int EX_MEM::getALUResultadoOut(){
    return this->ALUResultadoOut;
}

unsigned int EX_MEM::getReadDataOut(){
    return this->readDataOut;
}

unsigned int EX_MEM::getWriteRegisterOut(){
    return this->writeRegisterOut;
}

int EX_MEM::getRegWriteOut(){
    return this->regWriteOut;
}

int EX_MEM::getMemToRegOut(){
    return this->memToRegOut;
}

int EX_MEM::getBranchSignalOut(){
    return this->branchSignalOut;
}

int EX_MEM::getMemReadOut(){
    return this->memReadOut;
}

int EX_MEM::getMemWriteOut(){
    return this->memWriteOut;
}

void EX_MEM::setZero(bool zero){
    this->zero = zero;
}

void EX_MEM::setSomadorResultado(int somadorResultado){
    this->somadorResultado = somadorResultado;
}

void EX_MEM::setALUResultado(unsigned int ALUResultado){
    this->ALUResultado = ALUResultado;
}

void EX_MEM::setReadData(unsigned int readData){
    this->readData = readData;
}

void EX_MEM::setWriteRegister(unsigned int writeRegister){
    this->writeRegister = writeRegister;
}

void EX_MEM::setRegistradores(bool zero, int somadorResultado, int ALUResultado, int readData, int writeRegister){
    this->zero = zero;
    this->somadorResultado = somadorResultado;
    this->ALUResultado = ALUResultado;
    this->readData = readData;
    this->writeRegister = writeRegister;
}