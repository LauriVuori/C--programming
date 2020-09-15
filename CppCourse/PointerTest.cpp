#include <iostream>
using namespace std;
int main(void){
    int i = 5;
    int *ptr = &i;
    int &ref = *ptr;
    cout << "Address of i: " << &i << endl;
    cout << "Address of i in *ptr: " << ptr << endl;
    cout << "Value of ptr: " << *ptr << endl;
    cout << "Address of ptr: " << &ptr << endl;
    cout << "Reference of ptrs var address: " << &ref << endl;
    cout << "Reference of ptrs value: " << ref << endl;

}