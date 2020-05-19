//
// Created by zhang on 2020/4/22.
//

#include "Cpu.h"

int Cpu::MEM(Memory &mem2) {

    int used = 0;

    if (hasIns4) {

        printf("Running %02d MEM...\n", insn4 / 4 + 1);
        hasIns4 = false;
        hasIns5 = true;

        long long n = arrayToInt(ALU_result, 31, 0);//n is multiple of 4

        if (MemWrite34) {
            used = 1;
            mem2.intToMem(data2_34, n);
        }

        if (MemRead34) {
            used = 1;
            mem2.getMem(n, ReadData);
        }
/*
        if (MemWrite34 or MemRead34) {
            printf("Data Memory:\n");
            mem2.showMem(0, n / 4 + 1);
        }
*/
        MemToReg45 = MemToReg34;
        RegWrite45 = RegWrite34;
        copyArray(ALU_result, ALU_result45, 0, 0, 32);
        RegDst45 = RegDst34;
        insn5 = insn4;

        //mul
        if (mulFlag34) {
            mulFlag45 = true;
            copyArray(hi34, hi45, 0, 0, 32);
            mulFlag34 = false;
        }
    }
    return used;
}