
#include "constantsinh.h"
/*
class Person, which includes the following attributes: first name, surname, phone number, username and password as well as the following methods:
to_string() method, which returns as text all person's information except for the password.
search() method, which receives first name, surname or phone and returns the current object if any of these attributes matches object's data.
Define also the default constructor and a constructor, which can be used to initialize first name, surname and phone number attributes.
*/

class person{
protected:
    char* first_name;
    char* surname;
    char* phonenumber;

public:
    person();
    person(char*, char*, char*);
    void print_data();
    person* find_person(char*);
    ~person();
};


/*
class User, which inherits class Person in public mode and have permissions attribute as an array of null-terminated string. 
Define also necessary constructors and the following methods for the class:

set_permissions() as a private method, which receives a set of permissions (read, write, execution) as an array and initializes the permissions 
attribute with the given set of permissions.

remove_permissions() as a private method, which receives a permission and first checks if the user has already the specified permission and removes 
it if the user has it and returns a text message indicating the results of the operation. 

compare(), which receives an object of User, and compares the phone numbers of the current object with the phone number of the object passed as 
argument and returns the results as a Boolean value.
*/
class user:public person{
private:

  char username[MAXLEN];
  char password[MAXLEN];
    char permissions[3][MAXLEN];
private:
    void set_permissions(char [][MAXLEN]);
public:
    user();
    user(char*, char*, char*);
    user(char* , char*, char*, char*, char*);
    void init_info(char*, char*, char*);
    user* find_user(char* );
    void get_info();
    void search(char*);
    void print_permissions();
    bool compare(char *);
    // ~user();
    friend class admin;
};
/*
class Admin, which also inherits class Person in public mode and is a friend class to class User. Define necessary constructors as well as 
the following methods for the class:

authenticate(), which asks the admin username and password and then compares them with the existing admin username and password and returns
 true if they match and otherwise returns false if they do not match.

set_usrname() method, which receives as argument a User object and a username and first calls authenticate() method to authenticate the 
admin and then sets the username of the given User object if authentication of admin succeeds and otherwise returns a failure message.

set_password() method, which receives as argument a User object and a password and first calls authenticate() method to authenticate the 
admin and then sets the password of the given User object if authentication of admin succeeds and otherwise returns a failure message.

set_permissions() as a public method, which receives as argument a User object and a set of permissions as an array and 
first calls authenticate() method to authenticate the admin and then sets the permissions of the given User object if 
authentication of admin succeeds and otherwise returns a failure message.

remove_permissions() as a public method, which receives as argument a User object and a set of permissions as an array and first 
calls authenticate() method to authenticate the admin and then removes the 
specified permissions of the given User object if authentication of admin succeeds and otherwise returns a failure message.
*/
// adminille nimi yms..
class admin:public person{
    // char admin_password[MAXLEN];
    char* admin_password;
    char admin_username[MAXLEN];
public:
    admin();
    admin(char*, char*);
    void set_admin_usrname_password(char*, char*);
    void set_usrname(user* , char*);
    void set_user_password(user*, char*);
    void get_user_name(user*);
    void print_admin();
    bool authenticate();
    void set_permissions(user*, int[]);
    void remove_permissions(user*, int[]);
    ~admin();
};


