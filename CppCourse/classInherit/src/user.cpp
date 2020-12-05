#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>
using namespace std;

user::user():person(),credentials(),organization(){
}

user::user(  
    char* fname, 
    char* sname,
    char* phnumber,
    char* usrname,
    char* password
    ):person(fname, sname, phnumber),credentials(usrname, password){
}

user::user(  
    char* fname, 
    char* sname, 
    char* phnumber):person(fname, sname, phnumber), credentials(){
}


user* user::find_user(char* find_user){
    return (user*)person::find_person(find_user);
}

bool user::compare(user* _user){
    if (!strcmp(this->phonenumber, _user->phonenumber)){
        cout << "Phone numbers is same" << endl;
        return true;
    }
    return false;
}
void user::get_info(){
    cout << "User information:" << endl;
    cout << this->first_name << "\n" << this->surname << "\n" 
    << this->username << "\n" << this->phonenumber << endl;
}

void user::get_all_info(){
    cout << "All info: " << endl;
    person::print_data();
}

void user::init_info(char* firstname, char* surname, char* phonenumber){
    strcpy(this->first_name, firstname);
    strcpy(this->surname, surname);
    strcpy(this->phonenumber, phonenumber);
}

void user::search(char* searchName){
    if(!strcmp(this->username, searchName)){
        cout << "User found" << endl;
        this->get_info();
    }
}

// destuctor
user::~user() {
}

void user::set_permissions(char confirmed_permissions[][MAXLEN]){
    for (int i = 0; i < PERMISSIONS; i++){
        strcpy(permissions[i], confirmed_permissions[i]);
    }
}

void user::print_permissions(){
    for (int i = 0; i < PERMISSIONS; i++){
        cout << permissions[i] << endl;
    }
}