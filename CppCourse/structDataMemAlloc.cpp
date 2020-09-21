// A program in which you define two data structures: room and customer. 
// The fields for room should be: room_id, type (single, double, ...) and 
// price per night. The fields for customer should be: name, room_id and number_of_nights. 
// The program must ask the number of rooms and customers from the user, allocate memory for 
// them and read data for them. After 
// reading the data, the program must print a list which shows which room (room_id) 
// is occupied by which customer and displays the customer information.

#include <iostream>
#include <new>
#include <cstring>
using namespace std;


#define ARSIZE 30

struct room {
    int room_id;
    char type[ARSIZE];
    int price;
};

struct customer {
    char name[ARSIZE];
    char room_id[ARSIZE];
    int number_of_nights;

};

int main(void) {
    room * roomData;
    customer * customerData;
    int roomNumber, customerNumber, i;
    char temp[30];
    try {
    roomData = new room[5];
    
	}catch (bad_alloc xa) {
     cout<<"Memory allocation Failed!";
     return 1;
    }

    try {

    customerData = new customer[3];
    
	}catch (bad_alloc xa) {
     cout<<"Memory allocation Failed!";
     return 1;
    }
    // cout << "Give number:" << endl;
    // cin >> roomNumber;
    // cout << roomNumber;
    // for (i = 0; i <= roomNumber; i++){
    //     // cout << "Give room type(single,double,triple):" << endl;
    //     // cin.getline(temp, 30, '\n');
    //     roomData->room_id = i;
    //     roomData++;
    // }
    // while (i > 0){
    //     roomData--;
    //     i--;
    // }
    roomData->room_id = 1;
    roomData++;
    roomData->room_id = 2;
    roomData++;
    roomData->room_id = 3;
    roomData++;
    roomData->room_id = 4;
    roomData++;
    roomData->room_id = 5;
    roomData -= 4;
    for (i = 0; i < 5; i++){
        cout << roomData -> room_id << endl;
        roomData++;
    }
    
}