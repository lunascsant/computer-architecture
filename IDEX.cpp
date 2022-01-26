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


int* IDEX::getRegDstOut() const {
    return &regDstOut;
}

int* IDEX::getBranchOut() const {
    return &branchOut;
}

int* IDEX::getMemReadOut() const {
    return &memReadOut;
}

int* IDEX::getMemWriteOut() const {
    return &memWriteOut;
}

int* IDEX::getMemToRegOut() const {
    return &memToRegOut;
}

int* IDEX::getAluOp0Out() const {
    return &ALUOp0Out;
}

int* IDEX::getAluOp1Out() const {
    return &ALUOp1Out;
}

int* IDEX::getAluSrcOut() const {
    return &ALUSrcOut;
}

int* IDEX::getRegWriteOut() const {
    return &regWriteOut;
}

int* IDEX::getPcSrcOut() const {
    return &PCSrcOut;
}

unsigned int* IDEX::getReadData1Out() const {
    return &readData1Out;
}

unsigned int* IDEX::getReadData2Out() const {
    return &readData2Out;
}

unsigned int* IDEX::getNextInstOut() const {
    return &nextInstOut;
}

unsigned int* IDEX::getImmediateOut() const {
    return &immediateOut;
}

