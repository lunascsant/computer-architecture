//
// Created by patri on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_MEM_WB_H
#define COMPUTER_ARCHITECTURE_MEM_WB_H


class MEM_WB {
private:

    //inputs
    int *memToRegIn;
    int *regWriteIn;
    unsigned int* aluOutIn;
    unsigned int* readDataIn;
    unsigned int* writeRegisterIn;

    //registers
    int memToRegReg;
    int regWriteReg;
    unsigned int aluOutReg;
    unsigned int readDataReg;
    unsigned int writeRegisterReg;

    //outputs
    int memToRegOut;
    int regWriteOut;
    unsigned int aluOutOut;
    unsigned int readDataOut;
    unsigned int writeRegisterOut;

public:
    MEM_WB(int* memToReg, int *regWrite, unsigned int* readData, unsigned int* aluOut, unsigned int* writeRegister){
        this->memToRegIn = memToReg;
        this->regWriteIn = regWrite;
        this->readDataIn = readData;
        this->aluOutIn = aluOut;
        this->writeRegisterIn = writeRegister;
    }
    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->memToRegReg = *memToRegIn;
            this->regWriteReg = *regWriteIn;
            this->readDataReg = *readDataIn;
            this->aluOutReg = *aluOutIn;
            this->writeRegisterReg = *writeRegisterIn;

        }else{
            //descida do clock
            //lê dos registradores

            this->memToRegOut = memToRegReg;
            this->regWriteOut = regWriteReg;
            this->readDataOut = readDataReg;
            this->aluOutOut = aluOutReg;
            this->writeRegisterOut = writeRegisterReg;


        }
    }
    int* getMemToReg(){ return &this->memToRegOut;}
    int* getRegWrite(){ return &this->regWriteOut;}
    unsigned int* getAluOut(){ return &this->aluOutOut;}
    unsigned int* getReadData(){ return &this->readDataOut;}
    unsigned int* getWriteRegisterReg(){ return &this->writeRegisterOut;}

};


#endif //COMPUTER_ARCHITECTURE_MEM_WB_H
