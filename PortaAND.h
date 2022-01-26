//
// Created by patri on 26/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_PORTAOR_H
#define COMPUTER_ARCHITECTURE_PORTAOR_H


class PortaAND {
private:


     int* input1;
     int* input2;
     int output;

public:
    PortaAND(int* input1, int* input2){
        this->input1 = input1;
        this->input2 = input2;
    };
    void setInput1(int* input1){this->input1 = input1;}
    void setInput1(int* input2){this->input2 = input2;}
     int* getAndOut(){return &this->output;}
    void tickClock(int val){
        this->output = *input1 & *input2;
    }
};


#endif //COMPUTER_ARCHITECTURE_PORTAOR_H
