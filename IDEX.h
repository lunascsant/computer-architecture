//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IDEX_H
#define COMPUTER_ARCHITECTURE_IDEX_H


class IDEX {
private:

    //inputs

    int regDstIn;
    int jumpIn; // n sei se entra esse
    int branchIn;
    int memReadIn;
    int memWriteIn;
    int memToRegIn;
    int ALUOp0In;
    int ALUOp1In;
    int ALUSrcIn;
    int regWriteIn;
    int PCSrcIn;

    //registers

    int regDst;
    int jump; // n sei se entra esse
    int branch;
    int memRead;
    int memWrite;
    int memToReg;
    int ALUOp0;
    int ALUOp1;
    int ALUSrc;
    int regWrite;
    int PCSrc;

    //outputs

    int regDstOut;
    int jumpOut; // n sei se entra esse
    int branchOut;
    int memReadOut;
    int memWriteOut;
    int memToRegOut;
    int ALUOp0Out;
    int ALUOp1Out;
    int ALUSrcOut;
    int regWriteOut;
    int PCSrcOut;

public:
    IDEX();
    void setRegDst(int newSignal);
    void setALUOp0(int newSignal);
    void setALUOp1(int newSignal);
    void setALUSrc(int newSignal);
    void getRegDst();
    void getALUOp0();
    void getALUOp1();
    void getALUSrc();

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->regDst = *regDstIn;
            this->jump = *jumpIn; // n sei se entra esse
            this->branch = *branchIn;
            this->memRead = *memReadIn;
            this->memWrite = *memWriteIn;
            this->memToReg = *memToRegIn;
            this->ALUOp0 = *ALUOp0In;
            this->ALUOp1 = *ALUOp1In;
            this->ALUSrc = *ALUSrcIn;
            this->regWrite = *regWriteIn;
            this->PCSrc = *PCSrcIn;
        }else{
            //descida do clock
            //lê dos registradores
            this->regDstOut = *regDst;
            this->jumpOut = *jump; // n sei se entra esse
            this->branchOut = *branch;
            this->memReadOut = *memRead;
            this->memWriteOut = *memWrite;
            this->memToRegOut = *memToReg;
            this->ALUOp0Out = *ALUOp0;
            this->ALUOp1Out = *ALUOp1;
            this->ALUSrcOut = *ALUSrc;
            this->regWriteOut = *regWrite;
            this->PCSrcOut = *PCSrc;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IDEX_H
