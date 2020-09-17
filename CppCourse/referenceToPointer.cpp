#include <iostream>

using namespace std;

int main(void){

    int *ptr;
    int &ref = *ptr;
    cout << ptr << endl;
    cout << &ref << endl;
}