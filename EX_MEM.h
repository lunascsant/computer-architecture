#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED

#include <string>

using namespace std;

class EX_MEM {
    private:
        //inputs
        int* zeroIn;
        unsigned int *somadorResultadoIn;
        unsigned int *ALUResultadoIn;
        unsigned int* readData2In;
        unsigned int* writeRegisterIn;
        unsigned int* nextInstIn;

        int *regWriteIn;
        int *memToRegIn;
        int *branchSignalIn;
        int *memReadIn;
        int *memWriteIn;

        //registradores
        int zero;
        unsigned int somadorResultado;
        unsigned int ALUResultado;
        unsigned int readData2;
        unsigned int writeRegister;
        unsigned int nextInst;

        int regWrite;
        int memToReg;
        int branchSignal;
        int memRead;
        int memWrite;

        //outputs
        int zeroOut = 0;
        unsigned int somadorResultadoOut = 0;
        unsigned int ALUResultadoOut = 0;
        unsigned int readData2Out = 0;
        unsigned int writeRegisterOut = 0;
        unsigned int nextInstOut=0;

        int regWriteOut = 0;
        int memToRegOut = 0;
        int branchSignalOut = 0;
        int memReadOut = 0;
        int memWriteOut = 0;
        
    public:
        EX_MEM();
        EX_MEM(
            int *zero, 
            unsigned int *somadorResultado, 
            unsigned int *ALUResultado, 
            unsigned int *readData2, 
            unsigned int *writeRegister, 
            int *regWrite, 
            int *memToReg, 
            int *branchSignal, 
            int *memRead, 
            int *memWrite
        );

        void tickClock(int val){

            if (val == 1) {
                // Subida do clock
                // Escreve nos registradores
                this->zero = *zeroIn;
                this->somadorResultado = *somadorResultadoIn;
                this->ALUResultado = *ALUResultadoIn;
                this->readData2 = *readData2In;
                this->writeRegister = *writeRegisterIn;
                this->regWrite = *regWriteIn;
                this->memToReg = *memToRegIn;
                this->branchSignal = *branchSignalIn;
                this->memRead = *memReadIn;
                this->memWrite = *memWriteIn;
                this->nextInst = *nextInstIn;
            } else {
                // Descida do clock
                // Lê dos registradores
                this->zeroOut = zero;
                this->somadorResultadoOut = somadorResultado;
                this->ALUResultadoOut = ALUResultado;
                this->readData2Out = readData2;
                this->writeRegisterOut = writeRegister;
                this->regWriteOut = regWrite;
                this->memToRegOut = memToReg;
                this->branchSignalOut = branchSignal;
                this->memReadOut = memRead;
                this->memWriteOut = memWrite;
                this->nextInstOut = nextInst;
            }
        }

        // Setters das entradas
        void setZeroIn(int *newSignal){ this->zeroIn = newSignal; }
        void setSomadorResultadoIn(unsigned int *newSignal){ this->somadorResultadoIn = newSignal; }
        void setALUResultadoIn(unsigned int *newSignal){ this->ALUResultadoIn = newSignal; }
        void setReadData2In(unsigned int *newSignal){ this->readData2In = newSignal; }
        void setWriteRegisterIn(unsigned int *newSignal){ this->writeRegisterIn = newSignal; }
        void setRegWriteIn(int *newSignal){ this->regWriteIn = newSignal; }
        void setMemToRegIn(int *newSignal){ this->memToRegIn = newSignal; }
        void setBranchIn(int *newSignal){ this->branchSignalIn = newSignal; }
        void setMemReadIn(int *newSignal){ this->memReadIn = newSignal; }
        void setMemWriteIn(int *newSignal){ this->memWriteIn = newSignal; }
        void setNextInstIn(unsigned int *newSignal){ this->nextInstIn = newSignal; }

        // Get das saidas
        int* getZeroOut();
        unsigned int* getSomadorResultadoOut();
        unsigned int* getALUResultadoOut();
        unsigned int* getReadDataOut();
        unsigned int* getWriteRegisterOut();
        unsigned int* getNextInstOut(){ return &this->nextInstOut; }
        int* getRegWriteOut();
        int* getMemToRegOut();
        int* getBranchSignalOut();
        int* getMemReadOut();
        int* getMemWriteOut();

        //set de registradores
        void setZero(int zero);
        void setSomadorResultado(unsigned int somardorResultado);
        void setALUResultado(unsigned int ALUResultado);
        void setReadData(unsigned int readData);
        void setWriteRegister(unsigned int writeRegister);
        void setRegistradores(int zero,unsigned int somadorResultado, int ALUResultado, int readData, int writeRegister);

        string printSinaisEX_MEM() {
            string state;

            state += "MEM - > Branch: " + to_string(this->branchSignalOut) + "  MemRead: " + to_string(this->memReadOut) + "  MemWrite: " + to_string(this->memWriteOut) + "  ZeroAlu: " + to_string(this->zeroOut)
            + "\n";

            return state;
        }
};


#endif // EX_MEM_H_INCLUDED