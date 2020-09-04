// A program, which initializes randomly two matrixes and calculates the sum, subtraction and multiplication of 
// them and prints the result to the standard output device. The program should also determine the dimensions of matrixes randomly, 
// but it should take care that generated matrixes have proper dimensions to go  through basic operations.
#include <iostream>
#include <ctime>

#define MAXROWS 10
#define MINROWS 1
#define MAXCOLUMS 10
#define MINCOLUMS 1

using namespace std;

int main(void){
    int matriceRows = 0, matriceColums = 0;
    int row, colum;
    srand(time(NULL));

    matriceRows = rand() % MAXROWS + MINROWS;
    matriceColums = rand() % MAXCOLUMS + MINCOLUMS;
    cout << "Rows: " << matriceRows << "Colums: " << matriceColums << endl;
    // remove
    matriceRows = 2;
    matriceColums = 2;
    int firstMatr[matriceRows][matriceColums] = {};
    int secondMatr[matriceRows][matriceColums] = {};
    
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            firstMatr[row][colum] = rand() % 10 + 1;
            secondMatr[row][colum] = rand() % 10 + 1;
        }
    }
    cout << "First matrices:" << endl;
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << firstMatr[row][colum] <<  " ";
        }
        cout << endl;
    }

    cout << "Secodn matrices:" << endl;
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << firstMatr[row][colum] <<  " ";
        }
        cout << endl;
    }

}
