//
// Created by patri on 20/01/2022.
//

#include <fstream>
#include <iostream>
#include <valarray>
#include "FileIO.h"
#include "MemoriaInstrucoes.h"

/*
string toBinary(char chars[], int len){

    string result(len*8, '0');
    for(int i=0; i<len; i++){
        int num = chars[i];
        for(int j=7; j> 0; j--){
            result.replace(i*8+j, 1, to_string(num%2));
            num = num/2;
        }
    }
    return result;
}
*/

string toBinaryString(unsigned int number){
    string result(32, '0');
    unsigned int num = number;
    for(int i=31; i>= 0; i--){
        result.replace(i, 1, to_string(num%2));
        num = num/2;
    }

    return result;
}

unsigned int readBinaryString(string bin){
    unsigned int result=0;
    int size = (int)bin.size();

    for(int i= size; i>0; i--){
        int active = (bin[i-1] == '1');
        result += active*(int)pow(2, size-i);
    }
    return result;
}



 void FileIO::readFromFile(string filePath, MemoriaInstrucoes &memInstr) {
    ifstream input;
    input.open(filePath);
    string line;
    string chars;
    int hex = 0xFF;

     if(input.is_open()){
        while(!input.eof()){
            getline(input, line);
            line = line.substr(0, 32);

            if(line.empty() || line =="\n"){
                break;
            }
            //cout <<readBinaryString(line)<< endl;
            //cout << toBinaryString(readBinaryString(line))<<endl;

            unsigned int convertedInstr = readBinaryString(line);

            chars+= (unsigned char)((convertedInstr >> 24) & hex);
            chars+= (unsigned char)((convertedInstr >> 16) & hex);
            chars+= (unsigned char)((convertedInstr >> 8) & hex);
            chars+= (unsigned char)(convertedInstr & hex);

        }
    }else{
        cout << "Nao foi possivel abrir o arquivo " << filePath << endl;
    }
    input.close();

     memInstr.alocaMemoria(chars.size());
     for(int i=0; i<chars.size(); i++){
         memInstr.adicionaByte(chars[i]);
     }


}



