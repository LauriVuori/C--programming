
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
