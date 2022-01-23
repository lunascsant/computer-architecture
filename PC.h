#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

class PC {
    private:
        unsigned int valorPC;
        
    public:
        //se pc for inicializar com 0 nao precisa de enviar esse valor para o construtor
        PC(int valorPC);

        unsigned int* getValorPC();

        void setValorPC(unsigned int* valor);
};


#endif // PC_H_INCLUDED