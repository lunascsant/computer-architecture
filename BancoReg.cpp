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
    //teste, remover depois

    for(int i=1; i<32; i++){
        regs[i] = (1000 + i)*(i%2 == 0 ? -1 : 1);
    }

    regs[29] = 3;
    /*regs[1] = 1001;
    regs[2] = 1002;
    regs[3] = 10;
    regs[4] = 11;
    regs[5] = 0;
    regs[6] = 0;
    regs[7] = 0;
    regs[8] = 0;
    regs[9] = 3;*/
    //
}

void BancoReg::tickClock(int val){

    if(val==1){
        //subida do clock
        //escreve nos registradores
        if(*writeRegisterIn!=0){//ignora se tentar escrever no reg $zero
            regs[(*writeRegisterIn)] = *writeDataIn;
        }

    }else{
        //descida do clock
        //lê dos registradores
        readData1 = regs[(*readRegister1In)];
        readData2 = regs[(*readRegister2In)];
    }
}


string BancoReg::getState(){


    /*string state;
    char partStr[15];
    for(int i=0; i<32; i++){
       // state+="$" + regNames[i] +": " + to_string((int)regs[i]) + "\n";
        sprintf(partStr, "$%2s: %7d |",  regNames[i].c_str(), (int)regs[i]);
        state.append(partStr);
        if(i%4==0){
            state.append("\n");
        }
    }*/
    /*
    state+="$zero: " + to_string((int)regs[0]) + "\n";
    state+="$at: " + to_string((int)regs[1]) + "\n";
    state+="$v0: " + to_string((int)regs[2]) + "\n";
    state+="$v1: " + to_string((int)regs[3]) + "\n";
    state+="$a0: " + to_string((int)regs[4]) + "\n";
    state+="$a1: " + to_string((int)regs[5]) + "\n";
    state+="$a2: " + to_string((int)regs[6]) + "\n";
    state+="$a3: " + to_string((int)regs[7]) + "\n";
    state+="$t0: " + to_string((int)regs[8]) + "\n";
    state+="$t1: " + to_string((int)regs[9]) + "\n";
    state+="$t2: " + to_string((int)regs[10]) + "\n";
    state+="$t3: " + to_string((int)regs[11]) + "\n";
    state+="$t4: " + to_string((int)regs[12])+ "\n";
    state+="$t5: " + to_string((int)regs[13])+ "\n";
    state+="$t6: " + to_string((int)regs[14])+ "\n";
    state+="$t7: " + to_string((int)regs[15])+ "\n";
    state+="$s0: " + to_string((int)regs[16]) + "\n";
    state+="$s1: " + to_string((int)regs[17]) + "\n";
    state+="$s2: " + to_string((int)regs[18]) + "\n";
    state+="$s3: " + to_string((int)regs[19]) + "\n";
    state+="$s4: " + to_string((int)regs[20]) + "\n";
    state+="$s5: " + to_string((int)regs[21]) + "\n";
    state+="$s6: " + to_string((int)regs[22]) + "\n";
    state+="$s7: " + to_string((int)regs[23]) + "\n";
    state+="$t8: " + to_string((int)regs[24]) + "\n";
    state+="$t9: " + to_string((int)regs[25]) + "\n";
    state+="$k0: " + to_string((int)regs[26])+ "\n";
    state+="$k1: " + to_string((int)regs[27])+ "\n";
    state+="$gp: " + to_string((int)regs[28])+ "\n";
    state+="$sp: " + to_string((int)regs[29])+ "\n";
    state+="$fp: " + to_string((int)regs[30])+ "\n";
    state+="$ra: " + to_string((int)regs[31]) + "\n";*/

    //sprintf(partStr, "%s: %4c |",  nomes[i].c_str(), ' ');

    return "";

}