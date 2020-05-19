#include "Cpu.h"
#include "Memory.h"
#include <fstream>

using namespace std;

int main() {

//    Cpu cpu1;
    Memory mem1;//instruction memory
//    Memory mem2;//data memory

    int size = 34;//TODO
    int cyc_num = 74;//TODO
    int reg_size = 16;//TODO
    int data_size = 4;//TODO

    //load instructions
    char data[32];
    ifstream infile;
    infile.open("../Samples/test.txt");
    for (int i = 0; i < size; ++i) {
        infile >> data;
        mem1.charToMem(data, i);
    }
    infile.close();
    printf("Loading instructions finished.\n");
    //load end

    printf("Instruction Memory:\n");
    mem1.showMem(0, size);
//    system("pause");
    cout << endl;

    char repeat;
    do {
        Cpu cpu1;
        Memory mem2;//data memory

        //calculate the utilization factor
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        int c5 = 0;
        int sum = 0;

        int mode;
        cout << "Select between instruction(1) or cycle(2) mode:\n";
        cin >> mode;
        if (mode == 3) {

            int num_ins;
            cout << "Select the number of instructions:\n";
            cin >> num_ins;

            //single-cycle
            for (int i = 0; i < /*size*/num_ins; ++i) {
                printf("\nInstruction %02d\n", i + 1);

                c1 += cpu1.IF(mem1, size);
                c2 += cpu1.ID();
                c3 += cpu1.EX();
                c4 += cpu1.MEM(mem2);
                c5 += cpu1.WB();
                sum += 5;

                cpu1.showReg(reg_size);
                printf("Data Memory:\n");
                mem2.showMem(0, data_size);
//                system("pause");
            }
        } else if (mode == 2) {

            int num_cyc;
            cout << "Select the number of cycles:\n";
            cin >> num_cyc;

            //multi-cycle
            for (int i = 0; i < /*cyc_num*/num_cyc; ++i) {
                printf("\nCycle %02d\n", i + 1);

                c5 += cpu1.WB();
                c4 += cpu1.MEM(mem2);
                c3 += cpu1.EX();
                cpu1.ID_check();
                c2 += cpu1.ID();
                c1 += cpu1.IF(mem1, size);
//                cpu1.decPause();
                sum++;

//                printf("Pause: %d\n", cpu1.pause);

                cpu1.showReg(reg_size);

/*
                printf("RegCondition:\n");
                for (int j = 0; j < 32; ++j) {
                    printf("%d", cpu1.regUsing[j]);
                }
                printf("\n");
*/

                printf("Data Memory:\n");
                mem2.showMem(0, data_size);
//                system("pause");
            }
        } else if (mode == 1) {
            int num_ins;
            cout << "Select the number of instructions:\n";
            cin >> num_ins;

            int current = 0;
            int i = 0;
            while (current < num_ins) {
                printf("\nCycle %02d\n", ++i);

                c5 += cpu1.WB();
                c4 += cpu1.MEM(mem2);
                c3 += cpu1.EX();
                cpu1.ID_check();
                c2 += cpu1.ID();
                c1 += cpu1.IF(mem1, size);

                sum++;
                current += cpu1.runWB;

                if (cpu1.runWB) {
                    cpu1.showReg(reg_size);
                    printf("Data Memory:\n");
                    mem2.showMem(0, data_size);
                }
            }

        }


        cout << "\nProgram finished!\n";

        printf("Total cycle:\t%d\n", sum);
        printf("The utilization factor of each functional unit:\n");
        printf("In stage 1:\t%4.2f%%\n", (double) c1 / sum * 100.0, c1);
        printf("In stage 2:\t%4.2f%%\n", (double) c2 / sum * 100.0, c2);
        printf("In stage 3:\t%4.2f%%\n", (double) c3 / sum * 100.0, c3);
        printf("In stage 4:\t%4.2f%%\n", (double) c4 / sum * 100.0, c4);
        printf("In stage 5:\t%4.2f%%\n", (double) c5 / sum * 100.0, c5);

        cout << "Continue execution or not?(y/n)\n";
        cin >> repeat;

    } while (repeat == 'y' or repeat == 'Y');
    return 0;
}
