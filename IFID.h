//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IFID_H
#define COMPUTER_ARCHITECTURE_IFID_H


class IFID {
private:


    //inputs
    unsigned int* instructionIn;
    int* nextInstIn;

    //registers
    unsigned int instruction;
    int nextInst;

    //outputs
    unsigned int instructionOut;
    unsigned int opCodeOut;
    unsigned int rsOut;
    unsigned int rtOut;
    unsigned int rdOut;
    unsigned int immediateOut;
    unsigned int nextInstOut;
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
            this->nextInst = *nextInstIn;
            // outros registradores preenchidos:

        }else{
            //descida do clock
            //lê dos registradores
            this->instructionOut = instruction;
            divideInstrução();
            // depende da instrução

            this->nextInstOut = nextInst;
        }
    }
};


#endif //COMPUTER_ARCHITECTURE_IFID_H
