#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        char *memoriaDeInstrucoes;
        int tamanho;
        int posicao;
        unsigned int ultimaPalavraLida;
        unsigned int* endereco;

    public:
        MemoriaInstrucoes(int tamanhoMemoria);
        MemoriaInstrucoes();
        MemoriaInstrucoes(unsigned int* endereço);
        ~MemoriaInstrucoes();

        int getTamanho();

        unsigned int* getInstrucao();
        void adicionaByte(char byte);
        void alocaMemoria(int tamanhoMemoria);
};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED