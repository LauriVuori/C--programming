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
    int roomNumber, customerNumber, i, counter;
    bool roomAssigned = false;
    char compareId[ARSIZE];
    char newInfo;
    char temp[30];
    try {
    roomData = new room[ARSIZE];
    
	}catch (bad_alloc xa) {
     cout<<"Memory allocation Failed!";
     return 1;
    }

    try {

    customerData = new customer[ARSIZE];
    
	}catch (bad_alloc xa) {
     cout<<"Memory allocation Failed!";
     return 1;
    }
    
    cout << "Give number of rooms:" << endl;
    cin >> roomNumber;
    cin.get();
    cout <<"Assing data for " << roomNumber << " rooms: " << endl;
    for (i = 0; i < roomNumber; i++){
        cout << "Give room " << i+1 << " id:" <<endl;
        cin.getline(roomData->room_id, 30, '\n');

        cout << "type(single,double,triple):" << endl;
        cin.getline(roomData->type, 30, '\n');

        cout << "price per night:" << endl;
        cin >> roomData->price;
        cin.get();

        cout << endl;
        cout << "Room " << i+1 << " data is: " << endl;
        cout << "Id:" << roomData -> room_id << endl;
        cout << "Type:" << roomData -> type << endl;
        cout << "Price:" << roomData -> price << "e" << endl;
        cout << "Do you want to change information: (y/n)" << endl;
        cin >> newInfo;
        cin.get();
        while ((newInfo != 'y') && (newInfo != 'n')){
            cout << "Give (y/n):" << endl;
            cin >> newInfo;
            cin.get();
        }
        if (newInfo == 'y'){
            cout << "Give room " << i+1 << " id:" <<endl;
            cin.getline(roomData->room_id, 30, '\n');

            cout << "type(single,double,triple):" << endl;
            cin.getline(roomData->type, 30, '\n');

            cout << "price per night:" << endl;
            cin >> roomData->price;
            cin.get();
        }
        cout << "Room data saved" << endl;
        cout << endl;
        roomData++;
    }
    roomData -= roomNumber;

    //Customer part here--->>
    cout << "There is " << roomNumber << " rooms available" << endl;
    cout << "Give number of customers: " << endl;
    cin >> customerNumber;
    cin.get();
    for (i = 0; i < customerNumber; i++){
        cout << "Give customer name: " << endl;
        cin.getline(customerData -> name, 30, '\n');

        cout << "Rooms available are: " << endl;
        for (int ii = 0; ii < roomNumber; ii++){
            cout << "Room " << ii+1 << " data is: " << endl;
            cout << "Id:" << roomData -> room_id << endl;
            cout << "Type:" << roomData -> type << endl;
            cout << "Price:" << roomData -> price << "e" << endl;
            roomData++;
            cout << endl;
        }

        roomData -= roomNumber;
        cout << "What room customer wants(Give room id): " << endl;
        cin.getline(compareId, 30, '\n');
        counter = 0;
        while (roomAssigned == false){
            if (strcmp(compareId, roomData->room_id) == 0){
                cout << "Room " << roomData->room_id << " assigned to " << customerData->name <<  endl;
                strcpy(customerData -> room_id, compareId);
                roomAssigned = true;
            }
            else if (counter > roomNumber){
                cout << "There is no room with that id" << endl;
                cout << "Give new room id:" << endl;
                cin.getline(compareId, 30, '\n');
                roomData -= counter;
                counter = 0;
            }
            else{
                roomData++;
                counter++;
            }
        }
        cout << "Give nights in room:" << endl;
        cin >> customerData -> number_of_nights;
        cin.get();
        roomData -= counter;
        roomAssigned = false;
        
        customerData++;

    }
    customerData -= customerNumber;

    cout << "Room data starts here--->: " << endl;
    for (i = 0; i < roomNumber; i++){
        cout << "Room " << i+1 << " data is: " << endl;
        cout << "Id:" << roomData -> room_id << endl;
        cout << "Type:" << roomData -> type << endl;
        cout << "Price:" << roomData -> price << "e" << endl;
        roomData++;
        cout << endl;
    }
    roomData -= i;

    cout << "Customer data starts here---->" << endl;
    for (i = 0; i < customerNumber; i++){
        cout << "Customer name:" << customerData -> name << endl;
        cout << "Is in room: " << endl;
        counter = 0;
        while (roomAssigned == false){
            if (strcmp(customerData->room_id, roomData -> room_id) == 0){
                cout << "Room id: " << roomData -> room_id << endl;
                cout << "Type: " << roomData -> type << endl;
                cout << "Room price: " << roomData -> price << endl;
                cout << "End price is: " << customerData -> number_of_nights * roomData -> price << "e" << endl;
                roomData -= counter;
                roomAssigned = true;
            }
            else{
            roomData++;
            counter++;
            }
        }
        roomAssigned = false;
        customerData++;
        cout << endl;
    }
    customerData -= i;
    for(i = 0; i < customerNumber; ++i) {
        delete [] customerData;
        customerData++;
    }
    for(i = 0; i < roomNumber; ++i) {
        delete [] roomData;
        roomData++;
    }
}
