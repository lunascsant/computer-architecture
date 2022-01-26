#ifndef SOMADOR_H_INCLUDED
#define SOMADOR_H_INCLUDED

class Somador {
    private:
        unsigned int resultado;

        unsigned int* valor1;
        unsigned int* valor2;

    public:
    Somador(unsigned int* valor1, unsigned int* valor2);
    unsigned int* getResultado();
    void setResultado(unsigned int resultado);
    void somaValores();

    void tickClock(int val){
        if(val==1){
            //subida do clock
            somaValores();
        }else{
            //descida do clock
        }
    }
};


#endif // SOMADOR_H_INCLUDED