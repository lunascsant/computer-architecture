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


string DataMemory::getState(){


    string state;
    char partStr[50];

    for(int i=0; i<128; i++){

        //state+="$" + regNames[i] +": " + to_string((int)regs[i]) + "\n";
        sprintf(partStr, "%3d: %11d |",  i, (int)dataMemory[i]);
        state.append(partStr);
        //cout << i << endl;
        if((i+1)%8==0){
            state.append("\n");
        }
    }

    return state;

}