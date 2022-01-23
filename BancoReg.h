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
    unsigned int* readRegister1In;
    unsigned int* readRegister2In;
    unsigned int* writeRegisterIn;
    unsigned int* writeDataIn;

    //outputs
    unsigned int readData1;
    unsigned int readData2;

public:
    BancoReg(){}
    ~BancoReg()= default;
    void setRegWriteIn(int *regWrite){ this->regWrite=regWrite;}
    void setReadRegister1In(unsigned int* val){ this->readRegister1In = val;}
    void setReadRegister2In(unsigned int* val){ this->readRegister2In = val;}
    void setWriteRegisterIn(unsigned int* val){ this->writeRegisterIn = val;}
    void setWriteDataIn(unsigned int* val){ this->writeDataIn = val;}
    unsigned int* getReadData1(){return &this->readData1;}
    unsigned int* getReadData2(){return &this->readData2;}

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            regs[(*writeRegisterIn)] = *writeDataIn;

        }else{
            //descida do clock
            //lê dos registradores
            readData1 = regs[(*readRegister1In)];
            readData2 = regs[(*readRegister2In)];
        }
    }

};


#endif //COMPUTER_ARCHITECTURE_BANCOREG_H
