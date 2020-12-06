#include <iostream>
#include <cstring>
using namespace std;

// Hint: To convert text to integere and decimal values you can use atoi(const char *_string) and 
// atof(const char *_string) functions. Respectively, numbers can be converted to text 
// using int sprintf (char * str, const char * format, double number) function, which 
// returns the number of characters of the text after conversion.

int main(void){
	char test[15] = {"1abasdc"};
	int i;
	i = atoi (test);
	i += 5;
	cout << i << endl;

}

	// //Here we reserve enough memory to store object attributes in the same block of memory
	// char temp[sizeof(sizeof(id) + first_name) + sizeof(surname)  + sizeof(salary)];
	// //char* object_data = new char[sizeof(name) + sizeof(salary)];
	// //Here we save all object data as characters to the temp array
	// int actual_size= sprintf_s(temp, "%d %s %s %.2f" , id, this->first_name, this->surname, this->salary);
	// temp[actual_size] = '\0';
	// //Here we reserve an array with one extra place for the NULL '\0' character
	// char* object_data = new char[actual_size+1];
	// strcpy_s(object_data,actual_size+1, temp);
	// return object_data;