//
// Created by patri on 15/01/2022.
//

#ifndef TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H
#define TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H


class Multiplexador {

private:
    int controle;
    unsigned int* sinal0;
    unsigned int* sinal1;
    unsigned int saida;

public:
    Multiplexador(unsigned int controle,unsigned int* sinal0,unsigned int* sinal1){
        this->controle=controle;
        this->sinal0=sinal0;
        this->sinal1=sinal1;
    };

    void tickClock(int val){
        if(val==1){
            if(controle==0){
                saida = *sinal0;
            }
            else if(controle==1){
                saida = *sinal1;
            }
        }
    }

    unsigned int* getSaida(){
        return &this->saida;
    }

};


#endif //TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H
