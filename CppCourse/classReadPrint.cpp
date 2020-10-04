/*
Write a C++ program in which you define class employee and necessary 
functions for reading employees' information and saving them to an array 
of class employee. The member variables of the class should be: name, id and salary. 
The member functions of the class should be set_values(), print_values() and search_employee(). 
The function search_employee() should return a pointer to the object if the 
id it receives as parameter is the same as the id of the object. 
Declare all variables as private and use only functions for manipulating them. 
The program must print to the standard output a menu, from which user can choose the following actions:
A: add new employee information
R: remove employee's information
S: search based on employee's ID
Q: quit
The program must print to the standard output and update a counter which shows the number of employees whose information are saved in the database. The program must 
keep on showing the menu and letting the user to make a choice as long as Q is not pressed.*/
#include <iostream>

using namespace std;
class employee{
    private:
    char name[25];
    char empId[25];
    int salary;
    public:
    void print_values();
    void set_values();

};
void employee::set_values(){
    cout << "Give name: " << endl;
    cin.getline(name, 25, '\n');
    cout << "Give salay:" << endl;
    cin >> salary;
    cin.get(); 
}

void employee::print_values(){
    cout << "print:" << name << endl;
    cout << "print sal " << salary << endl;
}
int main(void){
    employee test[5];
    char menu;
    test[0].set_values();
    test[1].set_values();
    // test.salary = 5;
    // test[0].print_values();

    for (int i = 0; i < 2; i++){
        test[i].print_values();
    }

}