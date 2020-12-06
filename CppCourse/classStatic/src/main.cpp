#include "../include/class.h"

#include <iostream>
#include <cstring>
using namespace std;
void permissions();
// void set_perm(user* _users);

void find_user(user* _users){
    user* temp_user = new user;
    char find_person[MAXLEN];
    bool authenticate = false;
    int i = 0;
    cout << "Which user use to find user:" << endl;
    cin >> find_person;
    cout << find_person << endl;
    for (i = 0; i < NUMBER_USERS; i++){
            temp_user = _users[i].search(find_person);
            if (temp_user != NULL){
                temp_user->get_infos();
            
                // cout << "Which user to find:" << endl;
                // cin >> find_person;
                // cout << find_person << endl;
                // // temp_user = NULL;
                // for (int b = 0; b < NUMBER_USERS; b++){
                //     temp_user = _users[b].search(find_person);
                //     if (temp_user != NULL){
                //         _users[b].get_info();
                //     }
                // }
                // }
                // else{
                //     cout << "User denied" << endl;
                // }
            }
    }
    delete temp_user;
}

int main(void){
    char menu;
    user* _users = new user[NUMBER_USERS];
    _users[0] = user((char*)"Lauri", (char*)"Vuori", (char*)"0400123123", (char*)"lavu", (char*)"LAVU");
    _users[1] = user((char*)"Petteri", (char*)"Kauris", (char*)"0501323",(char*)"peka",(char*)"PEKA");
    _users[2] = user((char*)"Kalle", (char*)"Puska", (char*)"06132411",(char*)"kapu",(char*)"KAPU");
    user::set_denied_list((char*)"lavu");
    user::get_denied_list_counter();
    for (int i = 0; i < NUMBER_USERS; i++){
        _users[i].get_infos();
    }

    while (menu != 'q'){
    cout << "Options:\nA) Print users information \nB)Find user\nC)Set permissions\nQ)exit\n" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a': //print
                for (int i = 0; i < NUMBER_USERS; i++){
                    _users[i].get_infos();
                }
                user::get_permissions();
                user::get_denied_list();
                break;
            case 'b': // search
                find_user(_users);
                break;
            case 'c':
                // set_perm(_users);
                permissions();
                break;
            case 'q':
                cout << "Program shuts down" << endl;
                break;
        }
    }
}

// void set_perm(user* _users){
//     char permission[PERMISSIONS] = "";
//     user* temp_user = new user;
//     char find_person[MAXLEN];

//     cout << "Which user to find:" << endl;
//     cin >> find_person;
//     for (int i = 0; i < NUMBER_USERS; i++){
//         temp_user = _users[i].search(find_person);
//         if (temp_user != NULL){
//             permissions(&_users[i]);
//         }
//     }
// }

void permissions(){
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
         
        // while (i < PERMISSIONS){
        //     if (confirmed[i] != 0){
        //         if ((confirmed[0] == 1) && (confirmed[1] == 0) && (confirmed[2] == 0)){
        //             cout << "[x]read[]execute[]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 1) && (confirmed[1] == 1) && (confirmed[2] == 0)){
        //             cout << "[x]read[x]execute[]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 1) && (confirmed[1] == 1) && (confirmed[2] == 1)){
        //             cout << "[x]read[x]execute[x]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 0) && (confirmed[1] == 1) && (confirmed[2] == 1)){
        //             cout << "[]read[x]execute[x]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 0) && (confirmed[1] == 0) && (confirmed[2] == 1)){
        //             cout << "[]read[]execute[x]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 0) && (confirmed[1] == 1) && (confirmed[2] == 0)){
        //             cout << "[]read[x]execute[]write" << endl;
        //             i = 15;
        //         }
        //         else if ((confirmed[0] == 1) && (confirmed[1] == 0) && (confirmed[2] == 1)){
        //             cout << "[x]read[]execute[x]write" << endl;
        //             i = 15;
        //         }
        //     }
        //     i++;
        // }
        cout << "Which permissions to: \n add 1) read 2) execute 3) write\n\n e) set permissions\nr) reset selected permissions\n f)Remove permissions q)exit:" << endl;
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
                user::set_permissions(confirmed);
                // _users->get_info();
                user::get_permissions();
                choice = 'q';
                break;
            case 'r':
                for (int i = 0; i < PERMISSIONS; i++){
                    confirmed[i] = 0;
                }
                cout << "Permissions resetted" << endl;
                break;
            case 'f':
                user::remove_permissions(confirmed);
                // _users->get_info();
                user::get_permissions();
            case 'q':
                break;
        }
    }
}
