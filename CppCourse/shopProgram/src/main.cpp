#include "../include/shopconstants.h"
#include "../include/shopclasses.h"

#include <iostream>
#include <cstring>

using namespace std;

void update_shop_info(firm_info* firms);

int main(void){
    char menu;
    char id[MAXLEN];
    firm_info* firms = new firm_info[NUMBER_OF_FIRMS];
    basic_info* basic_infos = new basic_info[NUBMER_OF_BASICINFO];
    basic_info* temp = new basic_info;
    basic_infos[0] = basic_info((char*)"Opel", (char*)"123", (char*)"Autot");
    basic_infos[1] = basic_info((char*)"Lada", (char*)"678", (char*)"Autot");

    while (menu != 'q'){
        cout << "Options:\n A) Print firm info\n B) update firm info\n C) Print Basic_info\n D) Find basic info\n Q) Exit" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }
        switch (menu){
            case 'a': // print firm info
                for (int i = 0; i < NUMBER_OF_FIRMS; i++){
                    firms[i].get_shop_info();
                }
                break;
            case 'b': // update firm info
                update_shop_info(firms);
                break;
            case 'c':
                for (int i = 0; i < NUBMER_OF_BASICINFO; i++){
                    basic_infos[i].get_all_info();
                }
                break;
            case 'd':
                cout << "Give id: " << endl;
                cin>>id;
                for (int i = 0; i < NUBMER_OF_BASICINFO; i++){
                    temp = basic_infos[i].search_info(id);
                    if (temp != NULL){
                        temp->get_all_info();
                    }
                }
            case 'q':
                break;

        }
    }
}

void update_shop_info(firm_info* firms){
    char* firm_name = new char[MAXLEN];
    char* firm_phonenumber = new char[MAXLEN];
    char* firm_category = new char[MAXLEN];
    cout << "Give firm name" << endl;
    cin >> firm_name;
    cout << "Give firm phonenumber" << endl;
    cin >> firm_phonenumber;
    cout << "Give firm category" << endl;
    cin >> firm_category;
    firms->update_firm_info(firm_name, firm_phonenumber, firm_category);
}