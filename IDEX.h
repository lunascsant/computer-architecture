//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IDEX_H
#define COMPUTER_ARCHITECTURE_IDEX_H


class IDEX {
private:
    int ALUOp0;
    int ALUOp1;
    int ALUSrc;
    int regDst;
public:
    IDEX();
    void setRegDst(int newSignal);
    void setALUOp0(int newSignal);
    void setALUOp1(int newSignal);
    void setALUSrc(int newSignal);
    void getRegDst();
    void getALUOp0();
    void getALUOp1();
    void getALUSrc();
};


#endif //COMPUTER_ARCHITECTURE_IDEX_H
