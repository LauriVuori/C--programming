// A program in which you define two data structures: room and customer. 
// The fields for room should be: room_id, type (single, double, ...) and 
// price per night. The fields for customer should be: name, room_id and number_of_nights. 
// The program must ask the number of rooms and customers from the user, allocate memory for 
// them and read data for them. After 
// reading the data, the program must print a list which shows which room (room_id) 
// is occupied by which customer and displays the customer information.
// huoneiden tiedot, asiakkaan tiedot, huoneen id, ohjelma tulostaa vaihtoehdot, syötetään väärä id ei hyväksytä
#include <iostream>
#include <new>
#include <cstring>

using namespace std;

#define ARSIZE 30

struct test(room * roomData);

struct room {
    char room_id[ARSIZE];
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
    
    cout << "Give number of rooms:" << endl;
    cin >> roomNumber;
    cin.get();
    cout << roomNumber << " rooms: " << endl;
    for (i = 0; i < roomNumber; i++){
        cout << "Give room " << i+1 << ":" <<endl;
        cout << "room id: " << endl;
        cin.getline(roomData->room_id, 30, '\n');

        cout << "type(single,double,triple):" << endl;
        cin.getline(roomData->type, 30, '\n');

        cout << "price per night:" << endl;
        cin >> roomData->price;
        fflush(stdin);
        roomData++;
    }
    roomData -= roomNumber;
    test(&roomData);
    // cout << "Give number of customers:" << endl;
    // cin >> customerNumber;
    // cin.get();
    // // fflush(stdin);
    // // customerNumber = 3;
    // cout << customerNumber << " rooms: " << endl;
    // for (i = 0; i < customerNumber; i++){
    //     cout << "Give room " << i+1 << ":" <<endl;
    //     cout << "room id: " << endl;
    //     cin.getline(customerData->room_id, 30, '\n');

    //     cout << "type(single,double,triple):" << endl;
    //     cin.getline(customerData->type, 30, '\n');

    //     cout << "price per night:" << endl;
    //     cin >> customerData->price;
    //     fflush(stdin);
    //     customerData++;
    // }
    // customerData -= customerNumber;

    for (i = 0; i < roomNumber; i++){
        cout << "Room data " << i+1 << ": " << endl;
        cout << roomData -> room_id << endl;
        cout << roomData -> type << endl;
        cout << roomData -> price << endl;
        roomData++;
    }
    
}

struct test(room * roomData){

}