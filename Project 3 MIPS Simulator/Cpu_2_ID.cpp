//
// Created by zhang on 2020/4/16.
//
#include "Cpu.h"

void signExtend(int imm[], int imm32[], int sign, int flag) {
    for (int i = 0; i <= 15; ++i) {
        imm32[i] = imm[i];
    }
    for (int i = 16; i < 32; ++i) {
        if (flag == 1) {
            imm32[i] = sign;
        } else {
            imm32[i] = 0;
        }
    }
}

int Cpu::ID_check() {


    pause = 0;

//    if (pause == 0) {
//    if (runIF) {
    if (runID_check) {

        printf("Running %02d hazard check...\t", insn2 / 4 + 1);

//    int ir = arrayToInt(IR, 31, 0);
//
//    //no instruction in IR
//    if (ir == 0) {
//        printf("No instruction!\n");
//        return 3;
//    }

        //data hazards
        int rs = arrayToInt(IR, 25, 21);
        int rt = arrayToInt(IR, 20, 16);

        //test
        printf("%d %d\t", rs, rt);
        printf("%d %d\t", regUsing[rs], regUsing[rt]);

        if (regUsing[rs] != 0 or regUsing[rt] != 0) {
            printf("Data hazards!\n");
            pause = 2;
            return 1;
        }

        //control hazards
        if (runIF) {
            int op = arrayToInt(IR, 31, 26);
            if (op == 4) {//beq
                printf("Control hazards!\n");
                runIF = false;
                return 2;
            }
        } else {
            runIF = true;
        }

        //no hazards
        printf("No hazards!\n");
        return 0;
    }
    return 0;
}

int Cpu::ID() {

    int used = 0;

    if (hasIns2) {


        if (pause == 0) {
//        if (regUsing[rs] == 0 and regUsing[rt] == 0) {

            int op = arrayToInt(IR, 31, 26);
            int rs = arrayToInt(IR, 25, 21);
            int rt = arrayToInt(IR, 20, 16);

            printf("Running %02d ID...\n", insn2 / 4 + 1);
            used = 1;
            hasIns2 = false;
            hasIns3 = true;

            int signExtendFlag = 0;

            switch (op) {
                case 0:     //R-type
                    ALUSrc = 0;
                    ALUOp = arrayToInt(IR, 5, 0);// = func
                    RegDst = 1;
                    MemWrite = 0;
                    MemRead = 0;
                    MemToReg = 0;
                    RegWrite = 1;
                    break;
                case 8:     //addi
                case 10:    //slti
                    ALUSrc = 1;
                    ALUOp = op * 100;
                    RegDst = 0;
                    MemWrite = 0;
                    MemRead = 0;
                    MemToReg = 0;
                    RegWrite = 1;

                    signExtendFlag = 1;
                    break;
                case 12:    //andi
                case 13:    //ori
                case 15:    //lui
                case 11:    //sltiu
                    ALUSrc = 1;
                    ALUOp = op * 100;
                    RegDst = 0;
                    MemWrite = 0;
                    MemRead = 0;
                    MemToReg = 0;
                    RegWrite = 1;
                    break;
                case 35:    //lw
                    ALUSrc = 1;
                    ALUOp = op * 100;
                    RegDst = 0;
                    MemWrite = 0;
                    MemRead = 1;
                    MemToReg = 1;
                    RegWrite = 1;

                    signExtendFlag = 1;
                    break;
                case 43:    //sw
                    ALUSrc = 1;
                    ALUOp = op * 100;
                    RegDst;
                    MemWrite = 1;
                    MemRead = 0;
                    MemToReg;
                    RegWrite = 0;

                    signExtendFlag = 1;
                    break;
                case 4:     //beq
                    ALUSrc = 0;
                    ALUOp = op * 100;
                    RegDst;
                    MemWrite = 0;
                    MemRead = 0;
                    MemToReg;
                    RegWrite = 0;

                    signExtendFlag = 1;
                    break;
            }
            copyArray(Reg[rs], data1, 0, 0, 32);
            copyArray(Reg[rt], data2, 0, 0, 32);
            signExtend(IR, imm32, IR[15], signExtendFlag);

            pc23 = pc12;
            copyArray(IR, IR23, 0, 0, 32);

            insn3 = insn2;

        }

    }
    return used;
}