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

void init_users(user* _users){
    _users[0].init_info((char*)"Lauri", (char*)"Vuori", (char*)"0400123123");
    _users[1].init_info((char*)"Petteri", (char*)"Kauris", (char*)"0501323");
    _users[2].init_info((char*)"Kalle", (char*)"Puska", (char*)"06132411");
}

void init_person(person* _persons){
    _persons[0] = person((char*)"Juho", (char*)"Maki", (char*)"05000");
    _persons[1] = person((char*)"Kaisa", (char*)"Kuopio", (char*)"06000");
    _persons[2] = person((char*)"Martti", (char*)"Koivu", (char*)"07000");
}

int main(void){
    user* _users = new user[NUMBER_OF_USERS];
    person* _persons = new person[NUMBER_OF_PERSONS];
    person* temp_person;
    user* temp_user;
    admin _admin = admin((char*)"admin", (char*)"admin");
    char usrname[MAXLEN], admin_usrname[MAXLEN], admin_password[MAXLEN], password[MAXLEN], find_person[MAXLEN], menu;
    bool admin_authenticated = false, correct_phone_number = false;

    setAdminCredentials(&_admin);
     printf("test");
    init_users(_users);
    printf("test");
    // init_person(_persons);

    // _persons[0].print_data();
    // _persons[1].print_data();
    // _persons[2].print_data();

    // _admin.set_permissions(&_users[0], (char*)"read");

    while (menu != 'q'){
        cout << "Options:\nA) Find student\nB) Print users\nC) Set credentials to users \n D) Find Person\n E) Set permissions\n F) Compare phonenumber\n G) Print persons \nQ) exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a': // find user
                cout << "Give username to find: " << endl;
                cin >> usrname;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    _users[i].search((char*)usrname);
                }
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
            case 'd': // find persons
                cout << "Find person(firstname, surname, phonenumber):" << endl;
                cin >> find_person;

                for (int i = 0; i < NUMBER_OF_PERSONS; i++){
                    temp_person = _persons[i].find_person(find_person);
                    if (temp_person != NULL){
                        temp_person->print_data();
                    }
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
                for (int i = 0; i < NUMBER_OF_PERSONS; i++){
                    _persons[i].print_data();
                }
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
    delete [] _persons;
    return 0;
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


    while (choice != 'q'){
        i = 0;
        while (i < PERMISSIONS){
            if (confirmed[i] != 0){
                if ((confirmed[0] == 1) && (confirmed[1] == 0) && (confirmed[2] == 0)){
                    cout << "[x]read[]execute[]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 1) && (confirmed[1] == 1) && (confirmed[2] == 0)){
                    cout << "[x]read[x]execute[]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 1) && (confirmed[1] == 1) && (confirmed[2] == 1)){
                    cout << "[x]read[x]execute[x]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 0) && (confirmed[1] == 1) && (confirmed[2] == 1)){
                    cout << "[]read[x]execute[x]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 0) && (confirmed[1] == 0) && (confirmed[2] == 1)){
                    cout << "[]read[]execute[x]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 0) && (confirmed[1] == 1) && (confirmed[2] == 0)){
                    cout << "[]read[x]execute[]write" << endl;
                    i = 15;
                }
                else if ((confirmed[0] == 1) && (confirmed[1] == 0) && (confirmed[2] == 1)){
                    cout << "[x]read[]execute[x]write" << endl;
                    i = 15;
                }
            }
            i++;
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
