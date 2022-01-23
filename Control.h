//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_CONTROL_H
#define COMPUTER_ARCHITECTURE_CONTROL_H


class Control {
private:
    unsigned int* opcode;

    // output

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

public:
    // métodos
    Control();

    void defineSinais();
    void setOpcode(unsigned int* newOpcode) { this->opcode = newOpcode; }
    int* getRegDst() { return &this->regDstOut; }
    int* getBranch() { return &this->branchOut; }
    int* getMemRead() { return &this->memReadOut; }
    int* getMemWrite() { return &this->memWriteOut; }
    int* getMemToReg() { return &this->memToRegOut; }
    int* getALUOp0() { return &this->ALUOp0Out;}
    int* getALUOp1(){return &this->ALUOp1Out; }
    int* getALUSrc(){return &this->ALUSrcOut; }
    int* getRegWrite(){return &this->regWriteOut; }
    int* getPCSrc(){return &this->PCSrcOut;}

    void tickClock(int val){

        if(val==1){
            //subida do clock
            defineSinais();
        }else{
            //descida do clock
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_CONTROL_H
