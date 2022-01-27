//
// Created by lucia on 22/01/2022.
//

#include "IDEX.h"

IDEX::IDEX() {
    this->regDstOut = 0;
    this->branchOut = 0;
    this->memReadOut = 0;
    this->memWriteOut = 0;
    this->memToRegOut = 0;
    this->ALUOpOut = 0;
    this->ALUSrcOut = 0;
    this->regWriteOut = 0;
    this->PCSrcOut = 0;
    this->readData1Out = 0;
    this->readData2Out = 0;
    this->nextInstOut = 0;
    this->immediateOut = 0;
    this->rtOut = 0;
    this->rdOut = 0;
}

void IDEX::setRegDstIn(int* newSignal) {
    this->regDstIn = newSignal;
}

void IDEX::setALUOpIn(unsigned int* newSignal) {
    this->ALUOpIn = newSignal;
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


int* IDEX::getRegDstOut() {
    return &regDstOut;
}

int* IDEX::getBranchOut() {
    return &branchOut;
}

int* IDEX::getMemReadOut() {
    return &memReadOut;
}

int* IDEX::getMemWriteOut() {
    return &memWriteOut;
}

int* IDEX::getMemToRegOut() {
    return &memToRegOut;
}

unsigned int* IDEX::getAluOpOut() {
    return &ALUOpOut;
}

int* IDEX::getAluSrcOut() {
    return &ALUSrcOut;
}

int* IDEX::getRegWriteOut() {
    return &regWriteOut;
}

int* IDEX::getPcSrcOut() {
    return &PCSrcOut;
}

unsigned int* IDEX::getReadData1Out() {
    return &readData1Out;
}

unsigned int* IDEX::getReadData2Out() {
    return &readData2Out;
}

unsigned int* IDEX::getNextInstOut() {
    return &nextInstOut;
}

unsigned int* IDEX::getImmediateOut() {
    return &immediateOut;
}

unsigned int*  IDEX::getRdOut() {
    return &rdOut;
}

unsigned int*  IDEX::getRtOut() {
    return &rtOut;
}



