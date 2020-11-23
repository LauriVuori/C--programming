#include <iostream>
#include "shopconstants.h"
#include "shopclasses.h"
#include <cstring>

using namespace std;
const char* firm_info::shop_name;
const char* firm_info::shop_phone_number;


firm_info::firm_info(){
    this->shop_category = new char[MAXLEN];
    strcpy(this->shop_category, "Category not know");
    this->shop_name = "Shop name not known";
    this->shop_phone_number = "Shop phone number not known";
}

firm_info::firm_info(const char* shop_name, const char* shop_phone_number, char* category){
    this->shop_category = new char[MAXLEN];
    strcpy(this->shop_category, category);
    this->shop_name = shop_name;
    this->shop_phone_number = shop_phone_number;
}

void firm_info::get_shop_info(){
    cout << this->shop_name << " " << this->shop_phone_number << " " << this->shop_category <<  endl;
}

void firm_info::update_firm_info(const char* shop_name, const char* shop_phone_number, char* category){
    this->shop_name = shop_name;
    this->shop_phone_number = shop_phone_number;
    strcpy(this->shop_category, category);

}

firm_info::~firm_info(){
    delete [] shop_category;
}