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
    unsigned int* ALUOpIn;
    int* ALUSrcIn;
    int* regWriteIn;
    int* PCSrcIn;

    unsigned int* readData1In;
    unsigned int* readData2In;
    unsigned int* nextInstIn;
    unsigned int* immediateIn;
    unsigned int* rtIn;
    unsigned int* rdIn;

    //registers

    int regDst;
    int branch;
    int memRead;
    int memWrite;
    int memToReg;
    unsigned int ALUOp;
    int ALUSrc;
    int regWrite;
    int PCSrc;

    unsigned int readData1;
    unsigned int readData2;
    unsigned int nextInst;
    unsigned int immediate;
    unsigned int rt;
    unsigned int rd;

    //outputs

    int regDstOut;
    int branchOut;
    int memReadOut;
    int memWriteOut;
    int memToRegOut;
    unsigned int ALUOpOut;
    int ALUSrcOut;
    int regWriteOut;
    int PCSrcOut;
    unsigned int readData1Out;
    unsigned int readData2Out;
    unsigned int nextInstOut;
    unsigned int immediateOut;
    unsigned int rtOut;
    unsigned int rdOut;

public:
    IDEX();
    void setRegDstIn(int* newSignal);
    void setALUOpIn(unsigned int* newSignal);
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
    void setRdIn(unsigned int* newRd);
    void setRtIn(unsigned int* newRt);

    int *getRegDstIn();
    int *getRegDstOut();
    int *getBranchOut();
    int *getMemReadOut();
    int *getMemWriteOut();
    int *getMemToRegOut();
    unsigned int *getAluOpOut();
    int *getAluSrcOut();
    int *getRegWriteOut();
    int *getPcSrcOut();
    unsigned int *getReadData1Out();
    unsigned int *getReadData2Out();
    unsigned int *getNextInstOut();
    unsigned int *getImmediateOut();
    unsigned int *getRdOut();
    unsigned int *getRtOut();

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->regDst = *regDstIn;
            this->branch = *branchIn;
            this->memRead = *memReadIn;
            this->memWrite = *memWriteIn;
            this->memToReg = *memToRegIn;
            this->ALUOp = *ALUOpIn;
            this->ALUSrc = *ALUSrcIn;
            this->regWrite = *regWriteIn;
            this->PCSrc = *PCSrcIn;
            this->readData1 = *readData1In;
            this->readData2 = *readData2In;
            this->immediate = *immediateIn;
            this->rd = *rdIn;
            this->nextInst = *nextInstIn;
            this->rt = *rtIn;
        }else{
            //descida do clock
            //lê dos registradores
            this->regDstOut = regDst;
            this->branchOut = branch;
            this->memReadOut = memRead;
            this->memWriteOut = memWrite;
            this->memToRegOut = memToReg;
            this->ALUOpOut = ALUOp;
            this->ALUSrcOut = ALUSrc;
            this->regWriteOut = regWrite;
            this->PCSrcOut = PCSrc;
            this->readData1Out = readData1;
            this->readData2Out = readData2;
            this->immediateOut = immediate;
            this->rdOut = rd;
            this->nextInstOut = nextInst;
            this->rtOut = rt;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IDEX_H
