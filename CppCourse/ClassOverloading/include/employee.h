#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "constants.h"

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
    // string to_string();
    employee* search_employee(char*);
    employee* search_employee(float);
    char* get_name(){
        return this->name;
    }
    char* get_id(){
        return this->id;
    }
    char* get_job(){
        return this->job;
    }
    float get_salary(){
        return this->salary;
    }
    // employee* search_employee(float);
};

#endif