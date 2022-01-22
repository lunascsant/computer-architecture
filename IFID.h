//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IFID_H
#define COMPUTER_ARCHITECTURE_IFID_H


class IFID {
private:
    string instruction;
    string opcode;
    string rs;
    string rt;
    string rd;
    string shamt;
    string funct;
    string immediate;
    string address;
    int nextInst;
public:
    IFID();
};


#endif //COMPUTER_ARCHITECTURE_IFID_H
