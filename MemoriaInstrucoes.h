#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        char *memoriaDeInstrucoes;
        int tamanho;
        int posicao;

        //output
        unsigned int ultimaPalavraLida=0;

        //input
        unsigned int* endereco;

    public:
        MemoriaInstrucoes(int tamanhoMemoria);
        MemoriaInstrucoes();
        MemoriaInstrucoes(unsigned int* endereco);
        ~MemoriaInstrucoes();

        int getTamanho();

        void  setInstrucaoOut();
        void adicionaByte(char byte);
        void alocaMemoria(int tamanhoMemoria);
        void tickClock(int val){
            setInstrucaoOut();
        }
        unsigned int* getInstrucao(){return &this->ultimaPalavraLida;}


};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED