#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;


int main() 
{
    string rivi;
    int num, sum = 0;
 
    ifstream luku("nums.txt");

    if (luku.is_open()) {

    luku >> num;
    sum += num;

        while (luku >> num) {
            sum += num;
        }
    
    } 
    else {
    cout << "Cannot open file!" << endl;
    exit(-1);
    }
    printf("%d", sum);
}