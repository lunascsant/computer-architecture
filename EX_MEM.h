#ifndef EX_MEM_H_INCLUDED
#define EX_MEM_H_INCLUDED

class EX_MEM {
    private:
        bool zero;
        int somadorResultado;
        int ALUResultado;
        int readData;
        int writeRegister;
        
    public:
        EX_MEM(bool zero, int somadorResultado, int ALUResultado, int readData, int writeRegister);

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