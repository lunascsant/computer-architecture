#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

class ALU {
    private:
        int resultado;
        bool zero;
        
    public:
        ALU(int resultado, bool zero);

        int getResultado();
        bool getZero();

        void setResultado(int resultado);
        void setZero(bool zero);

        // usar void ou int?
        void soma(int valor1, int valor2);
        void subtracao(int valor1, int valor2);
};


#endif // ALU_H_INCLUDED