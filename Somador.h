#ifndef SOMADOR_H_INCLUDED
#define SOMADOR_H_INCLUDED

class Somador {
    private:
        //entradas
        unsigned int* valor1;
        unsigned int* valor2;

        //saidas
        unsigned int resultado = 0;

    public:
        Somador(unsigned int* valor1, unsigned int* valor2);

        //Setters das entradas
        void setValor1(unsigned int *valor1){ this->valor1 = valor1; }
        void setValor2(unsigned int *valor2){ this->valor2 = valor2; }

        //Retorna o endereco para o resultado do somador
        unsigned int* getResultado();

        void setResultado(unsigned int resultado);
        void somaValores();

        void tickClock(int val){
            if (val==1) {
                //subida do clock
                somaValores();
            } else {
                //descida do clock
            }
        }
};


#endif // SOMADOR_H_INCLUDED