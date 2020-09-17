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
    cin.getline(str1, size, '\n');

    cout << "Write second string: " << endl;
    cin.getline(str2, size, '\n');

    if (strlen(str1) > strlen(str2)) {
        while ((*str1 != '\0') && (strlen(str1) < size)){
            if (*str1 != *str2){
                cout << *str1 << " is different than " << *str2 << endl;
            }
            *str1++;
            *str2++;
        }
    }
    else {
        while ((*str2 != '\0') && (strlen(str2) < size)){
            if (*str2 != *str1){
                cout << *str2 << " is different than " << *str1 << endl;
            }
            *str1++;
            *str2++;
        }
    }
}

