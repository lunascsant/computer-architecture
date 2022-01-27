//
// Created by luciana on 22/01/2022.
//

#include "DataMemory.h"

DataMemory::DataMemory() {
    this->readData = 0;
}

unsigned int* DataMemory::getReadData() {
    return &this->readData;
}

void DataMemory::setAddress(unsigned int* newAddress) {
    this->address = newAddress;
}

void DataMemory::setWriteData(unsigned int* newWriteData) {
    this->writeData = newWriteData;
}

void DataMemory::setReadData(int newReadData) {
    this->readData = newReadData;
}

/*bool DataMemory::getMemWrite() {
    return this->memWrite;
}

bool DataMemory::getMemRead() {
    return this->memRead;
}*/

void DataMemory::setMemWrite(int* newMemWrite) {
    this->memWrite = newMemWrite;
}

void DataMemory::setMemRead(int* newMemRead) {
    this->memRead = newMemRead;
}

void DataMemory::buscaMemoriaDados(int address) {
    // pega no endereço
    // coloca em readData ou pega de writeData dependendo dos sinais
}