#include <iostream> 
using namespace std; 
  
int main(int argc, char** argv) { 

    cout << "Name of program is: " << argv[0] << endl;
    for (int i = 0; i < argc; i++){
        cout << "argv " << i << ":" << argv[i] << "\n";
    }
    cout << endl;

    cout << "You have entered " << argc 
         << " arguments:" << "\n"; 
  
    for (int i = 0; i < argc; ++i) 
        cout << argv[i] << "\n"; 
  
    return 0; 
} 