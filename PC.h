#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

class PC {
    private:
        int valorPC;
        
    public:
        //se pc for inicializar com 0 nao precisa de enviar esse valor para o construtor
        PC(int valorPC);

        int getValorPC();

        void setValorPC(int valor);
};


#endif // PC_H_INCLUDED