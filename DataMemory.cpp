//
// Created by luciana on 22/01/2022.
//

#include "DataMemory.h"

DataMemory::DataMemory() {
    this->memRead = 0;
    this-memWrite = 0;
}

int DataMemory::getAddress() {
    return this->address;
}

int DataMemory::getWriteData() {
    return this->writeData;
}

int DataMemory::getReadData() {
    return this->readData;
}

void DataMemory::setAddress(int newAddress) {
    this->address = newAddress;
}

void DataMemory::setWriteData(int newWriteData) {
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

void DataMemory::setMemWrite(bool* newMemWrite) {
    this->memWrite = newMemWrite;
}

void DataMemory::setMemRead(bool* newMemRead) {
    this->memRead = newMemRead;
}