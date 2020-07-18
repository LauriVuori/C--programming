/*
Tee ohjelma, joka kysyy käyttäjältä ympyrän säteen ja laskee annetun säteen
perusteella ympyrän pinta-alan. Lopuksi pinta-ala tulostetaan näytölle. 
Piin (π) arvona käytetään likiarvoa 3.142. Käyttäjän oletetaan syöttävän säteen 
arvoksi kokonaislukuja.

*/
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    double circlerad, area;
    cout << "Give circle radius: ";
    cin >> circlerad;
    area = 3.142*(pow(circlerad,2));
    cout << "Area is : " <<  area << endl;
}