//
// Created by zhang on 2020/4/22.
//

#include "Memory.h"

void Memory::showMem(int begin, int size) {
    for (int i = begin; i < size; ++i) {
        printf("0x");
        printf("%08x:\t", 4 * i);

        showArray(Mem[4 * i + 0], 7, 0);
        showArray(Mem[4 * i + 1], 7, 0);
        showArray(Mem[4 * i + 2], 7, 0);
        showArray(Mem[4 * i + 3], 7, 0);

        printf("  0x");
        hexArray(Mem[4 * i + 0], 8);
        hexArray(Mem[4 * i + 1], 8);
        hexArray(Mem[4 * i + 2], 8);
        hexArray(Mem[4 * i + 3], 8);

        printf("\n");
    }
}

void Memory::charToMem(char c[], int size) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Mem[4 * size + i][j] = c[(i + 1) * 8 - 1 - j] - '0';
        }
    }
}

void Memory::intToMem(int a[], int size) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Mem[/*4 **/ size + i][j] = a[(3 - i) * 8 + j];
        }
    }
}

void Memory::getMem(int addr, int d[]) {
    copyArray(Mem[addr + 0], d, 0, 24, 8);
    copyArray(Mem[addr + 1], d, 0, 16, 8);
    copyArray(Mem[addr + 2], d, 0, 8, 8);
    copyArray(Mem[addr + 3], d, 0, 0, 8);
}