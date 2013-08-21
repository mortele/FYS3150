#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void binaryFloat(double input) {
    int  n = 20;
    int* binaryInteger  = new int[n];
    int* binaryFloating = new int[n];

    int      integer  = (int) floor(input);
    double   floating = input;
    floating = floating - ((double) integer);

    // Convert integer part to binary.
    for (int i = 0; i < n; i++) {
        binaryInteger[i]  = integer % 2;
        integer          /= 2;
    }

    // Convert floating part to binary.
    bool exact   = false;
    int  numbers = n;

    for (int i = 0; i < n; i++) {
        floating *= 2;
        if (floating > 1) {
            floating       -= 1;
            binaryFloating[i]  = 1;
        } else if (floating < 1){
            binaryFloating[i]  = 0;
        } else {
            binaryFloating[i]  = 1;
            exact   = true;
            numbers = i+1;
            break;
        }
    }

    // Dump number in binary form to terminal.
    cout << "Decimal representation: " << input << endl;
    cout << "Binary representation:  ";

    bool zeros = true;
    for (int i = n-1; i >= 0; i--) {
        if (!(binaryInteger[i] == 0 && zeros == true)) {
            cout << binaryInteger[i];
            zeros = false;
        }
    }
    cout << ".";
    if (exact) n = numbers;
    for (int i = 0; i < n; i++) {
        cout << binaryFloating[i];
    }
    cout << endl << endl;
}

