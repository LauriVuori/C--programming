#include <iostream>
#include "constants.h"
#include "./classes.h"
#include <cstring>

using namespace std;

const char* firm_info::shop_name;

firm_info::firm_info(){
    this->shop_phone_number = new char[MAXLEN];
    strcpy(this->shop_phone_number, "Not known");
}

firm_info::firm_info(char* shop_phone_number){
    this->shop_phone_number = new char[MAXLEN];
    strcpy(this->shop_phone_number, shop_phone_number);
}

void firm_info::print_firm_info(){
    cout << this->shop_name << " " << this->shop_phone_number << endl;
}

void firm_info::set_name(const char* name) {
	this->shop_name = name;
}

