//
// Created by luciana on 22/01/2022.
//

#include "DataMemory.h"

DataMemory::DataMemory() {

}

int* DataMemory::getReadData() {
    return &this->readData;
}

void DataMemory::setAddress(int* newAddress) {
    this->address = newAddress;
}

void DataMemory::setWriteData(int* newWriteData) {
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