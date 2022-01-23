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
/*

void Control::setRegDst(int newSignal) {
    this->regDst = newSignal;
}

void Control::setJump(int newSignal) {
    this->jump = newSignal;
}

void Control::setBranch(int newSignal) {
    this->branch = newSignal;
}

void Control::setMemRead(int newSignal) {
    this->memRead = newSignal;
}

void Control::setMemWrite(int newSignal) {
    this->memWrite = newSignal;
}

void Control::setMemToReg(int newSignal) {
    this->memToReg = newSignal;
}

void Control::setALUOp0(int newSignal) {
    this->ALUOp0 = newSignal;
}

void Control::setALUOp1(int newSignal) {
    this->ALUOp1 = newSignal;
}

void Control::setALUSrc(int newSignal) {
    this->ALUSrc = newSignal;
}

void Control::setRegWrite(int newSignal) {
    this->regWrite = newSignal;
}

void Control::setPCSrc(int newSignal) {
    this->PCSrc = newSignal;
}

int* Control::getRegDst() {
    return &this->regDst;
}

int* Control::getJump() {
    return &this->jump;
}

int* Control::getBranch() {
    return &this->branch;
}

int* Control::getMemRead() {
    return &this->memRead;
}

int* Control::getMemWrite() {
    return &this->memWrite;
}

int* Control::getMemToReg() {
    return &this->memToReg;
}

int* Control::getALUOp0() {
    return &this->ALUOp0;
}

int* Control::getALUOp1() {
    return &this->ALUOp1;
}

int* Control::getALUSrc() {
    return &this->ALUSrc;
}

int* Control::getRegWrite() {
    return &this->regWrite;
}

int* Control::getPCSrc() {
    return &this->PCSrc;
}*/

void Control::defineSinais() {
    // define sinais baseado na instrução
}
