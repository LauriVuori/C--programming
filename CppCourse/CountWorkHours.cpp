#include <iostream>

using namespace std;

int main(){
    int days, counter = 0;
    double HoursAverage = 0, Hours[30], HoursSum = 0;
    cout << "How many days:";
    cin >> days;
    
    while (counter < days){
        cout << "Give " << counter+1 <<" days working hours:";
        cin >> Hours[counter];
        HoursSum += Hours[counter];
        counter++;
    }
    HoursAverage = double(HoursSum) / double(counter);
    printf("Sum: %d\n", HoursSum);
    printf("Average: %f\n", HoursAverage);
    cout << "Added hours: ";
    for (int i = 0; i < counter; i++){
        cout << Hours[i] << " ";
    }
    cout << endl;
}