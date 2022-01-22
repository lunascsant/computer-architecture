#include "EX_MEM.h"

EX_MEM::EX_MEM(bool zero, int somadorResultado, int ALUResultado, int readData, int writeRegister){
    this->zero = zero;
    this->somadorResultado = somadorResultado;
    this->ALUResultado = ALUResultado;
    this->readData = readData;
    this->writeRegister = writeRegister;
}

bool EX_MEM::getZero(){
    return this->zero;
}

int EX_MEM::getSomadorResultado(){
    return this->somadorResultado;
}

int EX_MEM::getALUResultado(){
    return this->ALUResultado;
}

int EX_MEM::getReadData(){
    return this->readData;
}

int EX_MEM::getWriteRegister(){
    return this->writeRegister;
}

void EX_MEM::setZero(bool zero){
    this->zero = zero;
}

void EX_MEM::setSomadorResultado(int somadorResultado){
    this->somadorResultado = somadorResultado;
}

void EX_MEM::setALUResultado(int ALUResultado){
    this->ALUResultado = ALUResultado;
}

void EX_MEM::setReadData(int readData){
    this->readData = readData;
}

void EX_MEM::setWriteRegister(int writeRegister){
    this->writeRegister = writeRegister;
}

void EX_MEM::setRegistradores(bool zero, int somadorResultado, int ALUResultado, int readData, int writeRegister){
    this->zero = zero;
    this->somadorResultado = somadorResultado;
    this->ALUResultado = ALUResultado;
    this->readData = readData;
    this->writeRegister = writeRegister;
}