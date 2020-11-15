#include <curses.h>
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main(){
    char default_password[25]="admin";
    char pwd_input[25];
    initscr(); // enable ncurses
    printw("Enter password:");

    noecho();  // disable character echoing
    getnstr(pwd_input,sizeof(pwd_input));
    echo();

    if(!strcmp(default_password,pwd_input))
        printw("\nCorrect password!");
    else
        printw("\nIncorrect password. Try again");
    printw("\nPress any key to continue.");
    getch(); // Wait for a keypress
    endwin(); // disable ncurses
    cout << default_password << " " << pwd_input;

    return 0;
}