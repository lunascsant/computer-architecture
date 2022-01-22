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
            cout <<readBinaryString(line)<< endl;
            cout << toBinaryString(readBinaryString(line))<<endl;

            int convertedInstr = readBinaryString(line);

            chars+= (char)(int)(convertedInstr & hex);
            chars+= (char)(int)((convertedInstr >> 8) & hex);
            chars+= (char)(int)((convertedInstr >> 16) & hex);
            chars+= (char)(int)((convertedInstr >> 24) & hex);
        }
    }else{
        cout << "Nao foi possivel abrir o arquivo " << filePath << endl;
    }
    input.close();

     //meminstr.setSize(chars.size())
     for(int i=0; i<chars.size(); i++){

         //meminstr.addbyte(chars[i])
     }


/*
    string byte = "01000000";
    char c =  (char)(int)readBinaryString(byte);
    cout << readBinaryString(byte) << endl;
    cout << c << endl;
    cout << toBinaryString((unsigned int)c)<<endl;

     string inst = "00011010001100100100000000100000";
     //int hex = 0xFF;
     int convertedInstr = readBinaryString(inst);
     cout << convertedInstr<<endl;
     int opcode = convertedInstr >> 26;
     int funct = convertedInstr & 63;//111111
     cout << toBinaryString(opcode) << endl;
     cout << toBinaryString(funct) << endl;

     char _c[4];
     _c[0]= (char)(int)(convertedInstr & hex);
     _c[1] = (char)(int)((convertedInstr >> 8) & hex);
     _c[2] = (char)(int)((convertedInstr >> 16) & hex);
     _c[3] = (char)(int)((convertedInstr >> 24) & hex);

     cout << toBinaryString((unsigned int)_c[0]) << endl;
     cout << toBinaryString((unsigned int)_c[1]) << endl;
     cout << toBinaryString((unsigned int)_c[2]) << endl;
     cout << toBinaryString((unsigned int)_c[3]) << endl;

*/


/*
    char c[2] = {'~', '@'};



     cout << toBinary(c, 2) << endl;
     cout << readBinaryString("11111111111111111111111111111111") <<endl;
     cout << toBinaryString(4294967295)<<endl;*/
}



