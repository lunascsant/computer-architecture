#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

class ALU {
    private:
        //entradas
        unsigned int* entrada1;
        unsigned int* entrada2;
        unsigned int* aluControlIn;

        //saidas
        unsigned int resultadoOut;
        int zeroOut;
        
    public:
        ALU(unsigned int resultadoOut);
        ALU();

        void tickClock(int val){

            if (val == 1) {
                // Subida do clock
                // Escreve nos registradores
                if (*this->aluControlIn == 2) { //0010
                    this->soma();
                }
                else {
                    if (*this->aluControlIn == 6) { //0110
                        this->subtracao();
                        if (resultadoOut == 0) {
                            setZeroOut(1);
                        }
                    }
                    else {
                        if (*this->aluControlIn == 0) { //0000
                            this->and();
                        }
                        else {
                            if (*this->aluControlIn == 1) { //0001
                                this->or();
                            }
                            else {
                                if (*this->aluControlIn == 7) { //0111

                                }
                            }
                        }
                    }
                }
            } else {
                // Descida do clock
                // Lê dos registradores
            }
        }

        // Setters das entradas
        void setEntrada1(unsigned int *entrada1){ this->entrada1 = entrada1; }
        void setSetEntrada2(unsigned int *entrada2){ this->entrada2 = entrada2; }
        void setAluControlIn(unsigned int *aluControlIn){ this->aluControlIn = aluControlIn; }

        // Getters das Saidas
        int* getZeroOut();
        unsigned int* getResultadoOut();

        // Setters das saidas da ALU
        void setResultadoOut(unsigned int resultado);
        void setZeroOut(int zero);

        // Funcoes da ALU
        void soma();
        void subtracao();
        void and();
        void or();
};


#endif // ALU_H_INCLUDED