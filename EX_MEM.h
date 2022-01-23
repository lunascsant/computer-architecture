#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED

class EX_MEM {
    private:
        //inputs
        int* zeroIn;
        unsigned int *somadorResultadoIn;
        unsigned int *ALUResultadoIn;
        unsigned int* readData2In;
        unsigned int* writeRegisterIn;

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

        int regWrite;
        int memToReg;
        int branchSignal;
        int memRead;
        int memWrite;

        //outputs
        int zeroOut;
        unsigned int somadorResultadoOut;
        unsigned int ALUResultadoOut;
        unsigned int readData2Out;
        unsigned int writeRegisterOut;

        int regWriteOut;
        int memToRegOut;
        int branchSignalOut;
        int memReadOut;
        int memWriteOut;
        
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

        void tickClock(int val){

            if (val == 1) {
                //subida do clock
                //escreve nos registradores
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
            } else {
                //descida do clock
                //lê dos registradores
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
            }
        }

        //set de registradores
        void setZero(int zero);
        void setSomadorResultado(unsigned int somardorResultado);
        void setALUResultado(unsigned int ALUResultado);
        void setReadData(unsigned int readData);
        void setWriteRegister(unsigned int writeRegister);

        //get das saidas
        int getZeroOut();
        unsigned int getSomadorResultadoOut();
        unsigned int getALUResultadoOut();
        unsigned int getReadDataOut();
        unsigned int getWriteRegisterOut();
        int getRegWriteOut();
        int getMemToRegOut();
        int getBranchSignalOut();
        int getMemReadOut();
        int getMemWriteOut();



        void setRegistradores(int zero,unsigned int somadorResultado, int ALUResultado, int readData, int writeRegister);
};


#endif // EX_MEM_H_INCLUDED