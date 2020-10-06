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

#define MAXNUM 100
#define MINNUM 1

using namespace std;
int * smallestNum(int [], int);
int * biggestNum(int [], int);
void readNums(int [], int);

int main(void){
    int *numArr;
    int *smallest;
    int *biggest;
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
    cout <<"Smallest num is: " << *smallest << " its address is: " << smallest << endl;
    biggest = biggestNum(numArr, maxArrSize);
    cout <<"Biggest num is: " << *biggest << " its address is: " << biggest << endl;


    // cout << "test:" << numArr[0] << " <test" << endl;
    delete [] numArr;
    // cout << "test:" << numArr[0] << " <test" << endl;

}
void readNums(int numArr[], int maxNums){
    cout << "Numbers: " << endl;
    for (int i = 0; i < maxNums; i++){
        numArr[i] = rand() % MAXNUM + MINNUM;
        cout << numArr[i] << endl;
    }
}


int * smallestNum(int numArr[], int maxNums){
    int * smallestPtr = &numArr[0];
    int i;
    for (i = 0; i < maxNums; i++){
        if (numArr[i] < *smallestPtr){
            smallestPtr = &numArr[i];
        }
    }
    return smallestPtr;
    // cout <<"smallest:" << smallest << endl;
    // for (i = 0; i < maxNums; i++){
    //     if (numArr[i] == smallest){
    //         cout << "smallest address in function: " << numArr+i << endl;
    //         return numArr + i;
    //     }
    // }
    // return 0;
}

int * biggestNum(int numArr[], int maxNums){
    int * biggestPtr = &numArr[0];
    int i;
    for (i = 1; i < maxNums; i++){
        if (numArr[i] > *biggestPtr){
            biggestPtr = &numArr[i];
        }
    }
    return biggestPtr;



    // int biggest = -1000, i, counter = 0;
    // for (i = 0; i < maxNums; i++){
    //     if (numArr[i] > biggest){
    //         biggest = numArr[i];
    //     }
    // }
    // cout <<"biggest:" << biggest << endl;
    // for (i = 0; i < maxNums; i++){
    //     if (numArr[i] == biggest){
    //         cout << "biggest address in function: " << numArr+i << endl;
    //         return numArr + i;
    //     }
    // }
    // return 0;
}