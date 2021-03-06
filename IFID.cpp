//
// Created by lucia on 22/01/2022.
//

#include "IFID.h"

IFID::IFID() {
    this->opCodeOut = 0;
    this->rsOut = 0;
    this->rtOut = 0;
    this->rdOut = 0;
    this->immediateOut = 0;
    this->nextInstOut = 0;
    this->jumpAddressOut = 0;
}

void IFID::divideInstrucao() {

    unsigned int primeiros16 = 65535;//1111111111111111
    unsigned int primeiros6 = 63;//111111
    unsigned int primeiros5 = 31;//011111
    unsigned int primeiros26 = 67108863;//11111111111111111111111111

    this->opCodeOut = this->instruction >> 26;
    this->rsOut = (this->instruction >> 21) & primeiros5;
    this->rtOut = (this->instruction  >> 16) & primeiros5;
    this->rdOut = (this->instruction  >> 11) & primeiros5;
    this->immediateOut = this->instruction & primeiros16;
    this->shamtOut = (this->instruction  >> 6) & primeiros5;
    this->jumpAddressOut = this->instruction & primeiros26;
    this->PCUltimos4Out = (nextInst >> 28) <<28;//11110000000000000000000000000000;

    //extensão de sinal
    if(this->immediateOut >> 15 == 1){
        //11111111111111110000000000000000
        this->immediateOut += 4294901760;
    }
}