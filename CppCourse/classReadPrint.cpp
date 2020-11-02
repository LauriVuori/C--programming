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
#include <cstring>

#define MAXLEN 25
#define LOWERCASE 32

using namespace std;

class employee{
private:
    char name[MAXLEN];
    char id[MAXLEN];
    float salary;
public:
    void print_values();
    void set_values(char* , char*, float);
    employee* search_employee(char*);
    

};

void employee::set_values(char* name, char* id, float salary){
    strcpy(this->name, name);
    strcpy(this->id, id);
    this->salary = salary;
}

void employee::print_values(){

    cout << "Employee information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Salary: " << salary << endl;
    cout << endl;

}

employee* employee::search_employee(char* id){
    if (!strcmp(this->id, id)){
        return this;
    }
    return NULL;
}

void init_emp(employee* emp){
    char name[MAXLEN], id[MAXLEN];
    float salary;
    cout << "Give name: " << endl;
    cin.getline(name, MAXLEN, '\n');
    cout << "Give id" << endl;
    cin.getline(id, MAXLEN, '\n');
    cout << "Give salary:" << endl;
    cin >> salary;
    cin.get(); 
    emp->set_values(name, id, salary);
}

int main(void){
    employee employeeList[MAXLEN];
    employee *emp;
    char menu;
    char id[MAXLEN];
    int employeeCount = 0;
    int i = 0;
    int removeNum = 0;

    while (menu != 'q'){
    cout << "Options:\nA) Add new employee information\nR) Remove employee's information \nS) Search based on id \nD) Print employees\nQ)exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a':
                init_emp(&employeeList[employeeCount]);
                employeeCount++;
                break;
            case 'b':
                cout << "BBB" << endl;
                break;
            case 's':
                cout << "Which id to find:" << endl;
                cin >> id;
                for (i = 0; i < employeeCount; i++){
                    emp = employeeList[i].search_employee(id);
                    if (emp != NULL){
                        // (*emp).print_values();
                        emp->print_values();
                    }
                }
                break;

            case 'r':
                cout << "Which employee information to delete(id):" << endl;
                cin >> id;
                for (i = 0; i < employeeCount; i++){
                    emp = employeeList[i].search_employee(id);
                    if (emp != NULL){
                        emp->set_values((char*)"",(char*)"", 0);
                        // employeeList[i] = NULL;
                        for (int ii = i; ii < employeeCount-1; ii++){
                            employeeList[ii] = employeeList[ii+1];
                        }
                        employeeCount--;
                        cout << "Employee deleted" << endl;
                    }
                }
                break;

            case 'd':
                if (employeeCount > 0){
                    for (int i = 0; i < employeeCount; i++){
                        employeeList[i].print_values();
                    }
                    cout << "There is " << employeeCount << " employees" << endl;
                }
                else{
                    cout << "No employees at the moment" << endl;
                }
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