#ifndef MEMORIA_INSTRUCOES_H_INCLUDED
#define MEMORIA_INSTRUCOES_H_INCLUDED

class MemoriaInstrucoes {
    private:
        int memoriaDeInstrucoes[128] = {};
        int tamanho;
        
    public:
        MemoriaInstrucoes();

        int getTamanho();

        int getInstrucao(int endereco);
        void adicionaInstrucao(int instrucao);
};


#endif // MEMORIA_INSTRUCOES_H_INCLUDED