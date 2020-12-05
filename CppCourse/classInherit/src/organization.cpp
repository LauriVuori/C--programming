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
    cout << org_name << " " << number_of_employees << " " << org_phonenumber;
}
organization::~organization(){
    delete [] org_name;
    delete [] org_phonenumber;
};
