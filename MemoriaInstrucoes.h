#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        char *memoriaDeInstrucoes;
        int tamanho;
        int posicao;
        unsigned int ultimaPalavraLida;
        
    public:
        MemoriaInstrucoes(int tamanhoMemoria);
        MemoriaInstrucoes();
        ~MemoriaInstrucoes();

        int getTamanho();

        unsigned int* getInstrucao(int endereco);
        void adicionaInstrucao(char instrucao);
        void alocaMemoria(int tamanhoMemoria);
};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED