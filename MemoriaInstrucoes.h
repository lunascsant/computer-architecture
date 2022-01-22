#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        char *memoriaDeInstrucoes;
        int tamanho;
        int posicao;
        
    public:
        MemoriaInstrucoes(int tamanhoMemoria);

        int getTamanho();

        int getInstrucao(int endereco);
        void adicionaInstrucao(char instrucao);
};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED