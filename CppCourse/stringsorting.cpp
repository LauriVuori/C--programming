#include <iostream>

using namespace std;

void sortstring(string * ptr1, string * ptr2);


int main(void){
    string names[5];
    string temp;

    for (int ii = 0; ii < 5; ii++){
        cout << "Give name " << ii << ":";
        cin >> names[ii];
    }
    int ii = 0;
    int bb = 0;
    for (ii = 0; ii < 5; ii++){
        for (bb = ii+1; bb < 5; bb++){
            if (names[ii][0] == names[bb][0]){
                if (names[ii][1] > names[bb][1]){
                    sortstring(&names[ii], &names[bb]);
                }
            }
            else if (names[ii][0] > names[bb][0]){
                sortstring(&names[ii], &names[bb]);
            }

        }
    }

    for (int i = 0; i < 5; i++){
        cout << names[i] << " ";
    }
    cout << endl;
}  


void sortstring(string * ptr1, string * ptr2){
    string temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}