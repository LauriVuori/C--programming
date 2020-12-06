/*

Improve your program for managing the information of IT users in the previous problem so that you define and use the following classes in the program:
class Person, which includes the following attributes: first name, surname, phone number, username and password as well as the following methods:
to_string() method, which returns as text all person's information except for the password.
search() method, which receives first name, surname or phone and returns the current object if any of these attributes matches object's data.

Define also the default constructor and a constructor, which can be used to initialize first name, surname and phone number attributes. 
Define class User, which inherits class Person in public mode and have permissions attribute as an array of null-terminated string. 
Define also necessary constructors and the following methods for the class:
set_permissions() as a private method, which receives a set of permissions (read, write, execution) as an array and initializes the permissions attribute with the given set of permissions.
remove_permissions() as a private method, which receives a permission and first checks if the user has already the specified permission and removes it if the user has it and returns a text message indicating the results of the operation. 
compare(), which receives an object of User, and compares the phone numbers of the current object with the phone number of the object passed as argument and returns the results as a Boolean value.
class Admin, which also inherits class Person in public mode and is a friend class to class User. Define necessary constructors as well as the following methods for the class:
authenticate(), which asks the admin username and password and then compares them with the existing admin username and password and returns true if they match and otherwise returns false if they do not match.
set_usrname() method, which receives as argument a User object and a username and first calls authenticate() method to authenticate the admin and then sets the username of the given User object if authentication of admin succeeds and otherwise returns a failure message.
set_password() method, which receives as argument a User object and a password and first calls authenticate() method to authenticate the admin and then sets the password of the given User object if authentication of admin succeeds and otherwise returns a failure message.
set_permissions() as a public method, which receives as argument a User object and a set of permissions as an array and first calls authenticate() method to authenticate the admin and then sets the permissions of the given User object if authentication of admin succeeds and otherwise returns a failure message.
remove_permissions() as a public method, which receives as argument a User object and a set of permissions as an array and first calls authenticate() method to authenticate the admin and then removes the specified permissions of the given User object if authentication of admin succeeds and otherwise returns a failure message.

In the main() function of the program, create an array of User objects and an Admin object and use the Admin object's methods to manipulate user's information. Make sure that you use all methods of User and Admin classes to test their functionality.
*/
#include "../include/classesinh.h"
#include "../include/constantsinh.h"
#include <iostream>
#include <cstring>

#define NUMBER_OF_USERS 3
#define NUMBER_OF_PERSONS 3
using namespace std;

void setAdminCredentials(admin * _admin);
void set_permis(admin * _admin, user * _users);
void find_and_print(user* _users);

void init(user* _users){
    _users[0] = user((char*)"Lauri", (char*)"Vuori", (char*)"0400123123");
    _users[1] = user((char*)"Petteri", (char*)"Kauris", (char*)"0501323");
    _users[2] = user((char*)"Kalle", (char*)"Puska", (char*)"06132411");

    _users[0].set_info((char*)"mcdonalds", 25, (char*)"+358400303");

}



int main(void){
    user* _users = new user[NUMBER_OF_USERS];
    user* temp_user;
    admin _admin = admin((char*)"adminsNAME", (char*)"adminsSURNAME", (char*)"adminphonenm040", (char*)"admin", (char*)"admin");
    char usrname[MAXLEN], admin_usrname[MAXLEN], admin_password[MAXLEN], password[MAXLEN], find_person[MAXLEN], menu;
    bool admin_authenticated = false, correct_phone_number = false;
    setAdminCredentials(&_admin);
    init(_users);


    for (int i = 0; i < NUMBER_OF_USERS; i++){
        cout << "User " << i+1 << ":" << endl;
        _users[i].get_info();
    }

    // menu = 'q';
    while (menu != 'q'){
        cout << "Options:\n"
                           "A) Find users\n"
                           "B) Print users\n"
                           "C) Set credentials to users \n"
                           "E) Set permissions\n"
                           "F) Compare phonenumber\n"
                           "G) Print admins info\n"
                           "Q) exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a': // find user
                find_and_print(_users);
                break;
            case 'b': // print users
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    cout << "User " << i+1 << ":" << endl;
                    _users[i].get_info();
                }
                break;
            case 'c':
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    _users[i].get_info();
                    cout << "Give username to user:" << endl;
                    cin >> usrname;
                    cout << "Give password to user:" << endl;
                    cin >> password;
                    _admin.set_usrname(&_users[i], usrname);
                    _admin.set_user_password(&_users[i], password);
                    cout << "Credentials changed\n" << endl;
                }
                break;
            case 'e': //set permissions
                admin_authenticated = false;
                admin_authenticated = _admin.authenticate();
                if (admin_authenticated = true){
                    cout << "Find user(firstname, surname, username):" << endl;
                    cin >> find_person;
                    for (int i = 0; i < NUMBER_OF_USERS; i++){
                        temp_user = _users[i].find_user(find_person);
                        if (temp_user != NULL){
                            set_permis(&_admin, &_users[i]);
                            _users[i].get_info();
                            cout << "Permissions:" << endl;
                            _users[i].print_permissions();
                        }
                    }
                }
                break;
            case 'f':
                cout << "Give phonenumber" << endl;
                cin >> find_person;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    correct_phone_number = _users[i].compare(&_users[i]);
                    _users[i].get_info();
                }
                break;
            case 'g':
                _admin.print_admin();
                break;
            case 'q':
                break;
        }
    }


    // user usr((char*)"Lauri", (char*)"Vuori",(char*)"kebab", (char*)"NotAPassword123", (char*)"0400123123");
    // user *usr2 = new user((char*)"Lauri", (char*)"Vuori",(char*)"kebab", (char*)"NotAPassword123", (char*)"0400123123");
    // usr.get_info();
    // usr2->get_info();
    // testi.search((char*)"Lauri");
    delete [] _users;
    return 0;
}
void find_and_print(user* _users){
    char choice = 's';
    char temp_find[MAXLEN];
    user* temp_user;
    while (choice != 'q'){
        cout << "Options:\n"
                           "A) Find user using username\n"
                           "B) Find user using (firstname, surname, phonenumber)\n"
                           "C) Find user using (org. name, org. employ coutn, org. phonenumber)\n"
                           "Q) exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> choice;
        cin.get();
        cout << endl;
        if ((choice >= 'A') && (choice <= 'Z')){
            choice += LOWERCASE;
        }
        switch (choice){
            case 'a':
                cout << "Give username to find:" << endl;
                cin >> temp_find;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    _users[i].search((char*)temp_find);
                }
                break;
            case 'b':
                cout << "Give (firstname, surname, phonenumber) to find:" << endl;
                cin >> temp_find;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    temp_user = _users[i].find_user(temp_find);
                    if (temp_user != NULL){
                        temp_user->get_info();
                    }
                }
                break;
            case 'c':
                cout << "Give (org. name, org. employ coutn, org. phonenumber) to find:" << endl;
                cin >> temp_find;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    temp_user = _users[i].find_organization((char*)temp_find);
                    if (temp_user != NULL){
                        temp_user->get_info();
                    }
                }
            case 'q':
                break;
        }
    }
}

void setAdminCredentials(admin * _admin){
    char choice = 'e', admin_usrname[MAXLEN], admin_password[MAXLEN];
    bool admin_authenticated = false;
    while((choice != 'n') && (choice != 'y')){
    cout << "Do you want to change default admin username and password?(y/n)" << endl;
    cin >> choice;
    }
    if (choice == 'y'){
        admin_authenticated = _admin->authenticate();
        if (admin_authenticated == true){
            cout << "Give admin new username:" << endl;
            cin >> admin_usrname;
            cout << "Give admin new password:" << endl;
            cin >> admin_password;
            _admin->set_admin_usrname_password(admin_usrname, admin_password);
        }
    }
    else{
        cout << "Admin uses default credentials" << endl;
    }
}

void set_permis(admin * _admin, user * _users){
    char choice = 'i';
    int confirmed[PERMISSIONS] = {0,0,0};
    int i = 0;
    char* confirmed_char[PERMISSIONS] = {(char*)"[x]eXecute",(char*)"[x]Read",(char*)"[x]Write"};
    char* denied_char[PERMISSIONS] = {(char*)"[]eXecute",(char*)"[]Read",(char*)"[]Write"};

    while (choice != 'q'){
        i = 0;
        for(int counter=0; counter<PERMISSIONS; counter++ ){
            if(confirmed[counter]){
                cout<< confirmed_char[counter];
            }
            else{
                cout<<denied_char[counter];
            }
        cout<<endl;
        }
        cout << "Which permissions to: \n add 1) read 2) execute 3) write\n e) set permissions\n f) remove users permissions \nr) reset selected permissions\n  q)exit:" << endl;
        cin >> choice;
        switch (choice){
            case '1':
                confirmed[0] = 1;
                break;
            case '2':
                confirmed[1] = 1;
                break;
            case '3':
                confirmed[2] = 1;
                break;
            case 'e':
                _admin->set_permissions(_users, confirmed);
                choice = 'q';
                break;
            case 'f':
                _admin->remove_permissions(_users, confirmed);
                choice = 'q';
            case 'r':
                for (int i = 0; i < PERMISSIONS; i++){
                    confirmed[i] = 0;
                }
                cout << "Permissions resetted" << endl;
                break;
            case 'q':
                break;
        }
    }
}
