//
// Created by patri on 20/01/2022.
//

#include "BancoReg.h"

using namespace std;

BancoReg::BancoReg(){
    //teste, remover depois
    regs[1] = 1;
    regs[2] = 2;
    regs[3] = 10;
    regs[4] = 11;
    regs[5] = 0;
    regs[6] = 0;
    regs[7] = 0;
    regs[8] = 0;
    regs[9] = 3;
    //
}

void BancoReg::tickClock(int val){

    if(val==1){
        //subida do clock
        //escreve nos registradores
        regs[(*writeRegisterIn)] = *writeDataIn;

    }else{
        //descida do clock
        //lê dos registradores
        readData1 = regs[(*readRegister1In)];
        readData2 = regs[(*readRegister2In)];
    }
}


string BancoReg::printState(){
    string state;
    state+="$zero: " + regs[0];


}