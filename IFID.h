//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IFID_H
#define COMPUTER_ARCHITECTURE_IFID_H


class IFID {
private:
    int* instruction;
    int opcode;
    int rs;
    int rt;
    int rd;
    int shamt;
    int funct;
    int immediate;
    int address;
    int nextInst;
public:
    IFID();
    void setInstruction(int* newInst);
    int* getOpcode();
    int* getRs();
    int* getRt();
    int* getRd();
    int* getShamt();
    int* getFunct();
    int* getImmediate();
    int* getAddress();
    int* getNextInst();
};


#endif //COMPUTER_ARCHITECTURE_IFID_H
