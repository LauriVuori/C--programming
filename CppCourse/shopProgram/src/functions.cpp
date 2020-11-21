#include <iostream>
#include "constants.h"
#include "./classes.h"
#include <cstring>

using namespace std;

firm_info::firm_info(){
    this->shop_name = new char[MAXLEN];
    this->shop_phone_number = new char[MAXLEN];
    strcpy(this->shop_name, "Not known");
    strcpy(this->shop_phone_number, "Not known");
}

firm_info::firm_info(char* shop_name, char* shop_phone_number){
    this->shop_name = new char[MAXLEN];
    this->shop_phone_number = new char[MAXLEN];
    strcpy(this->shop_name, shop_name);
    strcpy(this->shop_phone_number, shop_phone_number);
}

void firm_info::print_firm_info(){
    cout << this->shop_name << " " << this->shop_phone_number << endl;
}

