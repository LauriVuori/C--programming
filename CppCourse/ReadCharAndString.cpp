#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    char rivi[255];
    char merkki;
 
    
    ifstream luku("nums.txt");

    
    if (luku.is_open()) {
        while (luku.get(merkki) && luku.getline(rivi, 255)){
            cout << rivi << ": " << "luokka " << merkki << endl;
        }
    }
    else {
    cout << "Tiedoston avaaminen ei onnistunut!" << endl;
    exit(-1);
    }
}
