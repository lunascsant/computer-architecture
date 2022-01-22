//
// Created by luciana on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_DATAMEMORY_H
#define COMPUTER_ARCHITECTURE_DATAMEMORY_H


class DataMemory {
private:
    int dataMemory[128];
    int* memWrite;
    int* memRead;

    //inputs
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
};


#endif //COMPUTER_ARCHITECTURE_DATAMEMORY_H
