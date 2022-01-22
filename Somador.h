#ifndef SOMADOR_H_INCLUDED
#define SOMADOR_H_INCLUDED

class Somador {
    private:
        int resultado;
        
    public:
        Somador(int resultado);

        int getResultado();

        void setResultado(int resultado);

        void somaValores(int valor1, int valor2);
};


#endif // SOMADOR_H_INCLUDED