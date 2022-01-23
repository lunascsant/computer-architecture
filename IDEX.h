//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IDEX_H
#define COMPUTER_ARCHITECTURE_IDEX_H


class IDEX {
private:

    //inputs

    int* regDstIn;
    int* branchIn;
    int* memReadIn;
    int* memWriteIn;
    int* memToRegIn;
    int* ALUOp0In;
    int* ALUOp1In;
    int* ALUSrcIn;
    int* regWriteIn;
    int* PCSrcIn;

    unsigned int* readData1In;
    unsigned int* readData2In;
    unsigned int* nextInstIn;
    unsigned int* immediateIn;

    //registers

    int regDst;
    int branch;
    int memRead;
    int memWrite;
    int memToReg;
    int ALUOp0;
    int ALUOp1;
    int ALUSrc;
    int regWrite;
    int PCSrc;

    unsigned int readData1;
    unsigned int readData2;
    unsigned int nextInst;
    unsigned int immediate;

    //outputs

    int regDstOut;
    int branchOut;
    int memReadOut;
    int memWriteOut;
    int memToRegOut;
    int ALUOp0Out;
    int ALUOp1Out;
    int ALUSrcOut;
    int regWriteOut;
    int PCSrcOut;
    unsigned int readData1Out;
    unsigned int readData2Out;
    unsigned int nextInstOut;
    unsigned int immediateOut;

public:
    IDEX();
    void setRegDstIn(int* newSignal);
    void setALUOp0In(int* newSignal);
    void setALUOp1In(int* newSignal);
    void setBranchIn(int* newSignal);
    void setMemReadIn(int* newSignal);
    void setMemWriteIn(int* newSignal);
    void setMemToRegIn(int* newSignal);
    void setALUSrcIn(int* newSignal);
    void setRegWriteIn(int* newSignal);
    void setPCSrcIn(int* newSignal);
    void setReadData1(unsigned int* newReadData);
    void setReadData2(unsigned int* newReadData);
    void setNextInst(unsigned int* newNextInst);
    void setImmediate(unsigned int* newImmediate);

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->regDst = *regDstIn;
            this->branch = *branchIn;
            this->memRead = *memReadIn;
            this->memWrite = *memWriteIn;
            this->memToReg = *memToRegIn;
            this->ALUOp0 = *ALUOp0In;
            this->ALUOp1 = *ALUOp1In;
            this->ALUSrc = *ALUSrcIn;
            this->regWrite = *regWriteIn;
            this->PCSrc = *PCSrcIn;
            this->readData1 = *readData1In;
            this->readData2 = *readData2In;
        }else{
            //descida do clock
            //lê dos registradores
            this->regDstOut = regDst;
            this->branchOut = branch;
            this->memReadOut = memRead;
            this->memWriteOut = memWrite;
            this->memToRegOut = memToReg;
            this->ALUOp0Out = ALUOp0;
            this->ALUOp1Out = ALUOp1;
            this->ALUSrcOut = ALUSrc;
            this->regWriteOut = regWrite;
            this->PCSrcOut = PCSrc;
            this->readData1Out = readData1;
            this->readData2Out = readData2;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IDEX_H
