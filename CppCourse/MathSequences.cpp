#include <iostream>
#include <cmath>

void FirstProblem();
void SecondProblem();
void ThirdPorblem();

using namespace std;
int main(void){
	FirstProblem();
	SecondProblem();
	// ThirdPorblem();
}

void FirstProblem(){
	// 1 0 2 1 3 2 4 3 5...
	float result = 0;
	cout << "First numerical sequence"<< endl;
	
	for (float i = 1; i <= 15; i++){
		result = (-1.0/4.0) + (i/2.0) - (pow(-1.0, i) * 3.0/4.0);
		cout << result << " ";
	}
	cout << "\n"<< endl;
}

void SecondProblem(){
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

void ThirdPorblem(){
	// -1 0 -3 -2 -5 -4 -7.
}