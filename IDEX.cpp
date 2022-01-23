//
// Created by lucia on 22/01/2022.
//

#include "IDEX.h"

IDEX::IDEX() {

}

void IDEX::setRegDstIn(int* newSignal) {
    this->regDstIn = newSignal;
}

void IDEX::setALUOp0In(int* newSignal) {
    this->ALUOp0In = newSignal;
}

void IDEX::setALUOp1In(int* newSignal) {
    this->ALUOp1In = newSignal;
}

void IDEX::setALUSrcIn(int* newSignal) {
    this->ALUSrcIn = newSignal;
}

void IDEX::setBranchIn(int* newSignal) {
    this->branchIn = newSignal;
}

void IDEX::setMemReadIn(int* newSignal) {
    this->memReadIn = newSignal;
}

void IDEX::setMemWriteIn(int* newSignal) {
    this->memWriteIn = newSignal;
}

void IDEX::setMemToRegIn(int* newSignal) {
    this->memToRegIn = newSignal;
}

void IDEX::setRegWriteIn(int* newSignal) {
    this->regWriteIn = newSignal;
}

void IDEX::setPCSrcIn(int* newSignal) {
    this->PCSrcIn = newSignal;
}

void IDEX::setReadData1(unsigned int* newReadData) {
    this->readData1In = newReadData;
}

void IDEX::setReadData2(unsigned int* newReadData) {
    this->readData2In = newReadData;
}

void IDEX::setNextInst(unsigned int *newNextInst) {
    this->nextInstIn = newNextInst;
}

void IDEX::setImmediate(unsigned int *newImmediate) {
    this->nextInstIn = newImmediate;
}

