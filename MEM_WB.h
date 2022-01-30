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
    unsigned int* nextInstIn;

    //registers
    int memToRegReg;
    int regWriteReg;
    unsigned int aluOutReg;
    unsigned int readDataReg;
    unsigned int writeRegisterReg;
    unsigned int nextInst;

    //outputs
    int memToRegOut=0;
    int regWriteOut=0;
    unsigned int aluOutOut=0;
    unsigned int readDataOut=0;
    unsigned int writeRegisterOut=0;
    unsigned int nextInstOut=0;

public:
    MEM_WB(int* memToReg, int *regWrite, unsigned int* readData, unsigned int* aluOut, unsigned int* writeRegister){
        this->memToRegIn = memToReg;
        this->regWriteIn = regWrite;
        this->readDataIn = readData;
        this->aluOutIn = aluOut;
        this->writeRegisterIn = writeRegister;
    }

    MEM_WB(int* memToReg, int *regWrite){
        this->memToRegIn = memToReg;
        this->regWriteIn = regWrite;
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
    void setRegWriteIn(int *newSignal){ this->regWriteIn = newSignal; }
    void setMemToRegIn(int *newSignal){ this->memToRegIn = newSignal; }
    void setReadDataIn(unsigned int *newSignal){ this->readDataIn = newSignal; }
    void setAluOutIn(unsigned int *newSignal){ this->aluOutIn = newSignal; }
    void setWriteRegisterIn(unsigned int *newSignal){ this->writeRegisterIn = newSignal; }
    void setNextInstIn(unsigned int *newSignal){ this->nextInstIn = newSignal; }

    int* getMemToReg(){ return &this->memToRegOut;}
    int* getRegWrite(){ return &this->regWriteOut;}
    unsigned int* getAluOut(){ return &this->aluOutOut;}
    unsigned int* getReadData(){ return &this->readDataOut;}
    unsigned int* getWriteRegisterReg(){ return &this->writeRegisterOut;}
    unsigned int* getNextInstOut(){ return &this->nextInstOut; }

};


#endif //COMPUTER_ARCHITECTURE_MEM_WB_H
