#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

class PC {
    private:
        // Entrada
        unsigned int* valorPCIn;

        // Saida
        unsigned int valorPCOut=0;
        
    public:
        //se pc for inicializar com 0 nao precisa de enviar esse valor para o construtor
        PC(unsigned int* valorPC);
        PC();

        void tickClock(int val){

        if (val==1) {
            //subida do clock
            //escreve nos registradores
            this->valorPCOut = *valorPCIn;
        } else {
            //descida do clock
            //lê dos registradores
        }
    }

        // Setters das entradas
        void setValorPCIn(unsigned int *valorPCIn){ this->valorPCIn = valorPCIn; }

        // Getters das Saidas
        unsigned int* getValorPCOut();

        // Setters das saidas da ALU
        void setValorPCOut(unsigned int valorPCOut);
        void reset(){
            this->valorPCOut=0;
        }
};


#endif // PC_H_INCLUDED