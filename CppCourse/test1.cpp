#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 50;
//Here we use keyword class to create 
//a new data type
class Employee {
	//These are private member variables
	char name[LEN];
	float salary;
	//Here we declare public member functions
public:
	void set_info(char*, float);
	char*  to_string();
	void print();
};
//This is the definition of function set_info()
void Employee::set_info(char *name, float salary) {
	strcpy(this->name, LEN, name);
	this->salary = salary;
}
char* Employee::to_string()
{
	//Here we reserve enough memory to store object attributes in the same block of memory
	char temp[sizeof(name) + sizeof(salary)];
	//char* object_data = new char[sizeof(name) + sizeof(salary)];
	//Here we save all object data as characters to the temp array
	int actual_size= sprintf_s(temp, "%s  %.2f" , this->name, this->salary);
	temp[actual_size] = '\0';
	
	//Here we reserve an array with one extra place for the NULL '\0' character
	char* object_data = new char[actual_size+1];
	strcpy(object_data,actual_size+1, temp);
	return object_data;
}
void Employee::print() {
	cout << "Employee information: " << (*this).name << " " << this->salary << endl;
}
//Here we define a new data type using keyword struct
struct Profession {
	//These are public member functions
	char* get_type();
	void set(char *, int);
	char* to_string();
	//Here we declare private member variables
private:
	char type[LEN];
	int rank;
};
char* Profession::get_type() {
	return this->type;
}
void Profession::set(char *type, int rank) {
	strcpy(this->type,LEN, type);
	this->rank = rank;
}
char * Profession::to_string()
{
	//Here we reserve enough memory to store object attributes in the same block of memory
	char temp[sizeof(this->type) + sizeof(this->rank)];
	//Here we save all object data as characters to the temp array
	int actual_size = sprintf_s(temp, "%s  %d", this->type, this->rank);
	temp[actual_size] = '\0';
	//Here we reserve an array with one extra place for the NULL '\0' character
	char* object_data = new char[actual_size + 1];
	strcpy(object_data, actual_size + 1, temp);
	return object_data;
}
int main() {
	char type[LEN], name[LEN];
	float salary;
	int rank;
	//Here we declare an object of type Employee
	Employee e;
	//Here we declare an object of type Profession
	Profession p;
	cout << "Enter the type of the Profession: ";
	cin.getline(type, LEN, '\n');
	cout << "Enter the rank of the profession as an integer number";
	cin >> rank;
	//Here we call functions set_type() and get_type() of object p
	p.set(type, rank);
	cout << "Profession info : " << p.to_string() << endl;
	//Here we bypass the Enter key
	cin.ignore();
	cout << "Enter the Employee name: ";
	cin.getline(name, LEN, '\n');
	cout << "Enter the Employee salary: ";
	cin>> salary;
	//Here we call functions set_info() and print() of object e
	e.set_info(name, salary);
	//Here we call functions  e.to_string() to get employee info as text
	cout <<"Employee info: " << e.to_string() << endl;
	return 0;
}
