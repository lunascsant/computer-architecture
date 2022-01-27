//
// Created by patri on 26/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_SHIFTLEFT_H
#define COMPUTER_ARCHITECTURE_SHIFTLEFT_H


class ShiftLeft {

private:


    unsigned int* input;
    int shift=0;
    unsigned int output=0;

public:
    ShiftLeft(unsigned int* input, int shift){
        this->input = input;
        this->shift = shift;
    };
    void setShiftIn(unsigned int* input){this->input = input;}
    void setShift(unsigned int* input){this->shift = shift;}
    unsigned int* getShiftOut(){return &this->output;}
    void tickClock(int val){
        this->output = *input >> shift;
    }

};


#endif //COMPUTER_ARCHITECTURE_SHIFTLEFT_H
