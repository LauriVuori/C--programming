#include "../include/class.h"
#include "../include/constants.h"
#include <iostream>
#include <cstring>

using namespace std;
char user::permissions[PERMISSIONS][MAXLEN];
char user::denied_list[MAX_DENY][MAXLEN];
int user::denied_list_counter;

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
    if(this->authenticate() == false){
        cout << "User denied" << endl;
        return NULL;
    }
    if(!strcmp(this->username, searchName)){
        cout << "User found" << endl;
        return this;
    }
    return NULL;
}


bool user::authenticate(){
    for (int i = 0; i < MAX_DENY; i++){
        if (strcmp(this->username, denied_list[i]) == 0){
            return false;
        }
    }
    return true;
}

void user::set_denied_list(char* denied_user){
    // muokkaa, dynaamisesti kasvattaa. static laskuri/indeksi-> nollan tilalle, poistaessa indeksiä vähennetää
    strcpy(user::denied_list[0], denied_user);
}

void user::set_permissions(int confirmed_permissions[]){

    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(user::permissions[0], "READ");

        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(user::permissions[1], "EXECUTE");
        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(user::permissions[2], "WRITE");

        }
    }
}
void user::remove_permissions(int confirmed_permissions[]){
    char perm[3][MAXLEN] = {"","",""};
    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(user::permissions[0], "");

        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(user::permissions[0], "");

        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(user::permissions[0], "");

        }
    }
}

void user::get_permissions(){

    cout << "Permissions:" << endl;
    for (int i = 0; i < PERMISSIONS; i++){
        cout << user::permissions[i] << endl;
    }
}
// user::~user(){
//     delete [] first_name;
//     delete [] surname;
//     delete [] phonenumber;
//     delete [] username;
//     delete [] password;
// }

void user::get_denied_list(){
    for(int i = 0; i < MAX_DENY; i++){
        cout << denied_list[i] << endl;
    }
}