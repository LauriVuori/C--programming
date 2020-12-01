#include "constants.h"
/*
A program for managing the information of IT users. For this purpose, define a class called User, 
which should have the following private attributes: 
first name, surname, phone number, username and password and 
static attribute permissions, 
which is an array of null-teminated string and specifies types of permissions 
for the users, like read, write and update. 

Define another static attribute called denied_list, which is an 
array of null-terminated string and holds the list of usernames, which are not not allowed to call search() method. 

This means that if we call search() method for any User object, inside search() method first it must be checked if the user is in the 
static denied_list or not and then either returns the user information or a message informing that access denied. Define also 
appropriate static methods for setting returning values of theses static attributes. Define necessaty constructors for 
the class. Define also the following methods for the class:
get_info() method, which returns as text all user information except for the password.
search() method, which receives the username as an argument and returns all the user information if the given username is the same as the user's username.  
set_permission(), which sets the set of permissions for users.
get_permissions(), which returns the list of user permissions.
check_permission(), which receives a permission and checks whether the user has been granted the specified permission or not.
*/


class user{
private:
    char* first_name;
    char* surname;
    char* phonenumber;
    char* username;
    char* password;
    static char permissions[PERMISSIONS];
    static char denied_list[MAX_DENY][MAXLEN];
public:
    user();
    user(char*, char*, char*);
    user(char*, char*, char*, char*, char*);
    void get_info();
    user* search(char*);
    void set_denied_list(char*);
    void set_permissions(int[]);
    void get_permissions();
    bool authenticate();
    // ~user();
};

// like read, write and execute.

