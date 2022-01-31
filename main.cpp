//
// Created by patri on 15/01/2022.
//

#include <fstream>
#include <iomanip>
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
#include <array>

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

void shiftVectorLeft(int v[], int size){
    for(int i=size-1; i> 0; i--){
        v[i] = v[i-1];
    }
}

string printVector(int v[], int size){
    array<string, 5> nomes ={"IF", "ID", "EX", "MEM", "WB"};
    char partStr[20];
    string res;
    for(int i=0; i<size; i++){

        if(v[i]==-1){
            sprintf(partStr, "%s: %4c |",  nomes[i].c_str(), ' ');
            //printf("%s: %4c |",  nomes[i].c_str(), ' ');

        }else{
            sprintf(partStr, "%s: %4d |",  nomes[i].c_str(), v[i]);
        }

        res.append(partStr);

       //cout << v[i] << " |";
    } cout << res ;

    cout << "\n";

    return res;
}


void escreveArquivo(string strEstagio, string strBancoReg, string strInst, int clk, ofstream& executionFile){
    executionFile << "Clock: ";
    executionFile << clk;
    executionFile << endl;
    executionFile << strEstagio;
    executionFile << endl;
    executionFile << strInst;
    executionFile << endl;
    executionFile << strBancoReg;
    executionFile << endl;
}

string traduzInstrucao(unsigned int instrucao) {
    unsigned int primeiros16 = 65535; //1111111111111111
    unsigned int primeiros6 = 63;//111111
    unsigned int primeiros5 = 31;//011111
    unsigned int primeiros26 = 67108863;//11111111111111111111111111

    unsigned int opcode = instrucao >> 26;
    unsigned int funct = instrucao & primeiros6;
    unsigned int rs = (instrucao >> 21) & primeiros5;
    unsigned int rt = (instrucao  >> 16) & primeiros5;
    unsigned int rd = (instrucao  >> 11) & primeiros5;
    unsigned int immediate = instrucao & primeiros16;
    unsigned int shamt = (instrucao  >> 6) & primeiros5;
    unsigned int jumpAddress = instrucao & primeiros26;

    if (instrucao == 0) {
        string instrucaoBolha;
        instrucaoBolha += "instrucao bolha";
        
        return instrucaoBolha;
    }

    string instrucaoTraduzida;

    if (opcode == 0) { // TIPO-R
        if (funct == 32) { // ADD
            instrucaoTraduzida += "add $" + to_string((int)rd) + ", $" + to_string((int)rs) + ", $" + to_string((int)rt);
        }
        else {
            if (funct == 36) { // AND
                instrucaoTraduzida += "and $" + to_string((int)rd) + ", $" + to_string((int)rs) + ", $" + to_string((int)rt);
            }
            else {
                if (funct == 8) { // JUMP REGISTER - JR
                    instrucaoTraduzida += "jr $" + to_string((int)rs);
                }
                else {
                    if (funct == 37) { // OR
                        instrucaoTraduzida += "or $" + to_string((int)rd) + ", $" + to_string((int)rs) + ", $" + to_string((int)rt);
                    }
                    else {
                        if (funct == 42) { // SET LESS THAN - SLT
                            instrucaoTraduzida += "slt $" + to_string((int)rd) + ", $" + to_string((int)rs) + ", $" + to_string((int)rt);
                        }
                        else {
                            if (funct == 0) { // SHIFT LEFT LOGICAL - SLL
                                instrucaoTraduzida += "sll $" + to_string((int)rd) + ", $" + to_string((int)rt) + ", " + to_string((int)shamt);
                            }
                            else {
                                if (funct == 34) { // SUB
                                    instrucaoTraduzida += "sub $" + to_string((int)rd) + ", $" + to_string((int)rs) + ", $" + to_string((int)rt);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        if (opcode == 8) { // ADD IMMEDIATE
            instrucaoTraduzida += "addi $" + to_string((int)rt) + ", $" + to_string((int)rs) + ", " + to_string((int)immediate);
        }
        else {
            if (opcode == 4) { // BRANCH ON EQUAL - BEQ
                instrucaoTraduzida += "beq $" + to_string((int)rs) + ", $" + to_string((int)rt) + ", " + to_string((int)immediate);
            }
            else {
                if (opcode == 5) { // BRANCH ON NOT EQUAL - BNE
                    instrucaoTraduzida += "bne $" + to_string((int)rs) + ", $" + to_string((int)rt) + ", " + to_string((int)immediate);
                }
                else {
                    if (opcode == 2) { // JUMP - J
                        instrucaoTraduzida += "j " + to_string((int)jumpAddress);
                    }
                    else {
                        if (opcode == 3) { // JUMP AND LINK - JAL
                            instrucaoTraduzida += "jal " + to_string((int)jumpAddress);
                        }
                        else {
                            if (opcode == 35) { // LW
                                instrucaoTraduzida += "lw $" + to_string((int)rt) + ", " + to_string((int)immediate) + "($" + to_string((int)rs) + ")";
                            }
                            else {
                                if (opcode == 43) { // SW
                                    instrucaoTraduzida += "sw $" + to_string((int)rt) + ", " + to_string((int)immediate) + "($" + to_string((int)rs) + ")";
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return instrucaoTraduzida;
}


int main(int argv, char** argc){

    ofstream executionFile;
    executionFile.open("execution.txt");
    if (!executionFile) {
        cout << "Error file" << endl;
        exit(1);
    }

    PC pc = PC();
    MemoriaInstrucoes memoriaInstrucoes = MemoriaInstrucoes(pc.getValorPCOut());
    FileIO fileIo = FileIO();
    fileIo.readFromFile("teste8.txt", memoriaInstrucoes);
    unsigned int val4 = 4;
    Somador somador = Somador(&val4, pc.getValorPCOut());

    IFID ifid = IFID();
    ifid.setNextInstIn(somador.getResultado());
    ifid.setInstructionIn(memoriaInstrucoes.getInstrucao());

    ShiftLeft shiftLeftJump = ShiftLeft(ifid.getJumpAddressOut(), 2);
    Somador somadorJumpAddress = Somador(ifid.getPCUltimos4Out(), shiftLeftJump.getShiftOut());

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
    unsigned int ra = 31;
    Multiplexador muxEx1 = Multiplexador(idex.getRegDstOut(), idex.getRtOut(), idex.getRdOut(), &ra);
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
    exMem.setNextInstIn(idex.getNextInstOut());


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
    memWb.setNextInstIn(exMem.getNextInstOut());


    /////////////*********************************

    bancoReg.setRegWriteIn(memWb.getRegWrite());
    Multiplexador muxWb = Multiplexador(memWb.getMemToReg(), memWb.getAluOut(), memWb.getReadData(), memWb.getNextInstOut());
    bancoReg.setWriteRegisterIn(memWb.getWriteRegisterReg());
    bancoReg.setWriteDataIn(muxWb.getSaida());

    Multiplexador muxPc = Multiplexador(portaAnd.getAndOut(), somador.getResultado(), exMem.getSomadorResultadoOut());

    Multiplexador muxJump = Multiplexador(control.getJump(), muxPc.getSaida(), somadorJumpAddress.getResultado());
    Multiplexador muxJr = Multiplexador(aluControl.getJrOut(), muxJump.getSaida(), idex.getReadData1Out());
    pc.setValorPCIn(muxJr.getSaida());


    //depois de mem/wb
   // bancoReg.setWriteRegisterIn();
   // bancoReg.setWriteDataIn();

   string exe, inst;

   int valCLock=1;
   int i = 0;
   int estagios[5] ={-1,-1,-1,-1,-1};
  // for(int i = 0; i < 87; i++){
  while(!memoriaInstrucoes.fim()){
       //system("clear");
       somador.tickClock(1);//
       shiftLeftJump.tickClock(1);
       somadorJumpAddress.tickClock(1);
       memoriaInstrucoes.tickClock(1);
       portaAnd.tickClock(1);//
       muxPc.tickClock(1);//

       //**
       shiftVectorLeft(estagios, 5);
       estagios[0] = (int)*pc.getValorPCOut();
       exe = printVector(estagios, 5);
       inst = traduzInstrucao(*memoriaInstrucoes.getInstrucao());
       escreveArquivo(exe, bancoReg.getState(), inst, i, executionFile);
       cout << inst <<endl;
       // escreveArquivo(estagios, 5, executionFile);
       //executionFile << exe;
       //**

       control.tickClock(1);//
       muxJump.tickClock(1);

       shiftLeft.tickClock(1);//
       muxEx1.tickClock(1);//
       muxEx2.tickClock(1);//
       somador2.tickClock(1);//
       aluControl.tickClock(1);//
       muxJr.tickClock(1);
       pc.tickClock(1);
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
       bancoReg.print();
       i++;

   }
    bancoReg.print();

    // FileIO::readFromFile("input.txt");
    mainMenu();

    executionFile.close();
    return 0;
}
