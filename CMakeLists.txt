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
        MemWbReg.cpp
        MemWbReg.h)
