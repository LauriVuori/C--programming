
#include <iostream>
#include <cmath>


using namespace std;

int main(void){
    int num1, num2;
    double hypotenusa;
    cout << "Give first number: ";
    cin >> num1;
    cout << "Give first number: ";
    cin >> num2;
    hypotenusa = sqrt(pow(num1,2)+pow(num2,2));
    cout << "hypotenusa is:" << hypotenusa<< endl;
}
