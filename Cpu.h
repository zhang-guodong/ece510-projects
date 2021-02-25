//
// Created by zhang on 2020/4/22.
//
#include "tools.h"
#include "Memory.h"

#ifndef ECE510PROJECT3_0_2_CPU_H
#define ECE510PROJECT3_0_2_CPU_H


class Cpu {
public:
    int pause;

    bool runIF;
    int runWB;

    bool runID_check;

    bool hasIns2;
    bool hasIns3;
    bool hasIns4;
    bool hasIns5;

    int Reg[32][32];
    int regUsing[32];

    //IF registers
    int pc;
    //IF control signals
    int PCSrc;

    //1/2 IF/ID registers
    int pc12;
    int IR[32];
    int insn2;

//    bool IRisfull;

    //ID control signals
    int ALUSrc;
    int ALUOp;
    int RegDst;//0 is rt, 1 is rd
    int MemWrite;
    int MemRead;
    int MemToReg;
    int RegWrite;

    //2/3 ID/IE registers
    int pc23;
    int IR23[32];
    int insn3 = 0;
    int data1[32];
    int data2[32];
    int imm32[32];

    //3/4 IE/MA registers
    int pc34;
    int insn4;
    int data2_34[32];
    int ALU_result[32];
    int RegDst34;

    int MemWrite34;
    int MemRead34;
    int MemToReg34;
    int RegWrite34;

    //4/5 MA/WB registers
    int insn5;
    int ALU_result45[32];

    int MemToReg45;
    int RegWrite45;

    int ReadData[32];
    int RegDst45;

    //mul
    bool mulFlag34;
    bool mulFlag45;
    int hi34[32];
    int hi45[32];

//    void decPause();

    void showReg(int size);

    int IF(Memory mem1, int size);

    int ID_check();

    int ID();

    int EX();

    void ALU(int data1[], int data2[], int ALUOp);

    int MEM(Memory &mem2);

    int WB();

    Cpu();
};


#endif //ECE510PROJECT3_0_2_CPU_H
