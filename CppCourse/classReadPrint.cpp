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
The program must print to the standard output and update a counter which shows the number of employees 
whose information are saved in the database. The program must 
keep on showing the menu and letting the user to make a choice as long as Q is not pressed.*/

// pointer -> objektiin, jos funktion saama id on sama kuin objektin id


#include <iostream>
#define MAXLEN 25
using namespace std;
class employee{
private:
    char name[MAXLEN];
    char id[MAXLEN];
    float salary;
public:
    void print_values();
    void set_values();
    employee * search_employee(employee [], char, int);

};
void employee::set_values(){
    cout << "Give name: " << endl;
    cin.getline(name, MAXLEN, '\n');
    cout << "Give id" << endl;
    cin.getline(id, MAXLEN, '\n');
    cout << "Give salary:" << endl;
    cin >> salary;
    cin.get(); 
}

void employee::print_values(){
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Salary: " << salary << endl;
}

employee * employee::search_employee(employee list[], char findId[], int count){
    int i = 0;

    
    return &list;
}


int main(void){
    employee employeeList[25];
    employee *test;
    char menu;
    int employeeCount = 0;
    int i = 0, id = 0;

    while (menu != 'q'){
        cout << "Options:\na) Add new employee information\nb) remove employee's information \nc)Search based on id \nd)print\nq)exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += 32;
        }
        switch (menu){
            case 'a':
                employeeList[employeeCount].set_values();
                employeeCount++;
                break;
            case 'b':
                cout << "BBB" << endl;
                break;
            case 'c':
                cout << "Which id to find:" << endl;
                // cin >> id;
                // cin.get();
                test = search_employee(employeeList, 1, 1);
                break;
                
            case 'd':
                cout <<"which num: "<< endl;
                cin >> i;
                cin.get();
                employeeList[i].print_values(); 
                break;
            case 'q':
                cout << "Program shuts down" << endl;
                return false;
                break;
            default:
                cout << "Wrong input" << endl;
                break;
        }
    }
   return true;

}