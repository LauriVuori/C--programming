/*
A program for managing the information of IT users. For this purpose, 
1define a class called User, which should have the following private attributes: 
first name, surname, phone number, username and password. 
Define necessaty constructors and destructor for the class. The destructor should display the username and password when it is called. Define also the following methods for the class:
-get_info() method, which returns as text all user information except for the password.
-search() method, which receives the username as an argument and returns all the user information if the given username is the same as the user's username. 

Define also class Admin as a friend class to class User. The attributes of class Admin should be username and password. Define necessary constructors and the destructor for this class too. 
The destructor should display a message saying that Admin object is being destroyed. Define also the following methods for the class:
set_usrname() method, which receives as argument a User object and a username and sets the username of the given object.
set_password() method, which receives as argument a User object and a password and sets the password of the given object.
In the main() function of the program create an array of User objects and an Admin object 
and pass User objects to the Admin object to initialize them. 
After this call get_info() and search() methods of User objects to test their functionality. 
Hint: To convert text to integere and decimal values you can use atoi(const char *_string) and atof(const char *_string) functions. 
Respectively, numbers can be converted to text using int sprintf (char * str, const char * format, double number) function, 
which returns the number of characters of the text after conversion.

Class user, attributes:
first name, surname, phone number, username password,
constructors, destructors.
!destructor should display the username and password when it is called.
-get_info() method, which returns as text all user information except for the password.
-search() method, which receives the username as an argument and returns all the user information if the given username is the same as the user's username.

class admin, friend class to user
attributes:
username and password
set_usrname() method, which receives as argument a User object and a username and sets the username of the given object.
set_password() method, which receives as argument a User object and a password and sets the password of the given object.


In the main() function of the program create an array of User objects and an Admin object and pass User objects to the Admin object to initialize them. 
After this call get_info() and search() methods of User objects to test their functionality. 
*/

#include <./classes.h>
#include <./constants.h>
#include <iostream>
#define NUMBER_OF_USERS 5
using namespace std;

int main(void){
    
    user* userArr = new user[NUMBER_OF_USERS];

    admin admin;

    for (int i = 0; i < NUMBER_OF_USERS; i++){
        // userArr[i].set_values();
        userArr[i].get_info();
    }

    // user usr((char*)"Lauri", (char*)"Vuori",(char*)"kebab", (char*)"NotAPassword123", (char*)"0400123123");
    // user *usr2 = new user((char*)"Lauri", (char*)"Vuori",(char*)"kebab", (char*)"NotAPassword123", (char*)"0400123123");
    // usr.get_info();
    // usr2->get_info();
    // testi.search((char*)"Lauri");

    return 0;
}
