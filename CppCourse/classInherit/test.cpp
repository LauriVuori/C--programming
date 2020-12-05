//This is constants.h file
#ifndef INCLUDE_CONSTANTS_H_
#define INCLUDE_CONSTANTS_H_
const unsigned int LEN = 50;
#endif /* INCLUDE_CONSTANTS_H_ */

--------------
//This is  project.h file
#ifndef INCLUDE_PROJECT_H_
#define INCLUDE_PROJECT_H_
#include "constants.h"
//Here we define class Person
class Project {
//Here we define protected members of the class
protected:
	char name[LEN];
	char task[LEN];
	unsigned int duration;
public:
	Project();
	Project(char*, char*, unsigned int);
	Project* search_project(char*);
	char* get_project_name();
	unsigned int get_project_duration();
	char* to_string();
	void print();
};
#endif /* INCLUDE_PROJECT_H_ */

--------------

//This is person.h
#ifndef INCLUDE_PERSON_H_
#define INCLUDE_PERSON_H_
#include "constants.h"
//Here we define class Person
class Person {
//Here we define protected members of the class
protected:
	unsigned int id;
	char first_name[LEN];
	char surname[LEN];
public:
	Person();
	Person(unsigned int, char*, char*);
	Person* search(unsigned int);
	char* to_string();
	void print();
};
#endif /* INCLUDE_PERSON_H_ */

--------------
//This is employee.h file
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_
#include "person.h"
#include "project.h"
#include "constants.h"
//Here we define class Employee, which inherits class Person in public mode
class Employee : public Person, public Project{
//Here we define private members of the class
	float salary;
//public and protected members of class person will be copied here
//Here we declare public member functions
public:
	Employee();
	Employee(unsigned int, char*, char*, char*, char*, unsigned int, float);
	char*  to_string();
	void print();
};
#endif /* INCLUDE_EMPLOYEE_H_ */
--------------

//This is project.cpp file

#include "../include/project.h"
#include "../include/constants.h"
#include <iostream>
#include <cstring>
using namespace std;
Project::Project(){
	strcpy_s(name, LEN, "Unknown");
	strcpy_s(task,LEN, "Unknown");
	duration=0;
}
Project::Project(char* name, char* task, unsigned int duration){
	strcpy_s(this->name, LEN, name);
		strcpy_s(this->task,LEN, task);
		this->duration=duration;
}
Project* Project::search_project(char* name){
	if(!strcmp(this->name, name))
		return this;
	return NULL;
}
char* Project::get_project_name() {
	return this->name;
}
unsigned int Project::get_project_duration(){
	return this->duration;
}
char* Project::to_string()
{
	//Here we reserve enough memory to store object attributes in the same block of memory
	char temp[sizeof(name) + sizeof(task)  + sizeof(duration)];
	//Here we save all object data as characters to the temp array
	int actual_size= sprintf_s(temp, "%s %s %d", this->name, this->task, this->duration);
	temp[actual_size] = '\0';
	//Here we reserve an array with one extra place for the NULL '\0' character
	char* object_data = new char[actual_size+1];
	strcpy_s(object_data,actual_size+1, temp);
	return object_data;
}

--------------
//This is person.cpp file

#include <iostream>
#include <cstring>
#include "../include/person.h"
using namespace std;


//In the following we implement constructors and methods
Person::Person(){
	id=0;
	strcpy_s(first_name, LEN, "Unknown");
	strcpy_s(surname,LEN, "Unknown");
}


Person::Person(unsigned int id, char* first_name, char* surname){
	this->id=id;
	strcpy_s(this->first_name,LEN, first_name);
	strcpy_s(this->surname,LEN, surname);
}

Person* Person::search(unsigned int id){
	if(this->id==id)
		return this;

	return NULL;
}

char* Person::to_string()
{
	//Here we reserve enough memory to store object attributes in the same block of memory
	char temp[sizeof(this->id) + sizeof(this->first_name) + sizeof(this->surname) ];

	//Here we save all object data as characters to the temp array
	int actual_size= sprintf_s(temp, "%d %s %s" , id, this->first_name, this->surname);
	temp[actual_size] = '\0';

	//Here we reserve an array with one extra place for the NULL '\0' character
	char* object_data = new char[actual_size+1];
	strcpy_s(object_data,actual_size+1, temp);
	return object_data;
}


void Person::print(){
cout << "Person information: " <<id<<" "<<(*this).first_name << " " <<this->surname<<" "<<endl;

}

--------------
//This is employee.cpp file
#include "../include/employee.h"
#include <iostream>
#include <cstring>
using namespace std;
//Here we define the default constructor for class Employee and call the
//default constructor of class Person
Employee::Employee():Person(), Project(){
  this->salary=0.0;
}
Employee::Employee(unsigned int id, char *first_name, char* surname, char* name, char* task, unsigned int duration, float salary):Person(id, first_name, surname), Project(name, task, duration) {
	this->salary = salary;
}
char* Employee::to_string()
{
	char info[] = "Employee information: \n";
	//Here we reserve enough memory to store object attributes in the same block of memory
	char temp[sizeof(info) + sizeof(this->id) + sizeof(this->first_name) + sizeof(this->surname) + sizeof(name) + sizeof(task)  + sizeof(duration) + sizeof(salary) ];
	//Here we save all object data as characters to the temp array
	int actual_size= sprintf_s(temp, "%s%s %s %.2f" , info, Person::to_string(), Project::to_string(), this->salary);
	temp[actual_size] = '\0';
	//Here we reserve an array with one extra place for the NULL '\0' character
	char* object_data = new char[actual_size+1];
	strcpy_s(object_data,actual_size+1, temp);
	return object_data;
}
void Employee::print() {
	cout << "Employee information: "<<endl;
	cout<<"Personal information: "<< Person::to_string()<<endl;
	cout<<"Project information: "<<Project::to_string()<<endl;
	//Person::print();
	//Project::print();
	cout <<"Salary: "<<this->salary << endl;
}

--------------
//This is main.cpp file
#include <iostream>
#include <cstring>
#include "../include/employee.h"
using namespace std;
int main() {
	unsigned int id;
		char first_name[LEN], surname[LEN];
		char project_name[LEN], task[LEN];
		unsigned int duration;
		float salary;
		//Here we declare an object of type Employee
		Employee *employee;
		cout << "Enter Employee id: ";
		cin>>id;
		getchar();
		cout << "Enter employee's first name: ";
		cin.getline(first_name, LEN, '\n');
		cout << "Enter employee's surname: ";
		cin.getline(surname, LEN, '\n');
		cout << "Enter employee's salary: ";
		cin>> salary;
		cin.ignore();
		cout << "Enter project name: ";
			cin.getline(project_name, LEN, '\n');
			cout << "Enter task name: ";
				cin.getline(task, LEN, '\n');
				cout << "Enter task duration: ";
					cin>>duration;
		//Here we call the constructor to initialise employee object.
		employee=new Employee(id, first_name, surname, project_name, task, duration, salary);
		cout<<employee->to_string()<<endl;
	unsigned int search_id;
	Employee* found_employee=NULL;
	do {
	  cout<<"Enter employee id to search:";
			cin>>search_id;
	  //The following statement would cause error if the inheritance mode of
	 //class Person is set to private.
       found_employee= (Employee*) employee->search(search_id);
       cout <<"Search results: " <<endl;
     //Here we check whether the search result has been NULL or not
	if(found_employee != NULL)
	  cout<<found_employee->to_string() << endl;
	else
		cout<<"Employee with id="<<search_id<<" not found!"<<endl;
	} while (found_employee==NULL);
	//Here we free memory from the heap
	delete employee;
    delete found_employee;
	return 0;
}