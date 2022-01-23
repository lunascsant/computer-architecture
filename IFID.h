//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IFID_H
#define COMPUTER_ARCHITECTURE_IFID_H


class IFID {
private:


    //inputs
    int* instructionIn;
    int* nextInstIn;

    //registers
    int instruction;
    int opcode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    int immediate;
    int address;
    int nextInst;

    //outputs
    int instructionOut;
    int opCodeOut;
    int rsOut;
    int rtOut;
    int rdOut;
    int shamtOut;
    int functOut;
    int immediateOut;
    int addressOut;
    int nextInstOut;
public:
    IFID();
    void setInstructionIn(int* newInst);
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
    void setNextInst();
    int* getOpCodeOut();
    int* getRsOut();
    int* getRtOut();
    int* getRdOut();
    int* getShamtOut();
    int* getFunctOut();
    int* getImmediateOut();
    int* getAddressOut();
    int* getNextInstOut();*/
    void divideInstrução();

    void tickClock(int val){

        if(val==1){
            //subida do clock
            //escreve nos registradores
            this->instruction  = *instructionIn;
            this->nextInst = *nextInst;
            // outros registradores preenchidos:
            divideInstrução();
        }else{
            //descida do clock
            //lê dos registradores
            this->instructionOut = *instruction;
            // depende da instrução
            this->opCodeOut = *opcode;
            this->rsOut = *rs;
            this->rtOut = *rt;
            this->rdOut = *rd;
            this->shamtOut = *shamt;
            this->functOut = *funct;
            this->immediateOut = *immediate;
            this->addressOut = *address;
            this->nextInstOut = *nextInst;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IFID_H
