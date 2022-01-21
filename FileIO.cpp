//
// Created by patri on 20/01/2022.
//

#include <fstream>
#include <iostream>
#include <valarray>
#include "FileIO.h"
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

 void FileIO::readFromFile(string filePath) {
    ifstream input;
    input.open(filePath);
    string line;

    if(input.is_open()){
        while(!input.eof()){
            getline(input, line);
            line = line.substr(0, 32);
            cout <<readBinaryString(line)<< endl;
            cout << toBinaryString(readBinaryString(line))<<endl;
        }
    }else{
        cout << "Nao foi possivel abrir o arquivo " << filePath << endl;
    }
    input.close();

/*
    char c[2] = {'~', '@'};



     cout << toBinary(c, 2) << endl;
     cout << readBinaryString("11111111111111111111111111111111") <<endl;
     cout << toBinaryString(4294967295)<<endl;*/
}



