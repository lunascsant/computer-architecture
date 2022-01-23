//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_CONTROL_H
#define COMPUTER_ARCHITECTURE_CONTROL_H


class Control {
private:
    int* instruction;

    // sinais:

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

    // output

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
    // métodos
    Control();
    void setRegDst(int newSignal);
    void setJump(int newSignal);
    void setBranch(int newSignal);
    void setMemRead(int newSignal);
    void setMemWrite(int newSignal);
    void setMemToReg(int newSignal);
    void setALUOp0(int newSignal);
    void setALUOp1(int newSignal);
    void setALUSrc(int newSignal);
    void setRegWrite(int newSignal);
    void setPCSrc(int newSignal);

    int* getRegDst();
    int* getJump();
    int* getBranch();
    int* getMemRead();
    int* getMemWrite();
    int* getMemToReg();
    int* getALUOp0();
    int* getALUOp1();
    int* getALUSrc();
    int* getRegWrite();
    int* getPCSrc();

    void defineSinais();

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            defineSinais();
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


#endif //COMPUTER_ARCHITECTURE_CONTROL_H
