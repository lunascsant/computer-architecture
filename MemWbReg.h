//
// Created by patri on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_MEMWBREG_H
#define COMPUTER_ARCHITECTURE_MEMWBREG_H


class MemWbReg {
private:

    //inputs
    int *memToReg;
    int *regWrite;
    unsigned int* aluOut;
    unsigned int* readData;
    unsigned int* writeRegister;

    //registers
    int memToRegReg;
    int regWriteReg;
    unsigned int aluOutReg;
    unsigned int readDataReg;
    unsigned int writeRegisterReg;

public:
    MemWbReg(int* memToReg, int *regWrite, unsigned int* readData, unsigned int* aluOut, unsigned int* writeRegister){
        this->memToReg = memToReg;
        this->regWrite = regWrite;
        this->readData = readData;
        this->aluOut = aluOut;
        this->writeRegister = writeRegister;
    }
    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->memToRegReg = *memToReg;
            this->regWriteReg = *regWrite;
            this->readDataReg = *readData;
            this->aluOutReg = *aluOut;
            this->writeRegisterReg = *writeRegister;

        }else{
            //descida do clock
            //lê dos registradores

        }
    }
    int* getMemToReg(){ return &this->memToRegReg;}
    int* getRegWrite(){ return &this->regWriteReg;}
    unsigned int* getAluOut(){ return &this->aluOutReg;}
    unsigned int* getReadData(){ return &this->readDataReg;}
    unsigned int* getWriteRegisterReg(){ return &this->writeRegisterReg;}



};


#endif //COMPUTER_ARCHITECTURE_MEMWBREG_H
