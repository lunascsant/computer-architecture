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
    unsigned int sw_lw = 0; //00
    unsigned int beq = 1;   //01
    unsigned int r_type = 2;//10

    //Funct field
    unsigned int add = 32;      //100000
    unsigned int subtract = 34; //100010
    unsigned int and_op = 36;   //100100
    unsigned int or_op = 37;    //100101
    unsigned int slt = 42;      //101010

public:
    ALUControl(unsigned int* aluOp, unsigned int* functField){
        this->aluOp=aluOp;
        this->functField=functField;
    }

    unsigned int getALUControlInput(){
        if(*aluOp == sw_lw){
            return 2; //0010
        }else if(*aluOp == beq){
            return 6; //0110
        }else if(*aluOp==r_type && *functField==add){
            return 2; //0010
        }else if(*aluOp==r_type && *functField==subtract){
            return 6; //0110
        }else if(*aluOp==r_type && *functField==and_op){
            return  0;//0000
        }else if(*aluOp==r_type && *functField==or_op){
            return  1;//0001
        }else if(*aluOp==r_type && *functField==slt){
            return 7; //0111
        }

        return 0;
    }

};


#endif //COMPUTER_ARCHITECTURE_ALUCONTROL_H
