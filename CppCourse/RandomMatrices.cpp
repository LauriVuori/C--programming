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

void printMat(int [][MATMAXCOL], 
              int [][MATMAXCOL], 
              int , 
              int );

void sumMat(int [][MATMAXCOL], 
              int [][MATMAXCOL], 
              int , 
              int );

void subMat(int [][MATMAXCOL], 
              int [][MATMAXCOL], 
              int , 
              int );

void multiMat(int [][MATMAXCOL], 
              int [][MATMAXCOL]);

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
    multiMat(firstMatr, secondMatr);
    
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
    cout << "Second matrices:" << endl;
    for (row = 0; row < matriceRows; row++) {
        for(colum = 0; colum < matriceColums; colum++) {
            cout << setw(3) << secondMatr[row][colum] <<  " ";
        }
        cout << endl;
    }
    cout << "\n\n" << endl;
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
    cout << "\n\n" << endl;
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
    cout << "\n\n" << endl;
}

void multiMat(int firstMatr[MATMAXROW][MATMAXCOL], 
              int secondMatr[MATMAXROW][MATMAXCOL]) {

    int multiMat[MATMAXROW][MATMAXCOL];
    int rowMat1, columMat1, rowMat2, columMat2;
    int row, colum;
    int ii, jj , kk;
    cout << "Multiplication of two matrices is: " << endl;
    rowMat1 = rand() % MAXROWS + MINROWS;
    columMat1 = rand() % MAXCOLUMS + MINCOLUMS;
    rowMat2 = columMat1;
    columMat2 = rand() % MAXCOLUMS + MINCOLUMS;


    cout << "First mat: " << endl;
    for (row = 0; row < rowMat1; row++) {
        for(colum = 0; colum < columMat1; colum++) {
            firstMatr[row][colum] = rand() % 10 + 1;
            cout << setw(3) << firstMatr[row][colum] << " ";
        }
        cout << endl;
    }
    cout << "Second mat: " << endl;
    for (row = 0; row < rowMat2; row++) {
        for(colum = 0; colum < columMat2; colum++) {
            secondMatr[row][colum] = rand() % 10 + 1;
            cout << setw(3) << secondMatr[row][colum] << " ";
        }
        cout << endl;
    }

    // for (row = 0; row < rowMat1; row++) {
    //     for(colum = 0; colum < columMat2; colum++) {
    //         multiMat[row][colum] = 0;
    //     }
    // }

    for(ii = 0; ii < rowMat1; ii++){
        for(jj = 0; jj < columMat2; jj++){
            multiMat[ii][jj] = 0;
            for(kk = 0; kk < rowMat2; kk++){
                multiMat[ii][jj] += firstMatr[ii][kk] * secondMatr[kk][jj];
            }
        }
    }
    cout << "\n" << "Result of mult: " << endl;
    for (row = 0; row < rowMat1; row++) {
        for(colum = 0; colum < columMat2; colum++) {
            cout << setw(3) << multiMat[row][colum] <<  " ";
        }
        cout << endl;
    }

}
