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

user::user(  
    char* fname, 
    char* sname, 
    char* phnumber){
    strcpy(this->firstname, fname);
    strcpy(this->surname, sname);
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
    cout << this->firstname << "\n" << this->surname << "\n" 
    << this->username << "\n" << this->phonenumber << endl;
}

void user::search(char* searchName){
    // if same values -> go into if
    if(!strcmp(this->username, searchName)){
        cout << "User found" << endl;
        this->get_info();
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
    strcpy(this->admin_username, "admin username not known");
    strcpy(this->admin_password, "admin password not known");
}

admin::admin(char* admin_username, char* admin_password){
    strcpy(this->admin_username, admin_username);
    strcpy(this->admin_password, admin_password);
}

// set_password() method, which receives as argument a User 
// object and a password and first calls authenticate() 
// method to authenticate the admin and then sets the password 
// of the given User object if authentication of admin succeeds 
// and otherwise returns a failure message.
void admin::set_user_password(user* _user, char* password){
    strcpy(_user->password, password);
}

//set_usrname() method, which receives as argument a 
// User object and a username and first calls authenticate() 
// method to authenticate the admin and then sets the username 
// of the given User object if authentication of admin succeeds 
// and otherwise returns a failure message.
void admin:: set_usrname(user* _user, char* username){
    strcpy(_user->username, username);
}





admin::~admin() {
    cout<<"Admin object destroyed "<<this->admin_username << endl;
    cout<<"Freeing memory and quitting..."<<endl;
 }

void admin::print_admin(){
    cout << admin_username << " " << admin_password << endl;
}

bool admin::authenticate(char* admin_username, char* admin_password){
    if ((!strcmp(this->admin_username, admin_username)) && (!strcmp(this->admin_password, admin_password))){
        return true;
    }
    else{
        return false;
    }
}