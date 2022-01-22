//
// Created by lucia on 22/01/2022.
//

#ifndef COMPUTER_ARCHITECTURE_CONTROL_H
#define COMPUTER_ARCHITECTURE_CONTROL_H


class Control {
public:
    // sinais:
    bool regDst;
    bool jump; // n sei se entra esse
    bool branch;
    bool memRead;
    bool memWrite;
    bool memToReg;
    bool ALUOp0;
    bool ALUOp1;
    bool ALUSrc;
    bool regWrite;
    bool PCSrc;

    // métodos
    Control();
    void setRegDst(bool newSignal);
    void setJump(bool newSignal);
    void setBranch(bool newSignal);
    void setMemRead(bool newSignal);
    void setMemWrite(bool newSignal);
    void setMemToReg(bool newSignal);
    void setALUOp0(bool newSignal);
    void setALUOp1(bool newSignal);
    void setALUSrc(bool newSignal);
    void setRegWrite(bool newSignal);
    void setPCSrc(bool newSignal);
};


#endif //COMPUTER_ARCHITECTURE_CONTROL_H
