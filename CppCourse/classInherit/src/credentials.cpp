#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>
using namespace std;


credentials::credentials(){
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    strcpy(this->username, "Username name not known");
    strcpy(this->password, "Password name not known");
}

credentials::credentials(char* username, char* password){
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    strcpy(this->username, username);
    strcpy(this->password, password);
}

void credentials::print_info(){
    cout << "Username:" << username << endl;
}

void credentials::set_credentials(char* username, char*password){
    strcpy(this->username, username);
    strcpy(this->password, password);

}
// credentials::~credentials(){

//     delete [] username;
//     delete [] password;
// }

// void credentials::print_data(){
//     // del pass
//     cout << username << " " << password << endl;
// }