//
// Created by lucia on 22/01/2022.
//

#include "Control.h"

Control::Control() {
    this->regDst = 0;
    this->memRead = 0;
    this->memWrite = 0;
    this->ALUOp0 = 0;
    this->ALUOp1 = 0;
    this->ALUSrc = 0;
    this->branch = 0;
    this->jump = 0;
    this->memToReg = 0;
    this->regWrite = 0;
}

void Control::setRegDst(bool newSignal) {
    this->regDst = newSignal;
}

void Control::setJump(bool newSignal) {
    this->jump = newSignal;
}

void Control::setBranch(bool newSignal) {
    this->branch = newSignal;
}

void Control::setMemRead(bool newSignal) {
    this->memRead = newSignal;
}

void Control::setMemWrite(bool newSignal) {
    this->memWrite = newSignal;
}

void Control::setMemToReg(bool newSignal) {
    this->memToReg = newSignal;
}

void Control::setALUOp0(bool newSignal) {
    this->ALUOp0 = newSignal;
}

void Control::setALUOp1(bool newSignal) {
    this->ALUOp1 = newSignal;
}

void Control::setALUSrc(bool newSignal) {
    this->ALUSrc = newSignal;
}

void Control::setRegWrite(bool newSignal) {
    this->regWrite = newSignal;
}

void Control::setPCSrc(bool newSignal) {
    this->PCSrc = newSignal;
}