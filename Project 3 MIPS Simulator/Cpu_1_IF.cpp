//
// Created by zhang on 2020/4/16.
//
#include "Cpu.h"

int Cpu::IF(Memory mem1, int size) {

    int used = 0;

    if (runIF) {

        if (pause == 0) {

            //choose pc
            if (PCSrc) {
                pc = pc34;
                PCSrc = 0;
            }

            if (pc / 4 + 1 <= 34) {
                printf("Running %02d IF...\n", pc / 4 + 1);
                used = 1;
                hasIns2 = true;
            } else {
                hasIns2 = false;
                runIF = false;
            }
            //store instruction to IR
            mem1.getMem(pc, IR);
//            IRisfull = true;

            //trans to next state
            insn2 = pc;
            pc12 = pc + 4;

            //renew pc
            pc = pc + 4;

        }
//    } else {
//        runIF = true;
    }
    runID_check = true;
    return used;
}