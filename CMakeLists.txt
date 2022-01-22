cmake_minimum_required(VERSION 3.20)
project(computer_architecture)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(computer_architecture
        main.cpp
        Multiplexador.cpp
        Multiplexador.h
        FileIO.h
        FileIO.cpp
        BancoReg.cpp
        BancoReg.h
        ALUControl.cpp
        ALUControl.h
        MEM_WB.cpp
        MEM_WB.h
        ALU.cpp
        ALU.h
        DataMemory.cpp
        DataMemory.h
        Control.cpp
        Control.h
        EX_MEM.cpp
        EX_MEM.h
        IDEX.cpp
        IDEX.h
        IFID.cpp
        IFID.h
        MemoriaInstrucoes.cpp
        MemoriaInstrucoes.h
        PC.cpp
        PC.h)
