#include <iostream>
#include <cstring>

int main(void){
    char temp[50] = {"terve"};
    char asd[50] = {"ville"};

    int a = 0;
    a = strcmp(temp, asd);
    printf("%d", a);
}