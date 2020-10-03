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

/*
allocate mem(customers **){
    *data = new customers[x];
}
??
or 
allocate mem(customers *&){
    data = new customers[x];
}
*/

#include <iostream>
#include <cstring>




#define ARSIZE 50

using namespace std;

struct customers{
    char name[ARSIZE];
    char customerId[ARSIZE];
    int totalCost;
};

int allocateMem(customers *&); 
void readCustomerData(customers *, int);
void printCustomerData(customers *, int);
void sortCustomers(customers *, int);

int main(void){
    int numberOfCustomers = 0;
    customers * customerData;

    numberOfCustomers = allocateMem(customerData);
    // numberOfCustomers = 3;
    // customerData = new customers[3];
    readCustomerData(customerData, numberOfCustomers);
    sortCustomers(customerData, numberOfCustomers);
    printCustomerData(customerData, numberOfCustomers);

    // delete [] customerData;
    // cout << customerData[1].totalCost << endl;
}

int allocateMem(customers *& customerData){
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
    // cout << "\nGive customer information" << endl;
    // for (int i = 0; i < numberOfCustomers; i++){
    //     cout << "Customer " << i+1 << ":" << endl;
    //     cout << "Give customer name: " << endl;
    //     cin.getline(customerData[i].name, ARSIZE, '\n');
    //     cout << "Give customer id: " << endl;
    //     cin.getline(customerData[i].customerId, ARSIZE, '\n');
    //     cout << "Give customers purchase total cost: " << endl;
    //     cin >> customerData[i].totalCost;
    //     cin.get();
    // }

    strcpy(customerData[0].name, "petteri");
    strcpy(customerData[1].name, "Ville");
    strcpy(customerData[2].name, "lauri");
    strcpy(customerData[0].customerId, "1");
    strcpy(customerData[1].customerId, "2");
    strcpy(customerData[2].customerId, "3");
    customerData[0].totalCost = 10;
    customerData[1].totalCost = 13;
    customerData[2].totalCost = 15;

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
    customers *temp;
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
                // cout << "ii:" << ii << endl;
                temp[0] = customerData[i];
                
                // cout << "test1" << endl;
                customerData[i] = customerData[ii];
                // cout << "test2" << endl;
                customerData[ii] = temp[0];
                // cout << "test3" << endl;
                
            }
        } 
    }
    delete [] temp;
}