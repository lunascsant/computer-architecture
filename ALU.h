#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

class ALU {
    private:
        //entradas
        unsigned int* entrada1;
        unsigned int* entrada2;

        //valores
        unsigned int resultado;
        int zero;

        //saidas
        unsigned int resultadoOut;
        int zeroOut;
        
    public:
        ALU(unsigned int resultado, int zero);
        ALU();

        // Setters das entradas
        void setEntrada1(unsigned int *entrada1){ this->entrada1 = entrada1; }
        void setSetEntrada2(unsigned int *entrada2){ this->entrada2 = entrada2; }

        // Valores da ALU
        unsigned int getResultado();
        int getZero();

        void setResultado(unsigned int resultado);
        void setZero(int zero);

        // Getters das Saidas
        int* getZeroOut();
        unsigned int* getResultadoOut();

        // Funcoes da ALU
        void soma();
        void subtracao();
};


#endif // ALU_H_INCLUDED