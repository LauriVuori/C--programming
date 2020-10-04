/* memcpy example */
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
bool menu();
int main(void){

   while (menu() == true);
}
bool menu(){
   char menu;
   while (menu != 'e'){
      cout << "Options:\na) \nb) \nc) \nd)\ne)exit\n" << endl;
      cout << "Give menu option" << endl;
      cin >> menu;
      if ((menu >= 'A') && (menu <= 'Z')){
         menu += 32;
      }
      switch (menu){
         case 'a':
            cout << "AAA" << endl;
            break;
         case 'b':
            cout << "BBB" << endl;
            break;
         case 'e':
            cout << "Program shuts down" << endl;
            return false;
            break;
         default:
            cout << "Wrong input" << endl;
            break;
        }
    }
   return true;
}