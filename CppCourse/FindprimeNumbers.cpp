#include <iostream>

using namespace std;

void ThirdProblem();

int Prime(int num);

int main(void){
    ThirdProblem();
}

void ThirdProblem(){
	//A program, which receives two numbers and prints to the standard output device the all 
	// prime numbers between the given numbers
	int num1, num2, start, ii, prime;

	cout << "Third problem\n"<< endl; 

	cout << "Give first number" << endl;
	cin >> num1;
	cout << "Give second number" << endl;
	cin >> num2;
	cout << "Start value is: " << num1 << " Prime numbers between: ";
	int i = 0, result;
	while (num1 < num2){
		num1 += 1;
		prime = 0;
		if (num1 < num2){
			prime = Prime(num1);
			if (prime == 1){
				cout << num1 << " ";
			}
		}
		else{
			cout << " End value is: " << num2 << endl;
		}
	}
	cout <<endl;
}

int Prime(int num) 
{ 
    if (num <= 1) 
        return 0; 
  

    for (int i = 2; i < num; i++) 
        if (num % i == 0) 
            return 0; 
  
    return 1; 
} 
  