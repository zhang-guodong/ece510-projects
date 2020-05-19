//
// Created by zhang on 2020/4/22.
//

#include "Cpu.h"
#include <cstdio>

void Cpu::showReg(int size) {
    printf("Register:\n");
    for (int i = 0; i < size; ++i) {
        printf("%02d:  ", i);
        showArray(Reg[i], 31, 0);
        printf("  0x");
        hexArray(Reg[i], 32);
        printf("  ");
        switch (i) {
            case 0:
                printf("pc:\t\t%d", pc);
                break;
            case 1:
                printf("IR:\t\t");
                showArray(IR, 31, 0);
                break;
            case 2:
                printf("PCSrc:\t%d", PCSrc);
                printf("\t");
                printf("RegWrite:\t%d", RegWrite);
                printf("\t");
                break;
            case 3:
                printf("ALUSrc:\t%d", ALUSrc);
                printf("\t");
                printf("ALUOp:\t\t");
                ALUOp_string(ALUOp);
                printf("\t");
                printf("RegDst:\t\t%d", RegDst);
                break;
            case 4:
                printf("MemWrite:\t%d", MemWrite);
                printf("\t");
                printf("MemRead:\t%d", MemRead);
                printf("\t");
                printf("MemToReg:\t%d", MemToReg);
                break;
            case 5:
                printf("data1:\t");
                showArray(data1, 31, 0);
                break;
            case 6:
                printf("data2:\t");
                showArray(data2, 31, 0);
                break;
            case 7:
                printf("imm32:\t");
                showArray(imm32, 31, 0);
                break;
            case 8:
                printf("ALU_result:\t");
                showArray(ALU_result, 31, 0);
                break;
        }

        printf("\n");
    }
}

/*
void Cpu::decRegUsing() {
    for (int i = 0; i < 32; ++i) {
        if (regUsing[i] != 0) {
            regUsing[i]--;
        }
    }
}
*/

/*
void Cpu::decPause() {
    if (pause != 0) {
        pause--;
    }
}
*/

Cpu::Cpu() {
    pause = 0;

    runIF = true;
    runWB = 0;

    runID_check = false;

    hasIns2 = false;
    hasIns3 = false;
    hasIns4 = false;
    hasIns5 = false;

//     Reg[32][32] = {0};
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            Reg[i][j] = 0;
        }
    }

//    regUsing[32] = {0};
    for (int i = 0; i < 32; ++i) {
        regUsing[i] = 0;
    }

    //IF registers
    pc = 0;
    //IF control signals
    PCSrc = 0;

    //1/2 IF/ID registers
    pc12;
//    IR[32] = {0};
    for (int i = 0; i < 32; ++i) {
        IR[i] = 0;
    }
    insn2 = 0;

//    IRisfull = false;

    //ID control signals
    ALUSrc = 0;
    ALUOp = 9999;
    RegDst = 0;//0 is rt, 1 is rd
    MemWrite = 0;
    MemRead = 0;
    MemToReg = 0;
    RegWrite = 0;

    //2/3 ID/IE registers
    pc23;
    IR23[32];
    insn3 = 0;
//    data1[32] = {0};
//    data2[32] = {0};
//    imm32[32] = {0};
    for (int i = 0; i < 32; ++i) {
        data1[i] = 0;
        data2[i] = 0;
        imm32[i] = 0;
    }

    //3/4 IE/MA registers
    pc34;
    insn4 = 0;
    data2_34[32];
//    ALU_result[32] = {0};
    for (int i = 0; i < 32; ++i) {
        ALU_result[i] = 0;
    }
    RegDst34;

    MemWrite34 = 0;
    MemRead34 = 0;
    MemToReg34 = 0;
    RegWrite34 = 0;

    //4/5 MA/WB registers
    insn5 = 0;
    ALU_result45[32];

    MemToReg45;
    RegWrite45 = 0;

    ReadData[32];
    RegDst45;

    //mul
    mulFlag34 = false;
    mulFlag45 = false;
    for (int i = 0; i < 32; ++i) {
        hi34[i] = 0;
        hi45[i] = 0;
    }
}