/*1⁄2 + 1⁄4 + 1⁄6+...+1⁄2n
-1⁄3 * -2⁄5 * -3⁄7*...*-n⁄(2n+1)*/


#include <iostream>
using namespace std;

int main(void){
    int counter = 0, i = 0;
    double sum = 0;

    cout << "How many times:" << endl;
    cin >> counter;
    cin.get();

    for (i = 1; i <= counter; i++){
        sum += 1.0/(2.0*i);
    }
    cout << "Sum is: " << sum << endl;
    sum = 1;
    for (i = 1.0; i <= counter; i++){
        sum *= -i/(2.0*i+1.0);
    }
    cout << "Multiplication is: " << sum << endl;
}