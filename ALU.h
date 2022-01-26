#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

class ALU {
    private:
        unsigned int resultado;
        int zero;
        
    public:
        ALU(unsigned int resultado, int zero);
        ALU();

        unsigned int getResultado();
        int getZero();

        void setResultado(unsigned int resultado);
        void setZero(int zero);

        // usar void ou int?
        void soma(unsigned int valor1, unsigned int valor2);
        void subtracao(unsigned int valor1, unsigned int valor2);
};


#endif // ALU_H_INCLUDED