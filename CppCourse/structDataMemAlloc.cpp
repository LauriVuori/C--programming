//  A program in which you define two data structures: room and customer. 
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
    int totalPrice;


};

void readRoomData(room *, int );
//menu
void updateRoomData(room *, int);

void readCustomerData(room *, customer *, int, int);

void printRoomData(room *, int );
void printCustomerData(room *, customer *, int, int);


int main(void) {
    room * roomData;
    customer * customerData;
    int numberOfRooms = 0, numberOfCustomers;
    
    int roomNumber, customerNumber, i, counter;
    bool roomAssigned = false;
    char compareId[ARSIZE];
    char newInfo;
    char temp[30];

    cout << "Give number of rooms: " << endl;
    cin >> numberOfRooms;
    cin.get();
    try {
       roomData = new room[numberOfRooms];
    }  
    catch (bad_alloc xa) {
       cout<<"Memory allocation Failed!";
    }
    
    readRoomData(roomData, numberOfRooms);
    updateRoomData(roomData, numberOfRooms);
    // printRoomData(roomData, numberOfRooms);


    cout << "Give number of customers: " << endl;
    cin >> numberOfCustomers;
    cin.get();
    try {
      customerData = new customer[numberOfCustomers];
    }   
    catch (bad_alloc xa) {
       cout<<"Memory allocation Failed!";
    }

    readCustomerData(roomData, customerData, numberOfCustomers, numberOfRooms);
    printCustomerData(roomData, customerData, numberOfCustomers, numberOfRooms);

    for(i = 0; i < numberOfCustomers; ++i) {
        delete [] customerData;
        customerData++;
    }
    for(i = 0; i < numberOfRooms; ++i) {
        delete [] roomData;
        roomData++;
    }
}

void readRoomData(room * roomData, int numberOfRooms){
    cout <<"Assing data for " << numberOfRooms << " rooms: " << endl;
    for (int i = 0; i < numberOfRooms; i++){
        cout << "Give room " << i+1 << " id:" <<endl;
        cin.getline(roomData->room_id, 30, '\n');

        cout << "type(single,double,triple):" << endl;
        cin.getline(roomData->type, 30, '\n');

        cout << "price per night:" << endl;
        cin >> roomData->price;
        cin.get();
        roomData++;
    }
    roomData -= numberOfRooms;
}

void updateRoomData(room * roomData, int numberOfRooms){

    cout << "\nUpdating room data: " << endl;
    char resp;
    for (int i = 0; i < numberOfRooms; i++){
        cout << "Room " << i+1 << " data is: " << endl;
        cout << "Id:" << roomData -> room_id << endl;
        cout << "Type:" << roomData -> type << endl;
        cout << "Price:" << roomData -> price << "e" << endl;
        cout << "Do you want to change information: (y/n)" << endl;
        cin >> resp;
        cin.get();
        while ((resp != 'y') && (resp != 'n')){
            cout << "Give (y/n):" << endl;
            cin >> resp;
            cin.get();
        }
        if (resp == 'y'){
            cout << "Give room " << i+1 << " id:" <<endl;
            cin.getline(roomData->room_id, 30, '\n');

            cout << "type(single,double,triple):" << endl;
            cin.getline(roomData->type, 30, '\n');

            cout << "price per night:" << endl;
            cin >> roomData->price;
            cin.get();
        }

        cout << "Room data saved" << endl;
        roomData++;
    }
    roomData -= numberOfRooms;
}

void readCustomerData(room * roomData, customer * customerData, int numberOfCustomers, int NumberOfRooms){
    bool roomAssigned = false;
    int counter = 0, i = 0;
    char compareId[25];
    cout << "There is " << NumberOfRooms << " rooms available" << endl;
    for (i = 0; i < numberOfCustomers; i++){
        cout << "Give customer name: " << endl;
        cin.getline(customerData -> name, 30, '\n');

        cout << "Rooms available are: " << endl;
        for (int ii = 0; ii < NumberOfRooms; ii++){
            cout << "Room " << ii+1 << " data is: " << endl;
            cout << "Id:" << roomData -> room_id << endl;
            cout << "Type:" << roomData -> type << endl;
            cout << "Price:" << roomData -> price << "e" << endl;
            roomData++;
            cout << endl;
        }

        roomData -= NumberOfRooms;
        cout << "What room customer wants(Give room id): " << endl;
        cin.getline(compareId, 30, '\n');
        counter = 0;
        while (roomAssigned == false){
            if (strcmp(compareId, roomData->room_id) == 0){
                cout << "Room " << roomData->room_id << " assigned to " << customerData->name <<  endl;
                strcpy(customerData -> room_id, compareId);
                roomAssigned = true;
            }
            else if (counter > NumberOfRooms){
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
    customerData -= numberOfCustomers;
}
void printRoomData(room * roomData, int numberOfRooms){
    cout << "Print room data: " << endl;
    for (int i = 0; i < numberOfRooms; i++){
        cout << "Room " << i+1 << endl;
        cout << "Room id: " << roomData[i].room_id << endl;
        cout << "Room type: " << roomData[i].type << endl;
        cout << "Room price: " << roomData[i].price << endl;
    }
}
void printCustomerData(room * roomData, customer * customerData, int numberOfCustomers, int numberOfRooms){
    bool roomAssigned = false;
    int i = 0, counter = 0;

    for (i = 0; i < numberOfCustomers; i++){
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
}
