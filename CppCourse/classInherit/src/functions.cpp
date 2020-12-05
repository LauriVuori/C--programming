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

credentials::~credentials(){
    delete [] username;
    delete [] password;
}

// void credentials::print_data(){
//     // del pass
//     cout << username << " " << password << endl;
// }
// organization::organization(){
//     this->org_name = new char[MAXLEN];
//     this->org_phonenumber = new char[MAXLEN];
//     strcpy(this->org_name, "Organizations name not known");
//     this->number_of_employees = 0;
//     strcpy(this->org_phonenumber, "Organizations phonenumber not known");
// }

// organization::organization(char* org_name, int number_of_employees, char* org_phonenumber){
//     this->org_name = new char[MAXLEN];
//     this->org_phonenumber = new char[MAXLEN];
//     strcpy(this->org_name, org_name);
//     this->number_of_employees = number_of_employees;
//     strcpy(this->org_phonenumber, org_phonenumber);
// }

// organization::~organization(){
//     delete [] org_name;
//     delete [] org_phonenumber;
// };

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
    cout << first_name << " " << surname << " " << phonenumber << endl;
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

user::user():person(),credentials(){
}

void user::get_info(){
    cout << "User information:" << endl;
    cout << this->first_name << "\n" << this->surname << "\n" 
    << this->username << "\n" << this->phonenumber << endl;
}

void user::get_all_info(){
    cout << "All info " << endl;
    cout << this->first_name << "\n" << this->surname << "\n" 
    << this->username << "\n" << this->phonenumber << "\n" << this->password <<  endl;
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





admin::~admin() {
}

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
    _user->set_permissions(perm);
}