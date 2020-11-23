#include "shopconstants.h"
#include "shopclasses.h"

#include <iostream>
#include <cstring>

using namespace std;
#define NUMBER_OF_FIRMS 2


void update_shop_info(firm_info* firms);

int main(void){
    char menu;
    firm_info* firms = new firm_info[NUMBER_OF_FIRMS];
    char firm_name[50] = {"firmanimi"};
    // firms[0] = firm_info((char*)"1111");
    // firms[1] = firm_info((char*)"2222");

    // cout << "anna nimi" << endl;
    // cin >> firm_name;
    firms[0].get_shop_info();
    firms[1].get_shop_info();
    firms[0].update_firm_info(firm_name, (const char*)"moro",(char*)"terve");
    cout << "firmsi" << endl;
    firms[0].get_shop_info();
    firms[1].get_shop_info();

    while (menu != 'q'){
        cout << "Options:\n A) Print firm info\n B) update firm info\n Q) Exit" << endl;
        cout << "Give menu option" << endl;
        cin >> menu;
        cin.get();
        cout << endl;
        if ((menu >= 'A') && (menu <= 'Z')){
            menu += LOWERCASE;
        }

        switch (menu){
        case 'a':
            for (int i = 0; i < NUMBER_OF_FIRMS; i++){
                firms[i].get_shop_info();
            }
            break;
        case 'b':
            update_shop_info(firms);
        case 'q':
            break;

        }
    }
}

void update_shop_info(firm_info* firms){
    char* firm_name = new char[MAXLEN];

}