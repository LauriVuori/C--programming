#include <./classes.h>
#include <./constants.h>
#include <iostream>

using namespace std;

int main(void){

    firm_info* test = new firm_info[2];
    firm_info::shop_name = "terve";
    test[0] = firm_info((char*)"1111");
    test[1] = firm_info((char*)"2222");
    test[0].print_firm_info();
    test[1].print_firm_info();
}