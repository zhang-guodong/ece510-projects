//
// Created by zhang on 2020/4/22.
//

#include "tools.h"

void showArray(int array[], int begin, int end) {
    for (int i = begin; i >= end; --i) {
        printf("%d", array[i]);
    }
}

void copyArray(int s[], int d[], int s_begin, int d_begin, int size) {
    for (int i = 0; i < size; ++i) {
        d[i + d_begin] = s[i + s_begin];
    }
}

long long arrayToInt(int array[], int begin, int end) {
    long long ans = 0;
    for (int i = begin; i >= end; i--) {
        ans = ans * 2 + array[i];
    }
    return ans;
}

void addArray(int a1[], int a2[], int r[], int size) {
    int carry = 0, sum;
    for (int i = 0; i < size; ++i) {
        sum = a1[i] + a2[i] + carry;
        switch (sum) {
            case 0:
                r[i] = 0;
                carry = 0;
                break;
            case 1:
                r[i] = 1;
                carry = 0;
                break;
            case 2:
                r[i] = 0;
                carry = 1;
                break;
            case 3:
                r[i] = 1;
                carry = 1;
                break;
        }
    }
}

void subArray(int a1[], int a2[], int r[], int size) {
    int borrow = 0, diff;
    for (int i = 0; i < size; ++i) {
        diff = a1[i] - a2[i] - borrow;
        switch (diff) {
            case 1:
                r[i] = 1;
                borrow = 0;
                break;
            case 0:
                r[i] = 0;
                borrow = 0;
                break;
            case -1:
                r[i] = 1;
                borrow = 1;
                break;
            case -2:
                r[i] = 0;
                borrow = 1;
                break;
        }
    }
}

void andArray(int a1[], int a2[], int r[], int size) {
    for (int i = 0; i < size; ++i) {
        if (a1[i] and a2[i]) r[i] = 1;
        else r[i] = 0;
    }
}

void orArray(int a1[], int a2[], int r[], int size) {
    for (int i = 0; i < size; ++i) {
        if (a1[i] or a2[i]) r[i] = 1;
        else r[i] = 0;
    }
}

void shiftL(int s[], int d[], int size, int shamt) {
    int i;
    for (i = size - 1; i - shamt >= 0; --i) {
        d[i] = s[i - shamt];
    }
    for (; i >= 0; --i) {
        d[i] = 0;
    }
}

void shiftR_logical(int s[], int d[], int size, int shamt) {
    int i;
    for (i = 0; i + shamt < size; ++i) {
        d[i] = s[i + shamt];
    }
    for (; i < size; ++i) {
        d[i] = 0;
    }
}

void ALUOp_string(int op) {
    switch (op) {
//R-type
        case 32://add
            printf("add");
            break;
        case 34://sub
            printf("sub");
            break;
        case 36://and
            printf("and");
            break;
        case 37://or
            printf("or");
            break;
        case 0: //sll
            printf("sll");
            break;
        case 2: //srl
            printf("srl");
            break;
        case 24://mul
            printf("mul");
            break;
//I-type
        case 800://addi
            printf("addi");
            break;
        case 1200://andi
            printf("andi");
            break;
        case 1300://ori
            printf("ori");
            break;
        case 3500://lw
            printf("lw");
            break;
        case 4300://sw
            printf("sw");
            break;
        case 400://beq
            printf("beq");
            break;
        case 1500://lui
            printf("lui");
            break;
        case 1000://slti
            printf("slti");
            break;
        case 1100://sltiu
            printf("sltiu");
            break;
        default:
            printf("error");
            break;
    }
}

int addArrayForMul(int a1[], int a2[], int r[], int r_bgein, int size) {
    int carry = 0;
    int sum;
    for (int i = 0; i < size; ++i) {
        sum = a1[i] + a2[i + r_bgein] + carry;
        switch (sum) {
            case 0:
                r[i + r_bgein] = 0;
                carry = 0;
                break;
            case 1:
                r[i + r_bgein] = 1;
                carry = 0;
                break;
            case 2:
                r[i + r_bgein] = 0;
                carry = 1;
                break;
            case 3:
                r[i + r_bgein] = 1;
                carry = 1;
                break;
        }
    }
    if (r_bgein + size <= 63) {
        r[r_bgein + size] = carry;
    }
    return carry;
}

void mulArray(int a1[], int a2[], int r[], int hi[], int size) {
    int ans[64] = {0};
    int carry = 0;
    for (int i = 0; i < size; ++i) {
        if (a2[i] == 1) {
            addArrayForMul(a1, ans, ans, i, size);
        }
    }
    copyArray(ans, r, 0, 0, size);
    copyArray(ans, hi, size, 0, size);
}

void hexArray(int a[], int size) {
    char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = size - 1; i >= 3; i = i - 4) {
        printf("%c", hex[arrayToInt(a, i, i - 3)]);
    }
}