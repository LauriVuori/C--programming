//A program which reads a string 
// from the standard input and prints the content of the string in ascending order. 
// Use pointer(s) in the string handling.

#include <iostream>

using namespace std;
void sort(char * ptr1, char * ptr2);
int main(void){
    char string[50];
    int ii, bb;

    cout << "Give string: " << endl;
    cin >> string;
    for (ii = 0; string[ii] != '\0'; ii++){
        for (bb = ii+1; string[bb] != '\0'; bb++){
            if (string[ii] > string[bb]){
                sort(&string[ii], &string[bb]);
            }
        }

    }

    cout << string << endl;

}

void sort(char * ptr1, char * ptr2){
    char temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp; 

}