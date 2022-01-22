//
// Created by patri on 20/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_BANCOREG_H
#define COMPUTER_ARCHITECTURE_BANCOREG_H


class BancoReg {

private:
    unsigned int regs[32];
    int* regWrite;

    //inputs
    unsigned int* readRegister1;
    unsigned int* readRegister2;
    unsigned int* writeRegister;
    unsigned int* writeData;

    //outputs
    unsigned int readData1;
    unsigned int readData2;

public:
    BancoReg(int *regWrite){this->regWrite=regWrite;}
    ~BancoReg()= default;
    void setReadRegister1(unsigned int* val){ this->readRegister1 = val;}
    void setReadRegister2(unsigned int* val){ this->readRegister2 = val;}
    void setWriteRegister(unsigned int* val){ this->writeRegister = val;}
    void setWriteData(unsigned int* val){ this->writeData = val;}
    unsigned int* getReadData1(){return &this->readData1;}
    unsigned int* getReadData2(){return &this->readData2;}

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            regs[(*writeRegister)] = *writeData;

        }else{
            //descida do clock
            //lê dos registradores
            readData1 = regs[(*readRegister1)];
            readData2 = regs[(*readRegister2)];
        }
    }

};


#endif //COMPUTER_ARCHITECTURE_BANCOREG_H
