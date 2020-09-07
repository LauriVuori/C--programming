#include <iostream>

using namespace std;

void sortstring(string * ptr1, string * ptr2);


int main(void){
    string names[5];
    string temp;

    for (int ii = 0; ii < 5; ii++){
        cout << "Give name " << ii+1 << ":";
        cin >> names[ii];
        if ((names[ii][0] >= 'a') && (names[ii][0] <= 'z')){
            names[ii][0] -= 32;
        }
        for (int jj = 1; names[ii][jj] != '\0'; jj++) {
            if ((names[ii][jj] >= 'A') && (names[ii][jj] <= 'Z')) {
                names[ii][jj] += 32;
            }
        }
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
            if (names[ii][0] > names[bb][0]){
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