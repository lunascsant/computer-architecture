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
    unsigned int sw_lw = 0; //00
    unsigned int beq = 1;   //01
    unsigned int r_type = 2;//10

    //Funct field
    //todo: make static
    unsigned int add = 32;      //100000
    unsigned int subtract = 34; //100010
    unsigned int and_op = 36;   //100100
    unsigned int or_op = 37;    //100101
    unsigned int slt = 42;      //101010

    //output
    unsigned int output=0;

public:
    ALUControl(unsigned int* aluOp, unsigned int* functField){
        this->aluOp=aluOp;
        this->functField=functField;
    }

    void tickClock(int val){
        if(val==0){
            if(*aluOp == sw_lw){
                output = 2; //0010
            }else if(*aluOp == beq){
                output = 6; //0110
            }else if(*aluOp==r_type && *functField==add){
                output = 2; //0010
            }else if(*aluOp==r_type && *functField==subtract){
                output = 6; //0110
            }else if(*aluOp==r_type && *functField==and_op){
                output =  0;//0000
            }else if(*aluOp==r_type && *functField==or_op){
                output =  1;//0001
            }else if(*aluOp==r_type && *functField==slt){
                output = 7; //0111
            }
        }
    }
    unsigned int* getOutput(){
        return &this->output;
    }

};


#endif //COMPUTER_ARCHITECTURE_ALUCONTROL_H
