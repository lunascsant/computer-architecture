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
#include <array>

using namespace std;

int menuExecucao(){

    int selecao;

    cout << "MENU EXECUCAO" << endl;
    cout << "-------------" << endl;
    cout << "[1] Inicio da execucao passo a passo" << endl;
    cout << "[2] Inicio da execucao direta" << endl;
    cout << "[3] Reset" << endl;
    cout << "[0] Sair" << endl;

    cin >> selecao;

    return selecao;

}

int menuArquivo(){

    int selecao;

    cout << "CARREGAMENTO DAS INSTRUCOES" << endl;
    cout << "---------------------------" << endl;
    cout << "Por favor, selecione a forma de entrada das instrucoes: " << endl;
    cout << "[1] Carregar arquivo" << endl;
    cout << "[2] Entrada do programa via teclado" << endl;

    cin >> selecao;

    return selecao;

}

void reset(BancoReg* banco, DataMemory* memoriaDados) {
    banco->resetBancoReg();
    memoriaDados->resetMemoriaDados();
}

void selecionarModoArquivo(int selecao, string* nomeArquivo){

    switch (selecao) {

        case 1:{
            string fileName;

            cout << "Digite o nome do arquivo a ser lido: " << endl;
            cin >> fileName;

            *nomeArquivo = fileName;


            cout << "Arquivo carregado." << endl;
            break;
        }
        case 2:{
            string instruction;
            ofstream instructionsFile;
            //int qtdInst;
            instructionsFile.open("instructions.txt", ios::out);

            //instructionsFile << "Teste";
            if(instructionsFile.is_open()) {

                cout << "Insira uma instrucao por vez e aperte enter apos cada instrucao digitada. " << endl;
                cout << "Digite ok quando terminar. " << endl;
                //cout << "Quantas instruções serão lidas? " << endl;
                //cin >> qtdInst;

                cin >> instruction;
                while(instruction != "ok") {
                    instructionsFile << instruction;
                    instructionsFile << "\n";
                    cin >> instruction;
                }

            } else {
                cout << "Nao foi possivel abrir o arquivo. " << endl;
            }

            instructionsFile.close();

            *nomeArquivo = "instructions.txt";
            cout << "Programa lido." << endl;
            break;
        }
        default:
        {
            cout << " Error!!! invalid option!!" << endl;
        }
    }
}

int selecionarModoExecucao(int selecao, BancoReg* bancoReg, DataMemory* memoriaDados){

    switch (selecao) {

        case 1:{
            cout << "Inicio da execucao passo a passo." << endl;
            return 0;
            break;
        }
        case 2:{
            cout << "Inicio da execucao direta." << endl;
            return 1;
            break;
        }
        case 3:{
            cout << "Limpando memoria e registradores..." << endl;
            reset(bancoReg, memoriaDados);
            cout << "Limpeza concluida." << endl;
            return 2;
            break;
        }
        case 0: {
            cout << "EXIT" << endl;
            break;
            return 3;
        }
        default:
        {
            cout << " Error!!! invalid option!!" << endl;
            return 4;
        }

    }
}

int mainMenu(string *nomeArquivo, BancoReg* bancoReg, DataMemory* memoriaDados){

    int opcaoExecucao = 2;
    int selecao = 1;

    while(selecao != 0 && opcaoExecucao != 1 && opcaoExecucao != 0){
        selecao = menuArquivo();
        selecionarModoArquivo(selecao, nomeArquivo);
        selecao = menuExecucao();
        opcaoExecucao = selecionarModoExecucao(selecao, bancoReg, memoriaDados);
    }

    return opcaoExecucao;
}

void shiftVectorLeft(unsigned int v[], int size){
    for(int i=size-1; i> 0; i--){
        v[i] = v[i-1];
    }
}

string printVector(int v[], int size){
    string nomes[5] ={"IF", "ID", "EX", "MEM", "WB"};
    char partStr[25];
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


void escreveArquivo(string strEstagio, string strBancoReg, int clk, int pcValue, string signalsIDEX, string signalsEXMEM,
                    string signalsMEMWB, string memDados, ofstream& executionFile){
    executionFile << "Clock: ";
    executionFile << clk;
    executionFile << endl;
    executionFile << "PC: ";
    executionFile << pcValue;
    executionFile << endl;
    executionFile << strEstagio;
    executionFile << endl;
    executionFile << "BANCO DE REGISTRADORES";
    executionFile << endl;
    executionFile << strBancoReg;
    executionFile << endl;
    executionFile << "SINAIS";
    executionFile << endl;
    executionFile << signalsIDEX;
    executionFile << signalsEXMEM;
    executionFile << signalsMEMWB;
    executionFile << endl;
    executionFile << "MEMORIA DE DADOS";
    executionFile << endl;
    executionFile << memDados;
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
    //extensão de sinal
    if (immediate >> 15 == 1) {
        //11111111111111110000000000000000
        immediate += 4294901760;
    }
    unsigned int shamt = (instrucao  >> 6) & primeiros5;
    unsigned int jumpAddress = instrucao & primeiros26;

    static array<string, 32> regNames = BancoReg::regNames;

    if (instrucao == 0) {
        string instrucaoBolha;
        instrucaoBolha += "instrucao bolha";
        
        return instrucaoBolha;
    }

    string instrucaoTraduzida;

    if (opcode == 0) { // TIPO-R
        if (funct == 32) { // ADD
            instrucaoTraduzida += "add $" + regNames[(int)rd] + ", $" + regNames[(int)rs] + ", $" + regNames[(int)rt];
        }
        else {
            if (funct == 36) { // AND
                instrucaoTraduzida += "and $" + regNames[(int)rd] + ", $" + regNames[(int)rs] + ", $" + regNames[(int)rt];
            }
            else {
                if (funct == 8) { // JUMP REGISTER - JR
                    instrucaoTraduzida += "jr $" + regNames[(int)rs];
                }
                else {
                    if (funct == 37) { // OR
                        instrucaoTraduzida += "or $" + regNames[(int)rd] + ", $" + regNames[(int)rs] + ", $" + regNames[(int)rt];
                    }
                    else {
                        if (funct == 42) { // SET LESS THAN - SLT
                            instrucaoTraduzida += "slt $" + regNames[(int)rd] + ", $" + regNames[(int)rs] + ", $" + regNames[(int)rt];
                        }
                        else {
                            if (funct == 0) { // SHIFT LEFT LOGICAL - SLL
                                instrucaoTraduzida += "sll $" + regNames[(int)rd] + ", $" + regNames[(int)rt] + ", " + to_string((int)shamt);
                            }
                            else {
                                if (funct == 34) { // SUB
                                    instrucaoTraduzida += "sub $" + regNames[(int)rd] + ", $" + regNames[(int)rs] + ", $" + regNames[(int)rt];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else {
        if (opcode == 8) { // ADD IMMEDIATE - ADDI
            instrucaoTraduzida += "addi $" + regNames[(int)rt] + ", $" + regNames[(int)rs] + ", " + to_string((int)immediate);
        }
        else {
            if (opcode == 4) { // BRANCH ON EQUAL - BEQ
                instrucaoTraduzida += "beq $" + regNames[(int)rs] + ", $" + regNames[(int)rt] + ", " + to_string(4*(int)immediate);
            }
            else {
                if (opcode == 5) { // BRANCH ON NOT EQUAL - BNE
                    instrucaoTraduzida += "bne $" + regNames[(int)rs] + ", $" + regNames[(int)rt] + ", " + to_string(4*(int)immediate);
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
                                instrucaoTraduzida += "lw $" + regNames[(int)rt] + ", " + to_string((int)immediate) + "($" + regNames[(int)rs] + ")";
                            }
                            else {
                                if (opcode == 43) { // SW
                                    instrucaoTraduzida += "sw $" + regNames[(int)rt] + ", " + to_string((int)immediate) + "($" + regNames[(int)rs] + ")";
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



string printVector(unsigned int v[], int size){
    string nomes[5] ={"IF", "ID", "EX", "MEM", "WB"};
    char partStr[50];
    string res;
    for(int i=0; i<size; i++){

        if(v[i]==0){
            sprintf(partStr, "%s: %-25c |",  nomes[i].c_str(), ' ');
            //printf("%s: %4c |",  nomes[i].c_str(), ' ');

        }else{
            sprintf(partStr, "%s: %-25s |",  nomes[i].c_str(), traduzInstrucao(v[i]).c_str());
        }

        res.append(partStr);

        //cout << v[i] << " |";
    }
    //cout << res ;

    //cout << "\n";

    return res;
}



int main(int argv, char** argc){

    ofstream executionFile;
    executionFile.open("execution.txt", ios::out);
    if (!executionFile) {
        cout << "Error file" << endl;
        exit(1);
    }

    string nomeArquivo;
    int opcaoExecucao;

    PC pc = PC();
    MemoriaInstrucoes memoriaInstrucoes = MemoriaInstrucoes(pc.getValorPCOut());
    FileIO fileIo = FileIO();
    fileIo.readFromFile(nomeArquivo, memoriaInstrucoes);
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

    opcaoExecucao = mainMenu(&nomeArquivo, &bancoReg, &dataMemory);
    cout << "Nome arquivo: " << nomeArquivo << endl;

    string exe;

    int valCLock=1;
    int contadorClock = 1;
    int i = 0;
    unsigned int estagios[5] ={0,0,0,0,0};

    //Execucao direta: execDireta == true
    
    while(!memoriaInstrucoes.fim()) {
        if (opcaoExecucao == 0) {
            cout << "\nAperte Enter para continuar..." << endl;
            cin.ignore();
        }
        //system("clear");
        somador.tickClock(1);//
        shiftLeftJump.tickClock(1);
        somadorJumpAddress.tickClock(1);
        memoriaInstrucoes.tickClock(1);
        portaAnd.tickClock(1);//
        muxPc.tickClock(1);//

        //**
        shiftVectorLeft(estagios, 5);

        estagios[0] = *memoriaInstrucoes.getInstrucao();
        exe = printVector(estagios, 5);
        escreveArquivo(exe, bancoReg.getState(), contadorClock, *pc.getValorPCOut(),
                        idex.getStateSignals(), exMem.printSinaisEX_MEM(),
                        memWb.printSinaisMEM_WB(), dataMemory.getState(), executionFile);
        cout << exe << "\n";
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
        contadorClock++;
    }

    // for(int i = 0; i < 87; i++){

    bancoReg.print();
    cout << dataMemory.getState() << endl;

    // FileIO::readFromFile("input.txt");

    executionFile.close();
    return 0;
}
