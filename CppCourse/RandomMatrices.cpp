// A program, which initializes randomly two matrixes and calculates the sum, subtraction and multiplication of 
// them and prints the result to the standard output device. The program should also determine the dimensions of matrixes randomly, 
// but it should take care that generated matrixes have proper dimensions to go  through basic operations.
#include <iostream>
#include <ctime>
#include <iomanip>

#define MAXROWS 6
#define MINROWS 2
#define MAXCOLUMS 10
#define MINCOLUMS 2

#define MATMAXROW 20
#define MATMAXCOL 20

using namespace std;

void printMat(int firstMatr[MATMAXROW][MATMAXCOL], 
              int secondMatr[MATMAXROW][MATMAXCOL], 
              int matriceRows, 
              int matriceColums);

void sumMat(int firstMatr[MATMAXROW][MATMAXCOL], 
            int secondMatr[MATMAXROW][MATMAXCOL], 
            int matriceRows, int matriceColums);

void subMat(int firstMatr[MATMAXROW][MATMAXCOL], 
            int secondMatr[MATMAXROW][MATMAXCOL], 
            int matriceRows, int matriceColums);

void multiMat(int firstMatr[MATMAXROW][MATMAXCOL], 
              int secondMatr[MATMAXROW][MATMAXCOL], 
              int matriceRows, int matriceColums);

int main(void){
    int matriceRows = 0, matriceColums = 0;
    int firstMatr[MATMAXROW][MATMAXCOL];
    int secondMatr[MATMAXROW][MATMAXCOL];
    int row, colum;
    bool rule = 0;

    srand(time(NULL));

    matriceRows = rand() % MAXROWS + MINROWS;
    matriceColums = rand() % MAXCOLUMS + MINCOLUMS;
    cout << "Rows: " << matriceRows << "Colums: " << matriceColums << endl;



    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            firstMatr[row][colum] = rand() % 10 + 1;
            secondMatr[row][colum] = rand() % 10 + 1;
        }
    }

    printMat(firstMatr, secondMatr, matriceRows, matriceColums);
    sumMat(firstMatr, secondMatr, matriceRows, matriceColums);
    subMat(firstMatr, secondMatr, matriceRows, matriceColums);
    cout << "Multiplication of two matrices is: " << endl;

    multiMat(firstMatr, secondMatr, matriceRows, matriceColums);
    
}

void printMat(int firstMatr[MATMAXROW][MATMAXCOL], 
              int secondMatr[MATMAXROW][MATMAXCOL], 
              int matriceRows, 
              int matriceColums) {

    int row, colum;

    cout << "First matrices:" << endl;
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << setw(3) << firstMatr[row][colum] <<  " ";
        }
        cout << endl;
    }
    cout << "Secodn matrices:" << endl;
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << setw(3) << secondMatr[row][colum] <<  " ";
        }
        cout << endl;
    }
}

void sumMat(int firstMatr[MATMAXROW][MATMAXCOL], 
            int secondMatr[MATMAXROW][MATMAXCOL], 
            int matriceRows, int matriceColums){
    int sumMat[MATMAXROW][MATMAXCOL];
    int row, colum;

    cout << "Sum of two matrices is: " << endl;

    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            sumMat[row][colum] = firstMatr[row][colum] + secondMatr[row][colum];
            cout << setw(3) << sumMat[row][colum] <<  " ";
        }
    cout << endl;
    }
}

void subMat(int firstMatr[MATMAXROW][MATMAXCOL], 
            int secondMatr[MATMAXROW][MATMAXCOL], 
            int matriceRows, int matriceColums){
    int subMat[MATMAXROW][MATMAXCOL];
    int row, colum;

    cout << "Subtraction of two matrices is: " << endl;

        for (row = 0; row < matriceRows; row++) {
            for(colum = 0; colum < matriceColums; colum++) {
                subMat[row][colum] = firstMatr[row][colum] - secondMatr[row][colum];
                cout << setw(3) << subMat[row][colum] <<  " ";
            }
            cout << endl;
        }
}

void multiMat(int firstMatr[MATMAXROW][MATMAXCOL], 
              int secondMatr[MATMAXROW][MATMAXCOL], 
              int matriceRows, int matriceColums){
    int multiMat[MATMAXROW][MATMAXCOL];
    int row, colum;
    int ii, jj , kk;
    
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            multiMat[row][colum] = 0;
        }
    }

    for(ii = 0; ii < row; ii++){
        for(jj = 0; jj < colum; jj++){
            for(kk = 0; kk < row; kk++){
                multiMat[ii][jj] += firstMatr[ii][kk] * secondMatr[kk][jj];
            }
        }
    }

    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << setw(3) << multiMat[row][colum] <<  " ";
        }
        cout << endl;
    }

}
