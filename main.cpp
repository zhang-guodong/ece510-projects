#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand((unsigned) time(NULL));
    int i = rand();
    cout << i << endl;
    cout << "The random integer is ";
    if (i <= 100) cout << "not ";
    cout << "greater than 100.";
    return 0;
}
