#include <./classes.h>
#include <./constants.h>

#include <iostream>

using namespace std;

int main(void){
    firm_info* test = new firm_info[2];
    test[0] = firm_info((char*)"teve", (char*)"asd");
    test[0].print_firm_info();
}