//
// Created by patri on 20/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_BANCOREG_H
#define COMPUTER_ARCHITECTURE_BANCOREG_H

#include "iostream"
#include "stdio.h"
#include <string>

using namespace std;

class BancoReg {

private:
    unsigned int regs[32];
    int* regWrite;

    //inputs
    unsigned int* readRegister1In;
    unsigned int* readRegister2In;
    unsigned int* writeRegisterIn;
    unsigned int* writeDataIn;

    //outputs
    unsigned int readData1=0;
    unsigned int readData2=0;

public:
    BancoReg();
    ~BancoReg()= default;
    void setRegWriteIn(int *regWrite){ this->regWrite=regWrite;}
    void setReadRegister1In(unsigned int* val){ this->readRegister1In = val;}
    void setReadRegister2In(unsigned int* val){ this->readRegister2In = val;}
    void setWriteRegisterIn(unsigned int* val){ this->writeRegisterIn = val;}
    void setWriteDataIn(unsigned int* val){ this->writeDataIn = val;}
    unsigned int* getReadData1(){return &this->readData1;}
    unsigned int* getReadData2(){return &this->readData2;}

    void tickClock(int val);
    string getState();

    void print(){
        /*for (int i=0; i<32; i++){
            cout << i << ": " << regs[i] << endl;
        }*/

        cout << getState()<<endl;
    }

};


#endif //COMPUTER_ARCHITECTURE_BANCOREG_H
