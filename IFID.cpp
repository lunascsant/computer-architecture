//
// Created by lucia on 22/01/2022.
//

#include "IFID.h"

IFID::IFID() {

}

void IFID::setInstruction(int* newInst) {
    this->instruction = newInst;
}

int* IFID::getOpcode() {
    return &this->opcode;
}

int* IFID::getRs() {
    return &this->rs;
}

int* IFID::getRt() {
    return &this->rt;
}

int* IFID::getRd() {
    return &this->rd;
}

int* IFID::getShamt() {
    return &this->shamt;
}

int* IFID::getFunct() {
    return &this->funct;
}

int* IFID::getImmediate() {
    return  &this->immediate;
}

int* IFID::getAddress() {
    return  &this->address;
}

int* IFID::getNextInst() {
    return &this->nextInst;
}