//
// Created by zhang on 2020/4/22.
//

#include "Cpu.h"

void Cpu::ALU(int data1[], int data2[], int ALUOp) {
    PCSrc = 0;
    switch (ALUOp) {
//R-type
        case 32://add
            addArray(data1, data2, ALU_result, 32);
            break;
        case 34://sub
            subArray(data1, data2, ALU_result, 32);
            break;
        case 36://and
            andArray(data1, data2, ALU_result, 32);
            break;
        case 37://or
            orArray(data1, data2, ALU_result, 32);
            break;
        case 0: //sll
            shiftL(data2, ALU_result, 32, arrayToInt(IR23, 10, 6));
            break;
        case 2: //srl
            shiftR_logical(data2, ALU_result, 32, arrayToInt(IR23, 10, 6));
            break;
        case 24://mul
            mulFlag34 = true;
            mulArray(data1, data2, ALU_result, hi34, 32);
            break;
//I-type
        case 800://addi
            addArray(data1, data2, ALU_result, 32);
            break;
        case 1200://andi
            andArray(data1, data2, ALU_result, 32);
            break;
        case 1300://ori
            orArray(data1, data2, ALU_result, 32);
            break;
        case 3500://lw
        case 4300://sw
            addArray(data1, data2, ALU_result, 32);
            break;
        case 400://beq
            if ((int) arrayToInt(data1, 31, 0) == (int) arrayToInt(data2, 31, 0))
                PCSrc = 1;
            break;
        case 1500://lui
            copyArray(imm32, ALU_result, 0, 16, 16);
            copyArray(Reg[0], ALU_result, 0, 0, 16);
            break;
        case 1000://slti
            copyArray(Reg[0], ALU_result, 0, 0, 32);
            if ((int) (arrayToInt(data1, 31, 0) - arrayToInt(imm32, 32, 0)) < 0) {
                ALU_result[0] = 1;
            }
            break;
        case 1100://sltiu
            copyArray(Reg[0], ALU_result, 0, 0, 32);
            if ((int) (arrayToInt(data1, 31, 0) - arrayToInt(imm32, 32, 0)) < 0) {
                ALU_result[0] = 1;
            }
            break;
    }
}

int Cpu::EX() {

    int used = 0;

    if (hasIns3) {

//        if (pause == 0) {

        printf("Running %02d EX...\t", insn3 / 4 + 1);
        used = 1;
        hasIns3 = false;
        hasIns4 = true;

        //branch choose
        pc34 = pc23 + arrayToInt(imm32, 31, 0) * 4;

        //ALU
        if (!ALUSrc) {
            ALU(data1, data2, ALUOp);
        } else {
            ALU(data1, imm32, ALUOp);
        }

        //RegDst
        if (!RegDst) {
            RegDst34 = arrayToInt(IR23, 20, 16);
        } else {
            RegDst34 = arrayToInt(IR23, 15, 11);
        }

        if (RegWrite) {

            printf("Reg %02d is using!\t", RegDst34);

            regUsing[RegDst34] = 2;
        }

        printf("\n");

        copyArray(data2, data2_34, 0, 0, 32);
        MemWrite34 = MemWrite;
        MemRead34 = MemRead;
        MemToReg34 = MemToReg;
        RegWrite34 = RegWrite;
        insn4 = insn3;

//        }

    }
    return used;
}