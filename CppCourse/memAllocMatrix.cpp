/*
A program which uses dynamic memory allocation for reserving memory 
for two matrix variables, initializes them randomly and calculates 
their multiplication and prints the result to the standard output. 
The program must set the dimensions of matrixes randomly during run-time 
and make sure that multiplication operation is possible for matrixes 
with generated dimensions.
*/

#include <iostream>
#include <ctime>
#include <iomanip>

#define ROWS 3
#define COLS 3




using namespace std;

int main(void){
    int row1M, colum1M, colum2M, row2M, rowResult, columResult, row, colum;

    srand(time(NULL));
    row1M = rand() % 7 + 1;
    colum1M = rand() % 7 + 1;
    row2M = colum1M;
    colum2M = rand() % 7 + 1;
    // colum 1 == row 2

    int **matrix1 = new int *[row1M];
    int **matrix2 = new int *[row2M];
    
    for(int i = 0; i < row1M; ++i) {
        matrix1[i] = new int[colum1M];
    }

    for(int i = 0; i < row2M; ++i) {
        matrix2[i] = new int[colum2M];
    }

    rowResult = row1M;
    columResult = colum2M;
    int **result = new int *[rowResult];
    for(int i = 0; i < rowResult; ++i) {
        result[i] = new int[colum2M];
    }

    srand(time(NULL));

    cout << "First mat: " << endl;
    for (row = 0; row < row1M; row++) {
        for(colum = 0; colum < colum1M; colum++) {
            matrix1[row][colum] = rand() % 10 + 1;
            cout << setw(3) << matrix1[row][colum] << " ";
        }
        cout << endl;
    }
    cout << "Second mat: " << endl;
    for (row = 0; row < row2M; row++) {
        for(colum = 0; colum < colum2M; colum++) {
            matrix2[row][colum] = rand() % 10 + 1;
            cout << setw(3) << matrix2[row][colum] << " ";
        }
        cout << endl;
    }

    int ii, jj, kk;
    for(ii = 0; ii < row1M; ii++){
        for(jj = 0; jj < colum2M; jj++){
            result[ii][jj] = 0;
            for(kk = 0; kk < row2M; kk++){
                result[ii][jj] += matrix1[ii][kk] * matrix2[kk][jj];
            }
        }
    }

    cout << "\n" << "Result of mult: " << endl;
    for (row = 0; row < rowResult; row++) {
        for(colum = 0; colum < columResult; colum++) {
            cout << setw(3) << result[row][colum] <<  " ";
        }
        cout << endl;
    }

    for(int i = 0; i < row1M; ++i) {
        delete [] matrix1[i];
    }
    for(int i = 0; i < row2M; ++i) {
        delete [] matrix2[i];
    }
    for(int i = 0; i < rowResult; ++i) {
        delete [] result[i];
    }

    delete [] matrix1;
    delete [] matrix2;
    delete [] result;

}