#include <iostream>
#include <cstring>

using namespace std;


int main(void){
    const int ARRLEN = 5, TEXTLEN = 25;
    char names[ARRLEN][TEXTLEN], temp[25];
    int ii = 0;
    int bb = 0;

    for (ii = 0; ii < ARRLEN; ii++){
        cout << "Give name " << ii+1 << ":";
        cin.getline(names[ii], TEXTLEN, '\n');
    }





    for (ii = 0; ii < 5; ii++){
        for (bb = ii+1; bb < 5; bb++){
            if (strcmp(names[ii], names[bb]) > 0){
                strcpy (temp, names[ii]);
                strcpy (names[ii], names[bb]);
                strcpy (names[bb], temp);
            }
        }
    }
    cout << "Names :" << endl;
    for (int i = 0; i < 5; i++) {
        cout << names[i] << endl;
    }
}  
