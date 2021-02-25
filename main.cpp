#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define SIZE 10

int main() {
    clock_t start, finish;
    start = clock();

    int a1[SIZE] = {0};
    int a2[SIZE];
    srand((unsigned) time(NULL));
    for (int i = 0; i < SIZE; ++i) a2[i] = rand();//initialize a2

    printf("The original arrays:\n");
    printf("a1:");
    for (int i = 0; i < SIZE; ++i) printf(" %d", a1[i]);
    printf("\na2:");
    for (int i = 0; i < SIZE; ++i) printf(" %d", a2[i]);
    printf("\n");

    for (int i = 0; i < SIZE; ++i) {
        //find the largest value
        int max = 0;//record the location of the largest value
        for (int j = 1; j < SIZE; ++j) {
            if (a2[j] > a2[max]) max = j;
        }
        a1[i] = a2[max];
        a2[max] = 0;
    }

    printf("The generated arrays:\n");
    printf("a1:");
    for (int i = 0; i < SIZE; ++i) printf(" %d", a1[i]);
    printf("\na2:");
    for (int i = 0; i < SIZE; ++i) printf(" %d", a2[i]);
    printf("\n");

    finish = clock();
    cout << "The execution time: " << finish - start;
    return 0;
}
