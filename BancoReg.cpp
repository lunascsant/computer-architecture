//
// Created by patri on 20/01/2022.
//

#include "BancoReg.h"
#include <array>

using namespace std;


array<string, 32> BancoReg::regNames =
        {"zero", "at", "v0", "v1",
         "a0", "a1", "a2", "a3",
         "t0", "t1", "t2", "t3",
         "t4", "t5","t6", "t7",
         "s0", "s1", "s2", "s3",
         "s4", "s5", "s6", "s7",
         "t8", "t9", "k0", "k1",
         "gp", "sp","fp", "ra"
        };

BancoReg::BancoReg(){
    regs[0]=0;

    for(int i=1; i<32; i++){
        regs[i] = (1000 + i)*(i%2 == 0 ? -1 : 1);
    }

    regs[29] = 508;
}

void BancoReg::tickClock(int val){

    if(val==1){
        //subida do clock
        //escreve nos registradores
        if(*writeRegisterIn!=0 && *regWrite ==1){//ignora se tentar escrever no reg $zero
            regs[(*writeRegisterIn)] = *writeDataIn;
        }

    }else{
        //descida do clock
        //lê dos registradores
        readData1 = regs[(*readRegister1In)];
        readData2 = regs[(*readRegister2In)];
    }
}

void BancoReg::resetBancoReg() {
    for (int i = 1; i < 32; i++) {
        if (i == 29) { //registrador sp volta ao estado inicial
            this->regs[i] = 508;
        }
        else {
            this->regs[i] = 0;
        }
    }
}

string BancoReg::getState(){


    string state;
    char partStr[50];

    for(int i=0; i<32; i++){

        sprintf(partStr, "$%-4s: %-11d | ",  regNames[i].c_str(), (int)regs[i]);
        state.append(partStr);
        
        if((i+1)%4==0){
            state.append("\n");
        }
    }

    return state;
}