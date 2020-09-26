/*
A program, which reads a an array of numbers and prints the smallest and 
the biggest values of the numbers. The program must ask how many numbers the user
wants to enter and then read the numbers and print the maximum and the minimum values. 
In the program use a function for reading the numbers, a function, which returns the memory 
address of the smallest value and another function, which returns the memory address of the 
biggest value. The program must use these memory addresses to print the smallest and the biggest values. 
1. how many nums -> arr max
2. rand nums on array
3. func find smallest, return mem address
4. func find biggest, return mem address
*/


#include <iostream>
#include <ctime>

using namespace std;
int * smallestNum(int [], int nums);
void biggestNum(int []);
void readNums(int [], int);

int main(void){
    int *numArr;
    int *smallest;
    int maxArrSize = 0;
    srand(time(NULL));

    cout << "How many numbers you want in array:" << endl;
    cin >> maxArrSize;
    cin.get();
    while ((maxArrSize < 0)){
        cout << "wrong input, give new value:" << endl;
        cin >> maxArrSize;
        cin.get();
    }

    numArr = new int[maxArrSize];

    readNums(numArr, maxArrSize);
    smallest = smallestNum(numArr, maxArrSize);
    cout << numArr[0] << endl;
    cout << *smallest << endl;
    // cout << "main-->" << endl;
    // for (int i = 0; i < maxArrSize; i++){
    //     cout << numArr[i] << endl;
    // }
    // works

}
void readNums(int numArr[], int maxNums){
    cout << "Func" << endl;
    for (int i = 0; i < maxNums; i++){
        numArr[i] = rand() % 10 + 1;
        // cout << numArr[i] << endl;
    }
}


int * smallestNum(int numArr[], int maxNums){
    return numArr;
}