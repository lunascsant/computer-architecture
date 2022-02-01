#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        unsigned char *memoriaDeInstrucoes;
        int tamanho;
        int posicao;
        int fimInstrucoes=0;
        int preTermino=0;

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
        void adicionaByte(unsigned char byte);
        void alocaMemoria(int tamanhoMemoria);
        void tickClock(int val){
            setInstrucaoOut();
        }
        unsigned int* getInstrucao(){return &this->ultimaPalavraLida;}
        int fim(){return this->fimInstrucoes;}
        int getPreTermino(){return this->preTermino;}
        void reset(){
            this->fimInstrucoes=0;
            this->preTermino=0;
            this->ultimaPalavraLida=0;
        }

};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED