#include <iostream>
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <cstring>

using namespace std;


person::person(){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];

    strcpy(this->first_name, "First name not known");
    strcpy(this->surname, "Surname not known");
    strcpy(this->phonenumber, "phonenumber name not known");
    strcpy(this->username, "username name not known");
    strcpy(this->password, "password name not known");

}

person::person(char* firstname, char* surname, char* phonenumber){
    this->first_name = new char[MAXLEN];
    this->surname = new char[MAXLEN];
    this->phonenumber = new char[MAXLEN];
    this->username = new char[MAXLEN];
    this->password = new char[MAXLEN];
    this->first_name = firstname;
    this->surname = surname;
    this->phonenumber = phonenumber;
    strcpy(this->username, "username name not known");
    strcpy(this->password, "password name not known");
}
void person::print_data(){
    cout << first_name << " " << surname << " " << phonenumber << " "
    << username << endl; 
}

person* person::find_person(char* find_person){
    
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
    delete [] username;
    delete [] password;
}


user* user::find_user(char* find_user){
    
    if (!strcmp(this->firstname, find_user)){
        return this;
    }
    if (!strcmp(this->surname, find_user)){
        return this;
    }
    if (!strcmp(this->username, find_user)){
        return this;
    }
    return NULL;
}


bool user::compare_phonenumber(char* phonenmber){
    if (!strcmp(this->phonenumber, phonenmber)){
        cout << "Phone numbers is same" << endl;
        return true;
    }
    return false;
}

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
    strcpy(this->username, "Username not known");
    strcpy(this->password, "Password not known");
}

user::user(){
    // strcpy(this->firstname, "Firstname not known");
    // strcpy(this->surname, "Surname not known");
    // strcpy(this->username, "Username not known");
    // strcpy(this->password, "Password not known");
    // strcpy(this->phonenumber, "Phonenumber not known");
}

void user::get_info(){
    cout << "User information:" << endl;
    cout << this->firstname << "\n" << this->surname << "\n" 
    << this->username << "\n" << this->phonenumber << endl;
}

void user::init_info(char* firstname, char* surname, char* phonenumber){
    strcpy(this->firstname, firstname);
    strcpy(this->surname, surname);
    strcpy(this->phonenumber, phonenumber);
}

void user::search(char* searchName){
    // if same values -> go into if
    if(!strcmp(this->username, searchName)){
        cout << "User found" << endl;
        this->get_info();
    }

}

// destuctor
// user::~user() {
//     cout<<"Destructor called for "<<this->username<< " " << this-> password << endl;
//     cout<<"Freeing memory and quitting..."<<endl;
//  }

void admin::get_user_name(user* _user){
    cout << _user->firstname << " " << _user->surname << " " 
    << _user->username << " " << _user->phonenumber << " " << endl;
}



admin::admin(){
    this->admin_password = new char[MAXLEN];
    strcpy(this->admin_username, "admin username not known");
    strcpy(this->admin_password, "admin password not known");
}

admin::admin(char* admin_username, char* admin_password){
    this->admin_password = new char[MAXLEN];
    strcpy(this->admin_username, admin_username);
    strcpy(this->admin_password, admin_password);
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

//set_usrname() method, which receives as argument a 
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
    delete [] admin_password;
    // cout<<"Admin object destroyed "<<this->admin_username << endl;
    // cout<<"Freeing memory and quitting..."<<endl;
}

void admin::print_admin(){
    cout << admin_username << " " << admin_password << endl;
}



bool admin::authenticate(){
    char adm_username[MAXLEN], adm_password[MAXLEN];
    cout << "Give admin username" << endl;
    cin >> adm_username;
    // obscure_password(adm_password);
    // cout << "<<>>" << admin_password << "<<<>>>" << endl;
    cout << "Give admin password" << endl;
    cin >> adm_password;
    if ((!strcmp(this->admin_username, adm_username)) && (!strcmp(this->admin_password, adm_password))){
        cout << "Credentials correct" << endl;
        return true;
    }
    else{
        cout << "Credentials incorrect" << endl;
        return false;
    }
}


void admin::set_admin_usrname_password(char* adminName, char* adminPassword){
    strcpy(this->admin_username, adminName);
    strcpy(this->admin_password, adminPassword);
    cout << "Credentials changed" << endl;
}

void admin::set_permissions(user* _user, int confirmed_permissions[]){
    char perm[3][50] = {"","",""};

    // for (int i = 0; i < PERMISSIONS; i++){
    //     strcpy(perm[i], "");
    // }

    int counter = 0;
    for (int i = 0; i < PERMISSIONS; i++){
        if((confirmed_permissions[0] == 1) && (i == 0)){
            strcpy(perm[counter], "read");
            counter++;
        }
        if((confirmed_permissions[1] == 1) && (i == 1)){
            strcpy(perm[counter], "execute");
            counter++;
        }
        if((confirmed_permissions[2] == 1) && (i == 2)){
            strcpy(perm[counter], "write");
            counter++;
        }
    }
    for (int i = 0; i < PERMISSIONS; i++){
        cout << perm[i] << endl;
    }
    _user->set_permissions(perm);
}

void user::set_permissions(char confirmed_permissions[][50]){
    for (int i = 0; i < PERMISSIONS; i++){
        strcpy(permissions[i], confirmed_permissions[i]);
    }
}

void user::print_permissions(){
    for (int i = 0; i < PERMISSIONS; i++){
        cout << permissions[i] << endl;
    }
}