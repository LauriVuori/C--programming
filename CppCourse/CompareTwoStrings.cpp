// A program in which you define two null-terminated strings by using two pointer variables of type char. 
// Using only pointers the program must compare two strings 
// character by character and inform what characters in the strings are different.

#include <iostream>
#include <cstring>

using namespace std;

void compare(char * ptr1, char * ptr2);

int main(void){
    char *str1, *str2;
    int i, size;

    cout << "Enter array size: ";
    cin >> size;
    getchar();

    str1 = (char*) malloc(size * sizeof(char));
    str2 = (char*) malloc(size * sizeof(char));

    cout << "Write first string: " << endl;
    cin.getline(str1, size);

    cout << "Write second string: " << endl;
    cin.getline(str2, size);


    if (strlen(str1) > strlen(str2)){
        for (i = 0; i < strlen(str1); i++){
            compare(&str1[i], &str2[i]);
        }
    }
    else{
        for (i = 0; i < strlen(str2); i++){
            compare(&str1[i], &str2[i]);
        }
    }    
}

void compare(char * ptr1, char * ptr2){
    if (*ptr1 != *ptr2){
        cout << *ptr1 << " is different than " << *ptr2 << endl;
    }
}