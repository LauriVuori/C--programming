#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>
using namespace std;



void admin::get_user_name(user* _user){
    cout << _user->first_name << " " << _user->surname << " " 
    << _user->username << " " << _user->phonenumber << " " << endl;
}



admin::admin():person(),credentials(){
}

admin::admin(char* admin_username, char* admin_password):person(), credentials(admin_username, admin_password){
}

admin::admin(char* fname, char* sname, char* phnumber,char* admin_username, char* admin_password):person(fname, sname, phnumber), credentials(admin_username, admin_password){

}

// set_password() method, which receives as argument a User 
// object and a password and first calls authenticate() 
// method to authenticate the admin and then sets the password 
// of the given User object if authentication of admin succeeds 
// and otherwise returns a failure message.
void admin::set_user_password(user* _user, char* password){
    bool admin_authenticated = false;
    cout << "Authenticate to set password" << endl;
    admin_authenticated = authenticate();
    if (admin_authenticated == true){
        strcpy(_user->password, password);
    }
    else{
        cout << "Setting password failed" << endl;
    }
}

// set_usrname() method, which receives as argument a 
// User object and a username and first calls authenticate() 
// method to authenticate the admin and then sets the username 
// of the given User object if authentication of admin succeeds 
// and otherwise returns a failure message.
void admin:: set_usrname(user* _user, char* username){
    bool admin_authenticated = false;
    cout << "Authenticate to set username" << endl; 
    admin_authenticated = authenticate();
    if (admin_authenticated == true){
        strcpy(_user->username, username);
    }
    else{
        cout << "Setting username failed" << endl;
    }
}





// admin::~admin() {
// }

void admin::print_admin(){
    this->print_data();
    cout << username << " " << password << endl;
}



bool admin::authenticate(){
    char adm_username[MAXLEN], adm_password[MAXLEN];
    cout << "Give admin username" << endl;
    cin >> adm_username;
    // obscure_password(adm_password);
    // cout << "<<>>" << admin_password << "<<<>>>" << endl;
    cout << "Give admin password" << endl;
    cin >> adm_password;
    if ((!strcmp(this->username, adm_username)) && (!strcmp(this->password, adm_password))){
        cout << "Credentials correct" << endl;
        return true;
    }
    else{
        cout << "Credentials incorrect" << endl;
        return false;
    }
}


void admin::set_admin_usrname_password(char* adminName, char* adminPassword){
    strcpy(this->username, adminName);
    strcpy(this->password, adminPassword);
    cout << "Credentials changed" << endl;
}

void admin::set_permissions(user* _user, int confirmed_permissions[]){
    char perm[3][MAXLEN] = {"","",""};

    // for (int i = 0; i < PERMISSIONS; i++){
    //     strcpy(perm[i], "");
    // }


    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(perm[0], "read");

        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(perm[1], "execute");

        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(perm[2], "write");

        }
    }
    for (int i = 0; i < PERMISSIONS; i++){
        cout << perm[i] << endl;
    }
    _user->set_permissions(perm);
}



void admin::remove_permissions(user* _user, int confirmed_permissions[]){
    char perm[3][MAXLEN] = {"","",""};
    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(perm[0], "");

        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(perm[1], "");

        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(perm[2], "");

        }
    }
    for (int i = 0; i < PERMISSIONS; i++){
        cout << perm[i] << endl;
    }
    _user->remove_permissions(perm);
}