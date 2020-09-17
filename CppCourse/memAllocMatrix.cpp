// A program which uses dynamic 
// memory allocation for reserving memory for two matrix 
// variables, calculates their multiplication 
// and prints the result to the standard output.

#include <iostream>
#include <ctime>
#include <iomanip>

#define ROWS 3
#define COL 3


using namespace std;

int main(void){
    int row, colum;
    int **matrix1 = new int *[3];
    int **matrix2 = new int *[3];
    int **result = new int *[3];
    for(int i = 0; i < 3; ++i) {
        matrix1[i] = new int[3];
    }

    for(int i = 0; i < 3; ++i) {
        matrix2[i] = new int[3];
    }

    for(int i = 0; i < 3; ++i) {
        result[i] = new int[3];
    }

    srand(time(NULL));

    cout << "First mat: " << endl;
    for (row = 0; row < ROWS; row++) {
        for(colum = 0; colum < COL; colum++) {
            matrix1[row][colum] = rand() % 10 + 1;
            cout << setw(3) << matrix1[row][colum] << " ";
        }
        cout << endl;
    }
    cout << "Second mat: " << endl;
    for (row = 0; row < ROWS; row++) {
        for(colum = 0; colum < COL; colum++) {
            matrix2[row][colum] = rand() % 10 + 1;
            cout << setw(3) << matrix2[row][colum] << " ";
        }
        cout << endl;
    }

    int ii, jj, kk;
    for(ii = 0; ii < ROWS; ii++){
        for(jj = 0; jj < COL; jj++){
            result[ii][jj] = 0;
            for(kk = 0; kk < ROWS; kk++){
                result[ii][jj] += matrix1[ii][kk] * matrix2[kk][jj];
            }
        }
    }

    cout << "\n" << "Result of mult: " << endl;
    for (row = 0; row < ROWS; row++) {
        for(colum = 0; colum < COL; colum++) {
            cout << setw(3) << result[row][colum] <<  " ";
        }
        cout << endl;
    }

    for(int i = 0; i < ROWS; ++i) {
        delete [] matrix1[i];
        delete [] matrix2[i];
        delete [] result[i];
    }
    delete [] matrix1;
    delete [] matrix2;
    delete [] result;

}