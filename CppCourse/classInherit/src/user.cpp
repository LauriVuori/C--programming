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
    ):person(fname, sname, phnumber), credentials(usrname, password), organization(){
}

user::user(  
    char* fname, 
    char* sname, 
    char* phnumber):person(fname, sname, phnumber), organization(), credentials(){
}


user* user::find_user(char* find_user){
    return (user*)person::find_person(find_user);
}

user* user::find_organization(char* find_org){
    return (user*) organization::search(find_org);
}

bool user::compare(user* _user){
    if (!strcmp(this->phonenumber, _user->phonenumber)){
        // cout << "Phone numbers is same" << endl;
        return true;
    }
    return false;
}
void user::get_info(){
    cout << "All info: " << endl;
    this->print_data();
    this->print_info();
    this->print_organization();
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
// user::~user(){

// }

void user::set_permissions(char confirmed_permissions[][MAXLEN]){
    for (int i = 0; i < PERMISSIONS; i++){
        strcpy(permissions[i], confirmed_permissions[i]);
    }
}

void user::remove_permissions(char confirmed_permissions[][MAXLEN]){
    for (int i = 0; i < PERMISSIONS; i++){
        strcpy(permissions[i], confirmed_permissions[i]);
    }
}

void user::print_permissions(){
    for (int i = 0; i < PERMISSIONS; i++){
        cout << permissions[i] << endl;
    }
}