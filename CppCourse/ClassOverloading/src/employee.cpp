#include "employee.h"
#include "constants.h"
#include <iostream>
#include <cstring>
using namespace std;

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

employee* employee::search_employee(float salary){
    if (this->salary == salary){
        return this;
    }
    return NULL;
}
//
// string employee::to_string(){
//     string text ="";
//     text += name;
//     text += ", ";
//     text += id;
//     text += ", ";
//     text += job;
//     text += ", ";
//     text += std::to_string(salary);
//     return text;
// }
