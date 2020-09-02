#include <iostream>
#include <cmath>

void FirstSequence();
void SecondSequence();
void ThirdSequence();

void SecondProblem();
void ThirdProblem();

using namespace std;
int main(void){
	// First problem
	FirstSequence();
	// SecondSequence();
	// ThirdSequence();
	// // Second problem
	// SecondProblem();
	// // Third problem
	// ThirdProblem();
}

void FirstSequence(){
	// 1 0 2 1 3 2 4 3 5...

	cout << "First numerical sequence"<< endl;
	
	int result = 0;
	float ii = 0;
	for (ii = 1; ii <= 15; ii++){
		if (int(ii) % 2 == 0){
			result = ii/2-1;
		}
		else{
			result = ii / 2.0 + 1.0/2.0;
		}
		cout << result << endl;
	}
	// for (float i = 1; i <= 15; i++){
	// 	result = (-1.0/4.0) + (i/2.0) - (pow(-1.0, i) * 3.0/4.0);
	// 	cout << result << " ";
	// }

	cout << "\n"<< endl;
}

void SecondSequence(){
	// 1 1 1 3 5 9 17...
	int num1 = 1, num2 = 1, num3 = 1, result = 0;
	cout << "Second numerical sequence"<< endl;
	cout << num1 << " " << num2 << " " << num3 << " ";

	for (int i = 0; i < 12; i++){
		result = num1 + num2 + num3;
		num1 = num2;
		num2 = num3;
		num3 = result;
		cout << result << " ";
	}
	cout<< "\n" << endl;
}

void ThirdSequence(){
	// -1 0 -3 -2 -5 -4 -7
	cout << "Third numerical sequence"<< endl;
	int num = -1;

	cout << num << " ";
	for (int i = 1; i < 15; i++){
		if (i%2 != 0){
			num++;
		}
		else{
			num -= 3;
		}
		cout << num << " ";
	}
	cout << "\n" << endl;

	// solution 2
	// int result = 0;
	// for (int i = 1; i <= 15; i++){
	// 	result = (pow(-1.0, i) + 1-i);
	// 	cout << result << " ";
	// }
}

void SecondProblem(){
	// A program, which receives two numbers and prints to the standard output device the sum of 
	// numbers between the given numbers.
	int num1, num2, result = 0;

	cout << "Second problem\n"<< endl;

	cout << "Give first number" << endl;
	cin >> num1;
	cout << "Give second number" << endl;
	cin >> num2;
	while (num1 < num2){
		num1 += 1;
		if (num1 < num2){
			result += num1;
		}

	}
	cout << "Sum is "<< result << "\n" <<endl;
}

void ThirdProblem(){
	//A program, which receives two numbers and prints to the standard output device the all 
	// prime numbers between the given numbers
	int num1, num2, start, ii;

	cout << "Third problem\n"<< endl; 

	cout << "Give first number" << endl;
	cin >> num1;
	cout << "Give second number" << endl;
	cin >> num2;
	cout << "Start value is: " << num1 << " Values between: ";
	while (num1 < num2){
		num1 += 1;
		if (num1 < num2){
			cout << num1 << " ";
		}
		else{
			cout << "End value is: " << num2 << endl;
		}
	}
	cout <<endl;
}