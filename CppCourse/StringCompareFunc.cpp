#include <iostream>
#include <cstring>

using namespace std;


int main(void){
    char names[5][25], temp[25];
    int ii = 0;
    int bb = 0;

    for (ii = 0; ii < 5; ii++){
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





    for (ii = 0; ii < 5; ii++){
        for (bb = ii+1; bb < 5; bb++){
            if (strncmp(names[ii], names[bb], 1) > 0){
                strcpy (temp, names[ii]);
                strcpy (names[ii], names[bb]);
                strcpy (names[bb], temp);
            }
            else if (strncmp(names[ii], names[bb], 1) == 0){
                if (strncmp(names[ii], names[bb], 2) > 0){
                    strcpy (temp, names[ii]);
                    strcpy (names[ii], names[bb]);
                    strcpy (names[bb], temp);
                }
            }
        }
    }
    cout << "Names :" << endl;
    for (int i = 0; i < 5; i++) {
        cout << names[i] << endl;
    }
}  