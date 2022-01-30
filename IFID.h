//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IFID_H
#define COMPUTER_ARCHITECTURE_IFID_H


class IFID {
private:


    //inputs
    unsigned int* instructionIn;
    unsigned int* nextInstIn;

    //registers
    unsigned int instruction;
    unsigned int nextInst;

    //outputs
    unsigned int instructionOut = 0;
    unsigned int opCodeOut = 0;
    unsigned int rsOut = 0;
    unsigned int rtOut = 0;
    unsigned int rdOut = 0;
    unsigned int immediateOut = 0;
    unsigned int nextInstOut = 0;
    unsigned int shamtOut = 0;
    unsigned int jumpAddressOut = 0;
    unsigned int PCUltimos4Out = 0;

public:
    IFID();
    void setInstructionIn(unsigned int* newInstruction) { this->instructionIn = newInstruction; }
    void setNextInstIn(unsigned int* newInst) { this->nextInstIn = newInst; }
    /*
    int getOpCode();
    int getRs();
    int getRt();
    int getRd();
    int getShamt();
    int getFunct();
    int getImmediate();
    int getAddress();
    int getNextInst();
    void setOpCode();
    void setRs();
    void setRt();
    void setRd();
    void setShamt();
    void setFunct();
    void setImmediate();
    void setAddress();
    void setNextInst();*/
    unsigned int* getOpCodeOut(){ return &this->opCodeOut; }
    unsigned int* getRsOut() { return &this->rsOut; }
    unsigned int* getRtOut() { return &this->rtOut; }
    unsigned int* getRdOut() { return &this->rdOut; }
    unsigned int* getImmediateOut() { return &this->immediateOut; }
    unsigned int* getNextInstOut() { return  &this->nextInstOut; }
    unsigned int* getShamtOut() { return &this->shamtOut; }
    unsigned int* getJumpAddressOut() { return &this->jumpAddressOut; }
    unsigned int* getPCUltimos4Out() { return &this->PCUltimos4Out; }
    void divideInstrucao();

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->instruction  = *instructionIn;
            this->nextInst = *nextInstIn;
            // outros registradores preenchidos:

        }else{
            //descida do clock
            //lê dos registradores
            this->instructionOut = instruction;
            divideInstrucao();
            // depende da instrução

            this->nextInstOut = nextInst;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IFID_H
