#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>
using namespace std;


organization::organization(){
    this->org_name = new char[MAXLEN];
    this->org_phonenumber = new char[MAXLEN];
    strcpy(this->org_name, "Organizations name not known");
    this->number_of_employees = 0;
    strcpy(this->org_phonenumber, "Organizations phonenumber not known");
}

organization::organization(char* org_name, int number_of_employees, char* org_phonenumber){
    this->org_name = new char[MAXLEN];
    this->org_phonenumber = new char[MAXLEN];
    strcpy(this->org_name, org_name);
    this->number_of_employees = number_of_employees;
    strcpy(this->org_phonenumber, org_phonenumber);
}

void organization::print_organization(){
    cout << "Organization name:" << org_name << endl;
    cout << "Number of employees: " << number_of_employees << endl;
    cout << "Organization phone number: " << org_phonenumber << endl;
    // cout << org_name << " " << number_of_employees << " " << org_phonenumber;
}

void organization::set_info(char* org_name, int numb_of_empl, char* org_phone){
    strcpy(this->org_name, org_name);
    number_of_employees = numb_of_empl;
    strcpy(this->org_phonenumber, org_phone);
}

organization* organization::search(char* findvalue){
    int temp = atoi(findvalue);

    if ((!strcmp(this->org_name, findvalue)) || (!strcmp(this->org_phonenumber, findvalue)) || ((this->number_of_employees == temp) && (this->number_of_employees != 0))){
        return this;
    }
    return NULL;
}
// organization::~organization(){
//     delete [] org_name;
//     delete [] org_phonenumber;
// };
