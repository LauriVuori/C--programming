#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>
using namespace std;


person::person(){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    strcpy(this->first_name, "First name not known");
    strcpy(this->surname, "Surname not known");
    strcpy(this->phonenumber, "phonenumber name not known");
}

person::person(char* firstname, char* surname, char* phnenumber){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    strcpy(this->first_name, firstname);
    strcpy(this->surname, surname);
    strcpy(this->phonenumber, phnenumber);
}
void person::print_data(){
    cout << "Firstname: " << first_name << "\n" << "Surname: " << surname << "\nPhonenumber: " << phonenumber << endl;
}

person* person::find_person(char* find_person){
    //yhdistä ||
    if (!strcmp(this->first_name, find_person)){
        return this;
    }
    if (!strcmp(this->surname, find_person)){
        return this;
    }
    if (!strcmp(this->phonenumber, find_person)){
        return this;
    }
    return NULL;
}
person::~person(){
    delete [] first_name;
    delete [] surname;
    delete [] phonenumber;
}