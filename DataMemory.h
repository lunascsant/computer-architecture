//
// Created by luciana on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_DATAMEMORY_H
#define COMPUTER_ARCHITECTURE_DATAMEMORY_H


class DataMemory {
private:
    bool* memWrite;
    bool* memRead;
    int address;
    int writeData;
    int readData;
public:
    DataMemory();
    int getAddress();
    int getWriteData();
    int getReadData();
    void setAddress(int newAddress);
    void setWriteData(int newWriteData);
    void setReadData(int newReadData);
    //bool getMemWrite();
    //bool getMemRead();
    void setMemWrite(bool* newMemWrite);
    void setMemRead(bool* newMemRead);
};


#endif //COMPUTER_ARCHITECTURE_DATAMEMORY_H
