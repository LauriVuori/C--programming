// A program in which you define two null-terminated strings by using two pointer variables of type char. 
// Using only pointers the program must compare two strings 
// character by character and inform what characters in the strings are different.

#include <iostream>

using namespace std;

void compare(char * ptr1, char * ptr2);

int main(void){
    int same = 0;
    char str1[25] = {"aapeli"};
    char str2[25] = {"aapeli"}; 
    printf("<main:%p>", str1);

    // for (int i = 0; str1[i] != '\0'; i++){
    //     cout << str1[i];
    // }
    // cout << endl;
    // printf("main %p\n", &str2[3]);
    same = compare(str1, str2);
    if (same == 0) {
        cout << "Not same strings" << endl;
    }
    else {
        cout << "Same strings"
    }

}

int compare(char * ptr1, char * ptr2){
    printf("%p", ptr1);
    for (int i = 0; ptr1[i] != '\0'; i++){
        if (ptr1[i] != ptr2){
            return 0;
        }
    }
    return 1;
}