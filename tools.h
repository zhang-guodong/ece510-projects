//
// Created by zhang on 2020/4/22.
//
#include <iostream>

#ifndef ECE510PROJECT3_0_2_TOOLS_H
#define ECE510PROJECT3_0_2_TOOLS_H


void showArray(int array[], int begin, int end);

void copyArray(int s[], int d[], int s_begin, int d_begin, int size);

long long arrayToInt(int array[], int begin, int end);//TODO return data type?

void addArray(int a1[], int a2[], int r[], int size);

void subArray(int a1[], int a2[], int r[], int size);

void andArray(int a1[], int a2[], int r[], int size);

void orArray(int a1[], int a2[], int r[], int size);

void shiftL(int s[], int d[], int size, int shamt);

void shiftR_logical(int s[], int d[], int size, int shamt);

void ALUOp_string(int op);

int addArrayForMul(int a1[], int a2[], int r[], int r_bgein, int size);

void mulArray(int a1[], int a2[], int r[], int hi[], int size);

void hexArray(int a[],int size);

#endif //ECE510PROJECT3_0_2_TOOLS_H
