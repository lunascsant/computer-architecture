//
// Created by lucia on 22/01/2022.
//

#include "Control.h"

Control::Control() {
    this->regDstOut = 0;
    this->branchOut = 0;
    this->memReadOut = 0;
    this->memWriteOut = 0;
    this->memToRegOut = 0;
    this->ALUOpOut = 0;
    this->ALUSrcOut = 0;
    this->regWriteOut = 0;
    this->PCSrcOut = 0;
}

void Control::defineSinais() {
    // define sinais baseado na instrução
    if (*this->opcode == 0) { //000000 - tipo r
        this->regDstOut = 1;
        this->ALUOpOut = 2;//10
        this->ALUSrcOut = 0;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 1;
        // professor aula 17 tabela errada
        this->memToRegOut = 0;
    } else if (*this->opcode == 35) {//100011 - lw
        this->regDstOut = 0;
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 1;
        this->branchOut = 0;
        this->memReadOut = 1;
        this->memWriteOut = 0;
        this->regWriteOut = 1;
        // professor aula 17 tabela errada
        this->memToRegOut = 1;
    } else if (*this->opcode == 43) {//101011 - sw
        this->regDstOut = 0;
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 1;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 1;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
    } else if (*this->opcode == 4) { //000100 - beq
        this->regDstOut = 0;
        this->ALUOpOut = 1;//01
        this->ALUSrcOut = 0;
        this->branchOut = 1;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
    }
}
