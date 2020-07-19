#include <iostream>
using namespace std;

int main(){
    

    int num1, num2;
    double sum;
    int command;
    cout << "Give command";
    cin >> command;
    cout << "Give first num:";
    cin >> num1;
    cout << "Give second num";
    cin >> num2;

    switch (command)
    {
    case 2:
        sum = num1 + num2;
        cout << sum << endl;
        break;
    case 1:
        sum = num1 - num2;
        cout << sum << endl;
        break;
    case 3:
        sum = num1 * num2;
        cout << sum << endl;
        break;
    case 5:
        sum = num1 % num2;
        cout << sum << endl;
        break;
    case 4:
        sum = num1 / num2;
        cout << sum << endl;
        break;
    default:
        cout << "Default" << endl;
        break;
    }
}
