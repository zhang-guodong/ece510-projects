//
// Created by zhang on 2020/4/22.
//
#include "tools.h"

#ifndef ECE510PROJECT3_0_2_MEMORY_H
#define ECE510PROJECT3_0_2_MEMORY_H


class Memory {
public:
    int Mem[40 * 4][8]={0};

    void showMem(int begin, int size);//inside * 4

    void charToMem(char c[], int size);//inside * 4

    void intToMem(int a[], int size);//outside * 4

    void getMem(int addr, int d[]);//outside * 4
};


#endif //ECE510PROJECT3_0_2_MEMORY_H
