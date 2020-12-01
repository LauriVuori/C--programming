#include "../include/class.h"
#include "../include/constants.h"
#include <iostream>
#include <cstring>

using namespace std;
char user::permissions[PERMISSIONS];
char user::denied_list[MAX_DENY][MAXLEN];

user::user(){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    strcpy(first_name, "Not known");
    strcpy(surname, "Not known");
    strcpy(phonenumber, "Not known");
    strcpy(username, "Not known");
    strcpy(password, "Not known");

}

user::user(char* first_name, char*surname, char* phonenumber){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    strcpy(this->first_name, first_name);
    strcpy(this->surname, surname);
    strcpy(this->phonenumber, phonenumber);
    strcpy(username, "Not known");
    strcpy(password, "Not known");

}
user::user(char* first_name, char*surname, char* phonenumber, char* username, char* password){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    strcpy(this->first_name, first_name);
    strcpy(this->surname, surname);
    strcpy(this->phonenumber, phonenumber);
    strcpy(this->username, username);
    strcpy(this->password, password);

}

void user::get_info(){
    cout << this->first_name << " " << this->surname << " " << this->phonenumber << " " << this->username 
    << endl;
}
user* user::search(char* searchName){
    // check denied list
    if(!strcmp(this->first_name, searchName)){
        cout << "User found" << endl;
        return this;
    }
    return NULL;
}

bool user::authenticate(){
    for (int i = 0; i < MAX_DENY; i++){
        if (strcmp(this->first_name, denied_list[i]) == 0){
            return true;
        }
    }
    return false;
}

void user::set_denied_list(char* denied_user){

    strcpy(this->denied_list[0], "Lauri");
}

void user::set_permissions(int confirmed_permissions[]){

    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(this->permissions[0], "R");
        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(this->permissions[1], "E");
        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(this->permissions[2], "W");

        }
    }
}
// user::~user(){
//     delete [] first_name;
//     delete [] surname;
//     delete [] phonenumber;
//     delete [] username;
//     delete [] password;
// }
