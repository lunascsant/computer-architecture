//
// Created by luciana on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_DATAMEMORY_H
#define COMPUTER_ARCHITECTURE_DATAMEMORY_H


class DataMemory {
private:
    unsigned int dataMemory[128];

    //inputs
    int* memWrite;
    int* memRead;
    unsigned int* address;
    unsigned int* writeData;

    //outputs
    unsigned int readData = 0;
public:
    DataMemory();
    unsigned int* getReadData();
    void setAddress(unsigned int* newAddress);
    void setWriteData(unsigned int* newWriteData);
    void setReadData(int newReadData);
    //bool getMemWrite();
    //bool getMemRead();
    void setMemWrite(int* newMemWrite);
    void setMemRead(int* newMemRead);
    void buscaMemoriaDados(int address);

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            if(*memWrite) {
                dataMemory[*this->address] = *writeData;
            }
        }else{
            //descida do clock
            //lê dos registradores
            if (*memRead) {
                this->readData = dataMemory[*this->address];
            }
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_DATAMEMORY_H
