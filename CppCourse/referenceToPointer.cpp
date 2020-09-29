#include <iostream>

using namespace std;

int main(void){
    int i = 5;
    int *ptr = &i;
    int &ref = *ptr;

    cout << "ptr val: " << *ptr << endl;
    cout << "ref val: " << ref << endl;
    cout << "ptr addr: " << ptr << endl;
    cout << "ref addr: " << &ref << endl;

} 
