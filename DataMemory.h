//
// Created by luciana on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_DATAMEMORY_H
#define COMPUTER_ARCHITECTURE_DATAMEMORY_H


class DataMemory {
private:
    int dataMemory[128];

    //inputs
    int* memWrite;
    int* memRead;
    int* address;
    int* writeData;

    //outputs
    int readData;
public:
    DataMemory();
    int* getReadData();
    void setAddress(int* newAddress);
    void setWriteData(int* newWriteData);
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


        }else{
            //descida do clock
            //lê dos registradores
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_DATAMEMORY_H
