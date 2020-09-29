/*A program in which you define a struct for customer information. The fields in the struct should be name, 
id and the amount of purchase. The program should read the information of a group of customers to an array 
and then display the information of the customers 
in descending order according to the purchase amounts. Use a function for reading the customer information 
and one for sorting the customers.*/

/*
1. group of customers to an array,
2. display info of customers
3. descending order purchase amounts
*/

#include <iostream>

#define ARSIZE 50

using namespace std;

struct customers{
    char name[ARSIZE];
    char customerId[ARSIZE];
    long double totalCost;
};

int allocateMem(customers *); 
void readCustomerData(customers *, int);
void printCustomerData(customers *, int);
void sortCustomers(customers *, int);

int main(void){
    int numberOfCustomers = 0;
    customers * customerData;

    numberOfCustomers = allocateMem(customerData);
    readCustomerData(customerData, numberOfCustomers);
    sortCustomers(customerData, numberOfCustomers);
    printCustomerData(customerData, numberOfCustomers);

    // delete [] customerData;
    // cout << customerData[1].totalCost << endl;
}

int allocateMem(customers * customerData){
    int numberOfCustomers = 0;
    cout << "How many customers there is: " << endl;
    cin >> numberOfCustomers;
    cin.get();
    try {
    customerData = new customers[numberOfCustomers];
    }
    catch (bad_alloc xa) {
       cout<<"Memory allocation Failed!";
    }
    return numberOfCustomers;
}

void readCustomerData(customers * customerData, int numberOfCustomers){
    cout << "\nGive customer information" << endl;
    for (int i = 0; i < numberOfCustomers; i++){
        cout << "Customer " << i+1 << ":" << endl;
        cout << "Give customer name: " << endl;
        cin.getline(customerData[i].name, ARSIZE, '\n');
        cout << "Give customer id: " << endl;
        cin.getline(customerData[i].customerId, ARSIZE, '\n');
        cout << "Give customers purchase total cost: " << endl;
        cin >> customerData[i].totalCost;
        cin.get();
    }
}

void printCustomerData(customers * customerData, int numberOfCustomers){
    cout << "Customers:" << endl;
    for (int i = 0; i < numberOfCustomers; i++){
        cout << "Customer " << i+1 << ":" << endl;
        cout << "Name: " << customerData[i].name << endl;
        cout << "Id: " << customerData[i].customerId << endl;
        cout << "Total cost: " << customerData[i].totalCost << "e" << endl;
    }
}

void sortCustomers(customers * customerData, int numberOfCustomers){
    customers * temp;
    int i, ii;
    try {
    temp = new customers[1];
    }
    catch (bad_alloc xa) {
       cout<<"Memory allocation Failed!";
    }

    for (i = 0; i < numberOfCustomers; i++){
        for (ii = i+1; ii < numberOfCustomers; ii++){
            if (customerData[i].totalCost < customerData[ii].totalCost){
                temp = &customerData[i];
                customerData[i] = customerData[ii];
                customerData[ii] = *temp;
            }
        }
    }
    delete [] temp;
    cout << "test" << endl;
}