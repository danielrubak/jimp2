#include "MultiplicationTable.h"

void PrintMultiplicationTable (int tab [][10]) {
    for ( int i = 0; i < 10; i++ ) {
        for ( int j = 0; j < 10; j++ ) {
            std::cout.width(4);
            std::cout << tab[i][j];
            std::cout << " |";
        }
        std::cout << std::endl;
    }
}

void MultiplicationTable(int tab[][10]) {
    for ( int i = 0; i < 10; i++ ) {
        for (int j = 0; j < 10; j++) {
            tab[i][j] = (i + 1) * (j + 1);
        }
    }
}