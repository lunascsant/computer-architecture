#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED

class EX_MEM {
    private:
        //inputs
        bool zeroIn;
        int somadorResultadoIn;
        unsigned int ALUResultadoIn;
        unsigned int readDataIn;
        unsigned int writeRegisterIn;

        int *regWriteIn;
        int *memToRegIn;
        int *branchSignalIn;
        int *memReadIn;
        int *memWriteIn;

        //registradores
        bool zero;
        int somadorResultado;
        unsigned int ALUResultado;
        unsigned int readData;
        unsigned int writeRegister;

        int regWrite;
        int memToReg;
        int branchSignal;
        int memRead;
        int memWrite;

        //outputs
        bool zeroOut;
        int somadorResultadoOut;
        unsigned int ALUResultadoOut;
        unsigned int readDataOut;
        unsigned int writeRegisterOut;

        int regWriteOut;
        int memToRegOut;
        int branchSignalOut;
        int memReadOut;
        int memWriteOut;
        
    public:
        EX_MEM(
            bool zero, 
            int somadorResultado, 
            unsigned int ALUResultado, 
            unsigned int readData, 
            unsigned int writeRegister, 
            int *regWrite, 
            int *memToReg, 
            int *branchSignal, 
            int *memRead, 
            int *memWrite
        );

        void tickClock(int val){

            if (val == 1) {
                //subida do clock
                //escreve nos registradores
                this->zero = zeroIn;
                this->somadorResultado = somadorResultadoIn;
                this->ALUResultado = ALUResultadoIn;
                this->readData = readDataIn;
                this->writeRegister = writeRegisterIn;
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
                this->readDataOut = readData;
                this->writeRegisterOut = writeRegister;
                this->regWriteOut = regWrite;
                this->memToRegOut = memToReg;
                this->branchSignalOut = branchSignal;
                this->memReadOut = memRead;
                this->memWriteOut = memWrite;
            }
        }

        bool getZero();
        int getSomadorResultado();
        int getALUResultado();
        int getReadData();
        int getWriteRegister();

        void setZero(bool zero);
        void setSomadorResultado(int somardorResultado);
        void setALUResultado(int ALUResultado);
        void setReadData(int readData);
        void setWriteRegister(int writeRegister);

        void setRegistradores(bool zero, int somadorResultado, int ALUResultado, int readData, int writeRegister);
};


#endif // EX_MEM_H_INCLUDED