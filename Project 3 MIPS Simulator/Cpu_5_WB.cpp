//
// Created by zhang on 2020/4/16.
//
#include "Cpu.h"

int Cpu::WB() {

    int used = 0;
    runWB = 0;
    if (hasIns5) {

        printf("Running %02d WB...\t", insn5 / 4 + 1);
        hasIns5 = false;
        runWB = 1;
        //test
        printf("RegWrite:%d\t", RegWrite45);

        if (RegWrite45) {
            used = 1;
            if (MemToReg45) {
                copyArray(ReadData, Reg[RegDst45], 0, 0, 32);
            } else {
                copyArray(ALU_result45, Reg[RegDst45], 0, 0, 32);
            }

            regUsing[RegDst45] = 0;

            //test
            printf("%d %d\t", RegDst45, regUsing[RegDst45]);
        }

        printf("\n");

        //mul
        if (mulFlag45) {
            copyArray(hi45, Reg[RegDst45 + 1], 0, 0, 32);
            mulFlag45 = false;
        }
    }

    return used;
}