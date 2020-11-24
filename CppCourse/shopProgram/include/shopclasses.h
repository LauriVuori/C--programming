#include "shopconstants.h"


// Define class Firm_Info, whicn includes shop_name and shop_phone_number as static variables 
// and category as an instance variable. Define also necessary 
// constructors in addition to the following methods for this 
// class:

// get_shop_info(), which returns the shop information.
// update_shop_info(), which receives shop information and udates the current shop information. 
class firm_info{
private:
    char * shop_category;
    static const char* shop_name;
    static const char* shop_phone_number;
public:

    firm_info();
    firm_info(const char*, const char*, char*);
    void get_shop_info();
    void update_firm_info(const char*, const char*, char*);
    ~firm_info();
};

// Define class Basic_Info, whicn includes name, id and category as instance variables. Define also necessary constructors in addition to the following methods:
// get_all_info(), which returns full information of the object as text.
// search_info(), which receives the id of the object and returns full information of the object as text if the given id matches the object's id.

class basic_info{
private:
    char* basic_name;
    char* basic_id;
    char* basic_category;
public:
    basic_info();
    basic_info(char*, char*, char*);
    void init_basic_info(char*, char*, char*);
    void get_all_info();
    basic_info* search_info(char* );
    ~basic_info();
};

// Define class Product so that it inherits Firm_Info and Basic_Info classes in public mode. 
// The Product class should also include unit_price and amount  as attributes as well as 
// necessary constructors in addition to the following methods:
// get_unit_price(), which receives the name of the product and returns its unit price.
// update_amount(), which receives a value and updates the current amount by the given value.
class product : public firm_info, basic_info{
    int unit_price;
    int unit_amount;

public:
    void print();
};

// Define class Customer so that it also inherits Firm_Info and Basic_Info classes in public mode. 
// The customer class should include address and purchases as attributes. The purchases variable should be a matrix for keeping the name of the product and its value. 
// Class customer should also include necessary constructors as well as the following methods:
// update_purchase(), which receives the name of a  product and its value and adds it to the purchases of the customer.
// get_total_purchase(), which returns the total price of all purchases of the customer.
class customer{

};