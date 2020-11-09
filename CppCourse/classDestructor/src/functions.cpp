#include <iostream>
#include "constants.h"
#include "./classes.h"
#include <cstring>
using namespace std;


void user::set_values(  
    char* fname, 
    char* sname, 
    char* usrname,
    char* password,
    char* phnumber){
    strcpy(this->firstname, fname);
    strcpy(this->surname, sname);
    strcpy(this->username, usrname);
    strcpy(this->password, password);
    strcpy(this->phonenumber, phnumber);

}

void user::set_values(){
    strcpy(this->firstname, "Firstname not known");
    strcpy(this->surname, "Surname not known");
    strcpy(this->username, "Username not known");
    strcpy(this->password, "Password not known");
    strcpy(this->phonenumber, "Phonenumber not known");
}

void user::get_info(){
    cout << firstname << " " << surname << " " 
    << username << " " << phonenumber << " " << endl;
}

void user::search(char* searchName){
    // if same values -> go into if
    if(!strcmp(this->firstname, searchName)){
        cout << "User found" << endl;
        get_info();
    }
    else{
        cout << "No user found " << endl;
    }
}

// destuctor
user::~user() {
    cout<<"Destructor called for "<<this->username<< " " << this-> password << endl;
    cout<<"Freeing memory and quitting..."<<endl;
 }