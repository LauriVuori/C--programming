/*Vihje:
Neliöjuuren voi laskea seuraavasti (palauttaa double-tyypin arvon):
double juuri = sqrt(double_luku);
Tarvitset cmath-kirjastoa.

Example output:
Anna ensimmäinen kateetti:34
Anna toinen kateetti:11
Hypotenuusan pituus: 35.7351*/

#include <iostream>
#include <cmath>


using namespace std;

int main(void){
    int num1, num2;
    double hypotenusa;
    cout << "Give first number: ";
    cin >> num1;
    cout << "Give first number: ";
    cin >> num2;
    hypotenusa = sqrt(pow(num1,2)+pow(num2,2));
    cout << "hypotenusa is:" << hypotenusa<< endl;
}