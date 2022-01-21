//
// Created by patri on 20/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_BANCOREG_H
#define COMPUTER_ARCHITECTURE_BANCOREG_H


class BancoReg {

private:
    int regs[32];
    int* regWrite;
    int readRegister1;
    int readRegister2;
    int writeRegister;
    int writeData;
    int readData1;
    int readData2;
public:
    BancoReg(int *regWrite){this->regWrite=regWrite;}
    ~BancoReg()= default;
    void setReadRegister1(int val){ this->readRegister1 = val;}
    void setReadRegister2(int val){ this->readRegister2 = val;}
    void setWriteRegister(int val){ this->writeRegister = val;}
    void setWriteData(int val){ this->writeData = val;}
    int getReadData1(){return this->readData1;}
    int getReadData2(){return this->readData2;}

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


#endif //COMPUTER_ARCHITECTURE_BANCOREG_H
