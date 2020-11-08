/*
Write a C++ program in which you define class employee and necessary functions 
for reading employees' information and saving them to an array of class employee. 
The member variables of the class should be: name, id, job, and salary. 

Define constructors with different set of parameters as well as the default constructor for the class. 

Define also search(), update() 
and to_string() methods for the class. The search() should receive a value for name or id or job or salary and 
returns a pointer to the object if the given search criteria matches the information of the current employee. 

The update() method should be used to update the id, name, job and salary of the employee. The to_string() method 
should return all object data as text. Declare all variables as private and use only methods for manipulating them. 
The program must print to the standard output a menu, from which user can choose the following actions:

A: add new employee information
R: remove employee's information
S: search based on employee's ID
Q: quit

The program must print to the standard output and update a counter which shows the number of 
employees whose information are saved in the database. The program must keep on showing 
the menu and letting the user to make a choice as long as Q is not pressed.*/



#include "employee.h"
#include "constants.h"
#include <iostream>
#include <cstring>
using namespace std;


void init_emp(employee* emp);

// void find_employee(employee emp[], int employeeCount, char* menuOption);
void print_employee_string(employee emp){
    cout << emp.get_name() << " " << emp.get_id() << " " << emp.get_job() << " " << emp.get_salary() << endl;
}

int main(void){
    employee employeeList[MAXLEN];
    employee *emp;
    string text = "";
    char menu;
    char id[MAXLEN];
    float salary = 0;
    int employeeCount = 0, salaryOrText;
    int i = 0;
    int removeNum = 0;
    bool deleted = false, empFound = false;
    employeeList[0].set_values((char*)"Ville",(char*)"1",(char*)"Carpenter", 500);
    employeeList[1].set_values((char*)"Petteri",(char*)"emp2",(char*)"Architec", 1000);
    employeeList[2].set_values((char*)"Kalle",(char*)"emp3",(char*)"Police", 700);
    employeeList[3].set_values((char*)"Lauri",(char*)"emp4",(char*)"Student");
    employeeCount = 4;
    // find_employee(employeeList, employeeCount, (char*)"a");
    // cout << "uus" << endl;
    // find_employee(employeeList, employeeCount, (char*)"a");
    while (menu != 'q'){
    cout << "Options:\nA) Add new employee information\nB) Update employy information\nT) Object data to text\nR) Remove employee's information \nS) Search based on id \nD) Print employees\nQ)exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            //add new
            case 'a':
                init_emp(&employeeList[employeeCount]);
                employeeCount++;
                break;
            //update information
            case 'b':
                cout << "Find employee:\n1)Name,id,job\n2)salary\nGive 1 or 2:"<< endl;
                cin >> salaryOrText;
                cin.get();
                if (salaryOrText == 1){
                    cout << "Give information to find(Name,id,job):" << endl;
                    cin >> id;
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(id);
                        if (emp != NULL){
                            // (*emp).print_values();
                            cout << "Employee to update:" << endl;
                            employeeList[i].print_values();
                            employeeList[i].update();
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                else{
                    cout << "Give salary:" << endl;
                    cin >> salary;
                    cin.get();
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(salary);
                        if (emp != NULL){
                            // (*emp).print_values();
                            cout << "Employee to update:" << endl;
                            employeeList[i].print_values();
                            employeeList[i].update();
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                break;
            //object data to text
            case 't':
                cout << "Find employee:\n1)Name,id,job\n2)salary\nGive 1 or 2:"<< endl;
                cin >> salaryOrText;
                cin.get();
                if (salaryOrText == 1){
                    cout << "Give information to find(Name,id,job):" << endl;
                    cin >> id;
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(id);
                        if (emp != NULL){
                            // (*emp).print_values();
                            print_employee_string(employeeList[i]);
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                else{
                    cout << "Give salary" << endl;
                    cin >> salary;
                    cin.get();
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(salary);
                        if (emp != NULL){
                            // (*emp).print_values();
                            print_employee_string(employeeList[i]);
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                break;
            //find employee
            case 's':
                cout << "Find employee:\n1)Name,id,job\n2)salary\nGive 1 or 2:"<< endl;
                cin >> salaryOrText;
                cin.get();
                if (salaryOrText == 1){
                    cout << "Give information to find(Name,id,job):" << endl;
                    cin >> id;
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(id);
                        if (emp != NULL){
                            // (*emp).print_values();
                            emp->print_values();
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                else{
                    cout << "Give salary:" << endl;
                    cin >> salary;
                    cin.get();
                    empFound = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(salary);
                        if (emp != NULL){
                            // (*emp).print_values();
                            emp->print_values();
                            empFound = true;
                        }
                }
                    if (empFound == false){
                        cout << "No employee found" << endl;
                    }
                }
                break;
            //remove
            case 'r':
                cout << "Find employee:\n1)Name,id,job\n2)salary\nGive 1 or 2:"<< endl;
                cin >> salaryOrText;
                cin.get();
                if (salaryOrText == 1){
                    cout << "Give information to find(Name,id,job):" << endl;
                    cin >> id;
                    
                    deleted = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(id);
                        if (emp != NULL){                        
                            emp->set_values();
                            print_employee_string(*emp);
                            // cout << "test" << endl;
                            // employeeList[i] = NULL;
                            for (int ii = i; ii < employeeCount-1; ii++){
                                employeeList[ii] = employeeList[ii+1];
                            }
                            employeeCount--;
                            cout << "Employee deleted" << endl;
                            deleted = true;
                        }
                    }
                    if (deleted == false){
                        cout << "No employee found" << endl;
                    }
                }
                else{
                    cout << "Give salary:" << endl;
                    cin >> salary;
                    cin.get();
                    deleted = false;
                    for (i = 0; i < employeeCount; i++){
                        emp = employeeList[i].search_employee(salary);
                        if (emp != NULL){
                            emp->set_values((char*)"",(char*)"", 0);
                            // employeeList[i] = NULL;
                            for (int ii = i; ii < employeeCount-1; ii++){
                                employeeList[ii] = employeeList[ii+1];
                            }
                            employeeCount--;
                            cout << "Employee deleted" << endl;
                            deleted = true;
                        }
                }
                    if (deleted == false){
                        cout << "No employee found" << endl;
                    }
                }
                break;
            //print
            case 'd':
                if (employeeCount > 0){
                    for (int i = 0; i < employeeCount; i++){
                        // print_employee_string(employeeList[i]);
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

void init_emp(employee* emp){
    char name[MAXLEN], id[MAXLEN],job[MAXLEN];
    float salary;
    cout << "Give name: " << endl;
    cin.getline(name, MAXLEN, '\n');
    cout << "Give job: " << endl;
    cin.getline(job, MAXLEN, '\n');
    cout << "Give id" << endl;
    cin.getline(id, MAXLEN, '\n');
    cout << "Give salary:" << endl;
    cin >> salary;
    cin.get(); 
    emp->set_values(name, id, job, salary);
}

// void find_employee(employee emp[], int employeeCount, char* menuOption){
//     int salaryOrText = 0;
//     bool empFound = false;
//     cout << "Find employee:\n1)Name,id,job\n2)salary\nGive 1 or 2:"<< endl;
//     cin >> salaryOrText;
//     cin.get();
//     if (salaryOrText == 1){
//         cout << "Give information to find(Name,id,job):" << endl;
//         cin >> id;
//         empFound = false;
//         for (i = 0; i < employeeCount; i++){
//             emp = employeeList[i].search_employee(id);
//             if (emp != NULL){
//                 // (*emp).print_values();
//                 cout << "Employee to update:" << endl;
//                 employeeList[i].print_values();
//                 employeeList[i].update();
//                 empFound = true;
//             }
//     }
//         if (empFound == false){
//             cout << "No employee found" << endl;
//         }
//     }
//     else{
//         cout << "Give information to find(Name,id,job):" << endl;
//         cin >> salary;
//         cin.get();
//         empFound = false;
//         for (i = 0; i < employeeCount; i++){
//             emp = employeeList[i].search_employee(salary);
//             if (emp != NULL){
//                 // (*emp).print_values();
//                 cout << "Employee to update:" << endl;
//                 employeeList[i].print_values();
//                 employeeList[i].update();
//                 empFound = true;
//             }
//     }
//         if (empFound == false){
//             cout << "No employee found" << endl;
//         }
//     }
// }