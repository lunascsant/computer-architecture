//
// Created by patri on 21/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_ALUCONTROL_H
#define COMPUTER_ARCHITECTURE_ALUCONTROL_H


class ALUControl {
private:
    //control signals
    unsigned int* aluOp;
    unsigned int* functField;

    //ALUOp
    //todo: make static
    unsigned int sw_lw_addi = 0;//00
    unsigned int beq = 1;       //01
    unsigned int r_type = 2;    //10
    unsigned int bne = 3;       //11

    //Funct field
    //todo: make static
    unsigned int add = 32;      //100000
    unsigned int subtract = 34; //100010
    unsigned int and_op = 36;   //100100
    unsigned int or_op = 37;    //100101
    unsigned int slt = 42;      //101010
    unsigned int sll = 0;       //000000

    //output
    unsigned int output=0;

public:
    ALUControl(unsigned int* aluOp, unsigned int* functField){
        this->aluOp=aluOp;
        this->functField=functField;
    }

    void tickClock(int val){
        //functField na verdade é o campo immediate inteiro, ajuste abaixo
        unsigned int functFieldAjustado = *functField & 63;

        if(val==1){
            if(*aluOp == sw_lw_addi){
                output = 2; //0010
            }else if(*aluOp == beq){
                output = 6; //0110
            }else if(*aluOp == bne){
                output = 5; //0101
            }else if(*aluOp==r_type && functFieldAjustado==add){
                output = 2; //0010
            }else if(*aluOp==r_type && functFieldAjustado==subtract){
                output = 6; //0110
            }else if(*aluOp==r_type && functFieldAjustado==and_op){
                output =  0;//0000
            }else if(*aluOp==r_type && functFieldAjustado==or_op){
                output =  1;//0001
            }else if(*aluOp==r_type && functFieldAjustado==slt){
                output = 7; //0111
            }else if(*aluOp==r_type && functFieldAjustado==sll){
                output = 8; //1000
            }

        }
    }
    unsigned int* getOutput(){
        return &this->output;
    }

};


#endif //COMPUTER_ARCHITECTURE_ALUCONTROL_H
