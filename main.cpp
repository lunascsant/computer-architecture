//
// Created by patri on 15/01/2022.
//

#include <fstream>
#include "iostream"
#include "stdio.h"
#include "string"
#include "FileIO.h"
#include "PC.h"
#include "Somador.h"
#include "IFID.h"
#include "IDEX.h"
#include "BancoReg.h"
#include "Control.h"

using namespace std;

int menu(){

    int selecao;

    cout << "MENU" << endl;
    cout << "----" << endl;
    cout << "[1] Carregar arquivo" << endl;
    cout << "[2] Entrada do programa via teclado" << endl;
    cout << "[3] Inicio da execucao passo a passo" << endl;
    cout << "[4] Inicio da execucao direta" << endl;
    cout << "[5] Reset" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    return selecao;

}

void selecionar(int selecao){

    switch (selecao) {

        case 1:{
            string fileName;

            cout << "Digite o nome do arquivo a ser lido: ";
            cin >> fileName;

            // continua

            cout << "Arquivo carregado." << endl;
            break;
        }
        case 2:{
            string instruction;
            ofstream instructionsFile;
            //int qtdInst;
            instructionsFile.open("instructions.txt");

            instructionsFile << "Teste";
            if(instructionsFile.is_open()) {

                cout << "Insira uma instrucao por vez e aperte enter apos cada instrucao digitada. " << endl;
                cout << "Digite ok quando terminar. " << endl;
                //cout << "Quantas instruções serão lidas? " << endl;
                //cin >> qtdInst;

                cin >> instruction;
                while(instruction != "ok") {
                    instructionsFile << instruction;
                    cin >> instruction;
                }

            } else {
                cout << "Nao foi possivel abrir o arquivo. " << endl;
            }

            instructionsFile.close();

            cout << "Programa lido." << endl;
            break;
        }
        case 3:{

            cout << "Inicio da execucao passo a passo." << endl;
            // execução passo a passo
            break;
        }
        case 4:{

            cout << "Inicio da execucao direta." << endl;
            // execução direta
            break;
        }
        case 5:{

            cout << "Limpando memoria e registradores..." << endl;
            // limpa
            cout << "Limpeza concluida." << endl;
            break;
        }
        case 0: {
            cout << "EXIT" << endl;
            break;
        }
        default:
        {
            cout << " Error!!! invalid option!!" << endl;
        }

    }
}


int mainMenu(){

    int selecao = 1;

    while(selecao != 0){
        selecao = menu();
        selecionar(selecao);
    }

    return 0;
}

int main(int argv, char** argc){

    PC pc = PC(0);
    MemoriaInstrucoes memoriaInstrucoes = MemoriaInstrucoes(pc.getValorPC());
    FileIO fileIo = FileIO();
    fileIo.readFromFile("teste.txt", memoriaInstrucoes);
    unsigned int val4 = 4;
    Somador somador = Somador(&val4, pc.getValorPC());

    IFID ifid = IFID();
    ifid.setNextInstIn(somador.getResultado());
    ifid.setInstructionIn(memoriaInstrucoes.getInstrucao());


    BancoReg bancoReg = BancoReg();
    bancoReg.setReadRegister1(ifid.getRsOut());
    bancoReg.setReadRegister2(ifid.getRtOut());

    Control control = Control();
    control.setOpcode(ifid.getOpCodeOut());

    IDEX idex = IDEX();
    idex.setRegDstIn(control.getRegDst());
    idex.setBranchIn(control.getBranch());
    idex.setALUOp0In(control.getALUOp0());
    idex.setALUOp1In(control.getALUOp1());
    idex.setALUSrcIn(control.getALUSrc());
    idex.setMemReadIn(control.getMemRead());
    idex.setMemWriteIn(control.getMemWrite());
    idex.setMemToRegIn(control.getMemToReg());
    idex.setPCSrcIn(control.getPCSrc());
    idex.setRegWriteIn(control.getRegWrite());
    idex.setReadData1(bancoReg.getReadData1());
    idex.setReadData2(bancoReg.getReadData2());
    idex.setNextInst(ifid.getNextInstOut());
    idex.setImmediate(ifid.getImmediateOut());


    //depois de mem/wb
    bancoReg.setWriteRegister();
    bancoReg.setWriteData();
    bancoReg.setRegWrite();



    // FileIO::readFromFile("input.txt");
    mainMenu();
    return 0;
}
