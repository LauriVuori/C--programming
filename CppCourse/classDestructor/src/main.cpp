/*
A program for managing the information of IT users. 
For this purpose, define a class called User, which should have the following private 
attributes: first name, surname, phone number, username and password. Define necessary 
constructors and destructor for the class. The destructor should display the username 
and password when it is called. Define also the following methods for the class:
get_info() method, which returns as text all user information except for the password.
search() method, which receives the username as an argument and returns all the user 
information if the given username is the same as the user's username. 

Define also class Admin as a friend class to class User. The attributes of class 
Admin should be username and password. Define necessary constructors and the 
destructor for this class too. The destructor should display a message saying 
that Admin object is being destroyed. Define also the following methods for the class:
authenticate(), which asks the admin username and password and then compares 
them with the existing admin username and password and returns true if they 
match and otherwise returns false if they do not match.
set_usrname() method, which receives as argument a User object and a username 
and first calls authenticate() method to authenticate the admin and then 
sets the username of the given User object if authentication of admin succeeds 
and otherwise returns a failure message.
set_password() method, which receives as argument a User object and a password 
and first calls authenticate() method to authenticate the admin and then sets the 
password of the given User object if authentication of admin succeeds and otherwise 
returns a failure message.
In the main() function of the program create an array of User objects and an Admin 
object and use the Admin object's set_username() and set_password() methods to set the user name and passwords of each user. After this call get_info() and search() methods of User objects to test their functionality. 
*/

#include <./classes.h>
#include <./constants.h>
#include <iostream>
#define NUMBER_OF_USERS 3
using namespace std;
void setAdminCredentials(admin * _admin);
int main(void){
    user* userArr = new user[NUMBER_OF_USERS];
    admin _admin = admin((char*)"admin", (char*)"admin");
    char usrname[MAXLEN], admin_usrname[MAXLEN], admin_password[MAXLEN], password[MAXLEN];
    char menu;
    bool admin_authenticated = false;
    admin_authenticated = _admin.authenticate();
    // setAdminCredentials(&_admin);
    
    userArr[0].init_info((char*)"Lauri", (char*)"Vuori", (char*)"0400123123");
    userArr[1].init_info((char*)"Petteri", (char*)"Kauris", (char*)"0501323");
    userArr[2].init_info((char*)"Kalle", (char*)"Puska", (char*)"06132411");
    //kysy admin username ja salasana-> jotta pääsee muokkaamaan
    // _admin.set_usrname(&userArr[0],(char*)"LaVu");
    // _admin.set_user_password(&userArr[0], (char*)"abcpassword1");

    // _admin.set_usrname(&userArr[1],(char*)"Peka");
    // _admin.set_user_password(&userArr[1], (char*)"123password2");

    // _admin.set_usrname(&userArr[2],(char*)"Kapu");
    // _admin.set_user_password(&userArr[2], (char*)"9393password3");


    userArr[0].get_info();
    userArr[1].get_info();
    userArr[2].get_info();


    while (menu != 'q'){
        cout << "Options:\nA) Find student\nB) Print users\nC) Set credentials to users \nQ) exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a':
                cout << "Give username to find: " << endl;
                cin >> usrname;
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    userArr[i].search((char*)usrname);
                }
                break;
            case 'b':
                for (int i = 0; i < NUMBER_OF_USERS; i++){
                    cout << "User " << i+1 << ":" << endl;
                    userArr[i].get_info();
                }
                break;
            case 'c':

                admin_authenticated = _admin.authenticate();
                if (admin_authenticated == true){
                    for (int i = 0; i < NUMBER_OF_USERS; i++){
                        userArr[i].get_info();
                        cout << "Give username" << endl;
                        cin >> usrname;
                        cout << "Give password" << endl;
                        cin >> password;
                        _admin.set_usrname(&userArr[i], usrname);
                        _admin.set_user_password(&userArr[i], password);
                        cout << "Credentials changed\n" << endl;
                    }
                }
                admin_authenticated = false;
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
    delete []userArr;
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