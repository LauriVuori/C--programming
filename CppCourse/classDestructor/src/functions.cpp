#include <iostream>
#include "constants.h"
#include "./classes.h"
#include <cstring>
using namespace std;


user::user(  
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

user::user(){
    strcpy(this->firstname, "Firstname not known");
    strcpy(this->surname, "Surname not known");
    strcpy(this->username, "Username not known");
    strcpy(this->password, "Password not known");
    strcpy(this->phonenumber, "Phonenumber not known");
}

void user::get_info(){
    cout << this->firstname << " " << this->surname << " " 
    << this->username << " " << this->phonenumber << " " << endl;
}

void user::search(char* searchName){
    // if same values -> go into if
    if(!strcmp(this->firstname, searchName)){
        cout << "User found" << endl;
        this->get_info();
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

void admin::get_user_name(user* _user){
    cout << _user->firstname << " " << _user->surname << " " 
    << _user->username << " " << _user->phonenumber << " " << endl;
}



admin::admin(){
    strcpy(this->admin_name, "admin name not known");
    strcpy(this->admin_username, "admin username not known");
}

void admin::set_user_password(user* _user){
    strcpy(_user->password, "000");
}

admin::admin(char* admin_name, char* admin_username){
    strcpy(this->admin_name, admin_name);
    strcpy(this->admin_username, admin_username);
}
admin::~admin() {
    cout<<"Admin object destroyed "<<this->admin_name << endl;
    cout<<"Freeing memory and quitting..."<<endl;
 }