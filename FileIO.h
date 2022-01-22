
#ifndef COMPUTER_ARCHITECTURE_FILEIO_H
#define COMPUTER_ARCHITECTURE_FILEIO_H
#include <string>
#include "MemoriaInstrucoes.h"

using namespace std;

class FileIO {
public:
    static void readFromFile(string filePath, MemoriaInstrucoes &memInstr);

};


#endif
