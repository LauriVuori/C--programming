
#include <iostream>
using namespace std;

int main(){
    int age;
    char sex;
    
    cout << "Give sex:";
    cin >> sex;
    cout << "Give age:";
    cin >> age;

    
    if ((sex == 'm') && (age >= 0 && age <= 55)){
        cout << "m 0-55" << endl;
    }
    else if((sex == 'm') && (age >= 56 && age <= 100)){
        cout << "m 56-100" << endl; 
    }
    else if ((sex == 'n') && (age >= 0 && age <= 55)){
        cout << "n 0-55" << endl; 
    }
    else if((sex == 'n') && (age >= 56 && age <= 100)){
        cout << "n 56-100" << endl;
    }
    else{
        cout << "else" << endl;
    }

}