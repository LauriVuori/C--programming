#include <iostream>
#include "../include/shopconstants.h"
#include "../include/shopclasses.h"
#include <cstring>

using namespace std;
const char* firm_info::shop_name;
const char* firm_info::shop_phone_number;

//---------------------------------------------//
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

// Basic_info
//---------------------------------------------//
basic_info::basic_info(){
    basic_name = new char[MAXLEN];
    basic_id = new char[MAXLEN];
    basic_category = new char[MAXLEN];
    strcpy(this->basic_name, "Name not known");
    strcpy(this->basic_id, "Id not known");
    strcpy(this->basic_category, "Category not known");
}

basic_info::basic_info(char* name, char* id, char* category){
    this->basic_name = new char[MAXLEN];
    this->basic_id = new char[MAXLEN];
    this->basic_category = new char[MAXLEN];
    strcpy(this->basic_name, name);
    strcpy(this->basic_id, id);
    strcpy(this->basic_category, category);
}

void basic_info::get_all_info(){
    cout << basic_name << " " << basic_id << " " << basic_category << endl;
}

basic_info* basic_info::search_info(char* id){
    if(!strcmp(this->basic_id, id)){
        return this;
    }
    return NULL;
}
basic_info::~basic_info(){
    delete [] basic_category;
    delete [] basic_id;
    delete [] basic_name;
}
//---------------------------------------------//