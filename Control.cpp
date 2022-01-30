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
    this->jumpOut = 0;
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
        this->jumpOut = 0;
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
        this->jumpOut = 0;
    } else if (*this->opcode == 43) {//101011 - sw
        this->regDstOut = 0;
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 1;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 1;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
        this->jumpOut = 0;
    } else if (*this->opcode == 4) { //000100 - beq
        this->regDstOut = 0;
        this->ALUOpOut = 1;//01
        this->ALUSrcOut = 0;
        this->branchOut = 1;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
        this->jumpOut = 0;
    } else if (*this->opcode == 8) { //001000 - addi
        this->regDstOut = 0;
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 1;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 1;
        this->memToRegOut = 0;
        this->jumpOut = 0;
    } else if (*this->opcode == 5) { //000101 - bne
        this->regDstOut = 0;
        this->ALUOpOut = 3;//11
        this->ALUSrcOut = 0;
        this->branchOut = 1;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
        this->jumpOut = 0;
    } else if (*this->opcode == 2) { //000010 - jump
        this->regDstOut = 0;
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 0;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 0;
        this->memToRegOut = 0;
        this->jumpOut = 1;
    }
    else if (*this->opcode == 3) { //000011 - jal
        this->regDstOut = 2;//10
        this->ALUOpOut = 0;//00
        this->ALUSrcOut = 0;
        this->branchOut = 0;
        this->memReadOut = 0;
        this->memWriteOut = 0;
        this->regWriteOut = 1;
        this->memToRegOut = 2;//10
        this->jumpOut = 1;
    }

}
