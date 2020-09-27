/*
A program, which reads a number of names from the keyboard and then prints them to the standard output 
device in ascending order. In the program define a function for reading names, one function for 
sorting them and another function for printing them out. 
The program should ask in the beginning how many numbers the user is going to enter.
1. func -> how many names, and read them
2. func -> sort them
3. func -> print 
*/
#include <iostream>
#include <string.h>

#define MAXLENGHT 30

using namespace std;
void insertNames(char **, int);
void sortNames(char **, int);
void printNames(char **, int);
int main(void){
    char **namesArr;
    int maxNames = 0;

    cout << "How many names do you want: " << endl;
    cin >> maxNames;
    cin.get();

    namesArr = new char *[maxNames];
    for(int i = 0; i < maxNames; ++i) {
        namesArr[i] = new char[MAXLENGHT];
    }

    insertNames(namesArr,maxNames);
    sortNames(namesArr,maxNames);
    printNames(namesArr, maxNames);
    // cout << "Main: " << endl;
    // for (int i = 0; i < maxNames; i++) {
    //     cout << i+1 << ": " << namesArr[i] << endl;
    // }
    // int asd = strcmp(namesArr[0], namesArr[1]);
    // cout << asd;
    for(int i = 0; i < maxNames; ++i) {
        delete [] namesArr[i];
    }
    delete [] namesArr;
}

void insertNames(char ** namesArr, int maxNames){
    for (int i = 0; i < maxNames; i++){
        cout << "Give name: " << endl;
        cin.getline(namesArr[i], MAXLENGHT, '\n');
    }
    // cout << "Func:" << endl;
    // for (int i = 0; i < maxNames; i++){
    //     cout << i+1 << ": " << namesArr[i] << endl;
    // }
}

void sortNames(char ** namesArr, int maxNames){
    char temp[MAXLENGHT];
    int i, j;
    for (i = 0; i < maxNames; i++){
        for (j = i+1; j < maxNames; j++){
            if (strcmp(namesArr[i], namesArr[j]) > 0){
                strcpy(temp, namesArr[i]);
                strcpy(namesArr[i], namesArr[j]);
                strcpy(namesArr[j], temp);
            }
        }
    }
}
void printNames(char ** namesArr, int maxNames){
    cout << "names in ascending order:" << endl;
    for (int i = 0; i < maxNames; i++){
        cout << i+1 << ": " << namesArr[i] << endl;
    }
}