//
// Created by patri on 15/01/2022.
//

#ifndef TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H
#define TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H


class Multiplexador {

private:
    int* controle;
    int* sinal0;
    int* sinal1;

public:
    Multiplexador(int* controle, int* sinal0, int* sinal1){
        this->controle=controle;
        this->sinal0=sinal0;
        this->sinal1=sinal1;
    };
    int* getSaida(){
        if(controle==0){
            return sinal0;
        }
        else if(controle==1){
            return sinal1;
        }
    }

};


#endif //TRABALHO_ORGANIZAÇÃO_COMPUTADORES_MULTIPLEXER_H
