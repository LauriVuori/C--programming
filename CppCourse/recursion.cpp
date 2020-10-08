/*1⁄2 + 1⁄4 + 1⁄6+...+1⁄2n
-1⁄3 * -2⁄5 * -3⁄7*...*-n⁄(2n+1)*/


#include <iostream>
using namespace std;

double firstRecursion(unsigned int);
double secondRecursion(int);

int main(void) {
	double result1, result2;
	unsigned int number;

	cout << "Type an integer number: ";
	cin >> number;
	if (number < 0){
		return -1;
	}

	result1 = firstRecursion(number);
	
    result2 = secondRecursion(number);
    cout << endl << "first result is: " << result1 << endl;
    cout << "second result is: " << result2 << endl;

	return 0;
}


double firstRecursion(unsigned int number) {
	double value = 0;
	if (number == 1) {
		cout << "number: " << number << "value: " << (1.0/(2.0 * number)) << endl;
        return (1.0 / (2.0 * number));
	}

    value = firstRecursion(number - 1) + 1.0/(2.0 * number);
	cout << "Num: " << number << " value: " << value <<endl;
	return(value);
}

double secondRecursion(int number) {
	double value = 0;
	if (number == 1) {
		cout << "number: " << number << "value: " << (-number/(2.0 * number+1)) << endl;
        return (-number/(2.0 * number + 1.0));
	}

    value = secondRecursion(number - 1) * -number/(2.0 * number + 1.0);
	cout << "Num: " << number << " value: " << value <<endl;
	return(value);
}


/*
    for (i = 1.0; i <= counter; i++){
        sum *= -i/(2.0*i+1.0);
    }
*/

/*
Sum is: 1.14167
Multiplication is: -0.011544*/