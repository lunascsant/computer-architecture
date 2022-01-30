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
#include "Multiplexador.h"
#include "ALUControl.h"
#include "EX_MEM.h"
#include "ALU.h"
#include "DataMemory.h"
#include "MEM_WB.h"
#include "ShiftLeft.h"
#include "PortaAND.h"

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

    PC pc = PC();
    MemoriaInstrucoes memoriaInstrucoes = MemoriaInstrucoes(pc.getValorPCOut());
    FileIO fileIo = FileIO();
    fileIo.readFromFile("teste.txt", memoriaInstrucoes);
    unsigned int val4 = 4;
    Somador somador = Somador(&val4, pc.getValorPCOut());

    IFID ifid = IFID();
    ifid.setNextInstIn(somador.getResultado());
    ifid.setInstructionIn(memoriaInstrucoes.getInstrucao());

    ////***********************************

    BancoReg bancoReg = BancoReg();
    bancoReg.setReadRegister1In(ifid.getRsOut());
    bancoReg.setReadRegister2In(ifid.getRtOut());
    bancoReg.print();
    Control control = Control();
    control.setOpcode(ifid.getOpCodeOut());

    IDEX idex = IDEX();
    idex.setRegDstIn(control.getRegDst());
    idex.setBranchIn(control.getBranch());
    idex.setALUOpIn(control.getALUOp());
   // idex.setALUOp0In(control.getALUOp0());
    //idex.setALUOp1In(control.getALUOp1());
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
    idex.setRdIn(ifid.getRdOut());
    idex.setRtIn(ifid.getRtOut());
    idex.setShamtIn(ifid.getShamtOut());

    ///////////*******************************



    //////////

    Multiplexador muxEx1 = Multiplexador(idex.getRegDstOut(), idex.getRtOut(), idex.getRdOut());
    ALUControl aluControl = ALUControl(idex.getAluOpOut(), idex.getImmediateOut());
    Multiplexador muxEx2 = Multiplexador(idex.getAluSrcOut(), idex.getReadData2Out(), idex.getImmediateOut());
    Multiplexador muxShamtRs = Multiplexador(aluControl.getShamtOrRsOut(), idex.getReadData1Out(), idex.getShamtOut());

    ALU alu = ALU();
    alu.setEntrada1(muxShamtRs.getSaida());
    alu.setEntrada2(muxEx2.getSaida());
    alu.setAluControlIn(aluControl.getOutput());

    ShiftLeft shiftLeft = ShiftLeft(idex.getImmediateOut(), 2);
    Somador somador2 = Somador(shiftLeft.getShiftOut(),idex.getNextInstOut());

    EX_MEM exMem = EX_MEM();
    exMem.setALUResultadoIn(alu.getResultadoOut());
    exMem.setZeroIn(alu.getZeroOut());
    exMem.setSomadorResultadoIn(somador2.getResultado());
    exMem.setReadData2In(idex.getReadData2Out());
    exMem.setWriteRegisterIn(muxEx1.getSaida());
    exMem.setBranchIn(idex.getBranchOut());
    exMem.setMemReadIn(idex.getMemReadOut());
    exMem.setMemWriteIn(idex.getMemWriteOut());
    exMem.setMemToRegIn(idex.getMemToRegOut());
    exMem.setRegWriteIn(idex.getRegWriteOut());


    //////////////////************************


    DataMemory dataMemory = DataMemory();
    dataMemory.setAddress(exMem.getALUResultadoOut());
    dataMemory.setWriteData(exMem.getReadDataOut());
    dataMemory.setMemWrite(exMem.getMemWriteOut());
    dataMemory.setMemRead(exMem.getMemReadOut());


    PortaAND portaAnd = PortaAND(exMem.getZeroOut(), exMem.getBranchSignalOut());

    MEM_WB memWb = MEM_WB(exMem.getMemToRegOut(), exMem.getRegWriteOut());
    memWb.setReadDataIn(dataMemory.getReadData());
    memWb.setWriteRegisterIn(exMem.getWriteRegisterOut());
    memWb.setAluOutIn(exMem.getALUResultadoOut());


    /////////////*********************************

    bancoReg.setRegWriteIn(memWb.getRegWrite());
    Multiplexador muxWb = Multiplexador(memWb.getMemToReg(), memWb.getAluOut(), memWb.getReadData());
    bancoReg.setWriteRegisterIn(memWb.getWriteRegisterReg());
    bancoReg.setWriteDataIn(muxWb.getSaida());

    Multiplexador muxPc = Multiplexador(portaAnd.getAndOut(), somador.getResultado(), exMem.getSomadorResultadoOut());
    pc.setValorPCIn(muxPc.getSaida());



    //depois de mem/wb
   // bancoReg.setWriteRegisterIn();
   // bancoReg.setWriteDataIn();


   int valCLock=1;
   //int i=0;
   for(int i=0; i<5; i++){

       somador.tickClock(1);//
       memoriaInstrucoes.tickClock(1);
       portaAnd.tickClock(1);//
       muxPc.tickClock(1);//
       pc.tickClock(1);

       control.tickClock(1);//

       shiftLeft.tickClock(1);//
       muxEx1.tickClock(1);//
       muxEx2.tickClock(1);//
       somador2.tickClock(1);//
       aluControl.tickClock(1);//
       muxShamtRs.tickClock(1);//
       alu.tickClock(1);//



       muxWb.tickClock(1);//


       ifid.tickClock(1);
       bancoReg.tickClock(1);
       idex.tickClock(1);
       exMem.tickClock(1);
       dataMemory.tickClock(1);
       memWb.tickClock(1);


       ifid.tickClock(0);
       bancoReg.tickClock(0);
       idex.tickClock(0);
       exMem.tickClock(0);
       dataMemory.tickClock(0);
       memWb.tickClock(0);

       valCLock = !valCLock;

   }
    bancoReg.print();

    // FileIO::readFromFile("input.txt");
    mainMenu();
    return 0;
}
