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


#include <iostream>
#include <cstring>

#define MAXLEN 25
#define LOWERCASE 32

using namespace std;

class employee{
private:
    char name[MAXLEN];
    char id[MAXLEN];
    char job[MAXLEN];
    float salary;
public:
    void set_values(char* , char*, char*, float);
    void set_values(char* , char*, char*);
    void set_values();
    void print_values();
    void update();
    employee* search_employee(char*);
    // employee* search_employee(float);
};

//constructor with 4 values
void employee::set_values(char* name, char* id, char* job, float salary){
    strcpy(this->name, name);
    strcpy(this->id, id);
    strcpy(this->job, job);
    this->salary = salary;
}
//constructor with 3 values
void employee::set_values(char* name, char* id, char* job){
    strcpy(this->name, name);
    strcpy(this->id, id);
    strcpy(this->job, job);
    this->salary = 0;
}

//constructor with 0 values
void employee::set_values(){
    strcpy(this->name, "Name not known");
    strcpy(this->id, "Id not known");
    strcpy(this->job, "Job not known");
    this->salary = 0;
}

void employee::print_values(){

    cout << "Employee information:" << endl;
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Job: " << job << endl;
    cout << "Salary: " << salary << endl;
    cout << endl;
}

void employee::update(){
    cin.get();
    cout << "Give name: " << endl;
    cin.getline(name, MAXLEN, '\n');
    cout << "Give job: " << endl;
    cin.getline(job, MAXLEN, '\n');
    cout << "Give id" << endl;
    cin.getline(id, MAXLEN, '\n');
    cout << "Give salary:" << endl;
    cin >> salary;
    cin.get(); 
}

employee* employee::search_employee(char* searchValue){
    if (!strcmp(this->name, searchValue)){
        return this;
    }
    if (!strcmp(this->id, searchValue)){
        return this;
    }
    if (!strcmp(this->job, searchValue)){
        return this;
    }

    return NULL;
}
// employee* employee::search_employee(float salary){
//     if (salary == salary){
//         return this;
//     }
//     return NULL;
// }
void init_emp(employee* emp);

// employee::employee(){


// }

int main(void){
    employee employeeList[MAXLEN];
    employee *emp;
    char menu;
    char id[MAXLEN];
    int employeeCount = 0;
    int i = 0;
    int removeNum = 0;
    bool deleted = false, empFound = false;
    employeeList[0].set_values((char*)"Ville",(char*)"1",(char*)"Carpenter", 500);
    employeeList[1].set_values((char*)"Petteri",(char*)"emp2",(char*)"Architec", 1000);
    employeeList[2].set_values((char*)"Kalle",(char*)"emp3",(char*)"Police", 700);
    employeeList[3].set_values((char*)"Lauri",(char*)"emp4",(char*)"Student");
    employeeCount = 4;

    while (menu != 'q'){
    cout << "Options:\nA) Add new employee information\nB) Update employy information\nR) Remove employee's information \nS) Search based on id \nD) Print employees\nQ)exit\n" << endl;
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
                cout << "Give information to find(Name,id,job,salary):" << endl;
                cin >> id;
                empFound = false;
                for (i = 0; i < employeeCount; i++){
                    emp = employeeList[i].search_employee(id);
                    if (emp != NULL){
                        // (*emp).print_values();
                        employeeList[i].update();
                        empFound = true;
                    }
                }
                if (empFound == false){
                    cout << "No employee found" << endl;
                }
                break;
            case 's':
                cout << "Give information to find(Name,id,job,salary):" << endl;
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
                break;

            case 'r':
                cout << "Which employee information to delete(id):" << endl;
                cin >> id;
                deleted = false;
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
                        deleted = true;
                    }
                }
                if (deleted == false){
                    cout << "No employee deleted, wrong id" << endl;
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