//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_IDEX_H
#define COMPUTER_ARCHITECTURE_IDEX_H


class IDEX {
private:
    bool* ALUOp0;
    bool* ALUOp1;
    bool* ALUSrc;
    bool* regDst;
public:
    IDEX();
    void setRegDst(bool newSignal);
    void setALUOp0(bool newSignal);
    void setALUOp1(bool newSignal);
    void setALUSrc(bool newSignal);
};


#endif //COMPUTER_ARCHITECTURE_IDEX_H
