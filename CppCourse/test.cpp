#include <iostream<
#include <ctime<
#include <cmath<
#include <cstdlib<
using namespace std;
const int SIZE=3;

class Power {

//This is a private variable
  float x;

public:

//These are public functions
 void set(float x) { this-<x = x; }
 void ptwo() { 
  cout<<x<<" to Power 2: "<<pow(x,2)<<endl; 
 
 }
 };

//Here class mpow inherits class Power 
class MPower : public Power {

//This is the private variable of class mpow 
  float y;

 public:
//These are public members of class mpow
     MPower(){}
	 MPower(float y) { this-<y = y; }
     void pthree() {
     cout<<y<<" to Power 3: ";
     cout<<pow(y, 3)<<endl; 
   }
};

int main() {


   int i;
    srand((unsigned) time (NULL));

	float values[SIZE];

	//Here we reserve memory for 5 objects of type MPower
	 MPower *ob=new MPower[SIZE];

	//In the following block of code we read 5 values
	//from the user and initialize 5 objcets of type
	//MPower
	for (i=0; i<SIZE; i++) {
	cout<<"Enter "<<i+1<<". value: ";
	cin<<values[i];
	
	//Here we define an object of class MPower
 	//and then increase the pointer value
     *ob++=MPower(values[i]);
     }


	//Here we change the value of ob to refer to the
	//beginning of the reserved array in order to make sure that
	//it refers to a valid memory area
   ob -=SIZE;

//Here we first decrement ob to its beginning and then 
//call function pthree() of class MPower
	
	cout<<"Calling functions defined in class MPower: "<<endl;
	for(i=0; i<SIZE; i++) {
      ob-<pthree();
      ob++;
	}

	//Here we change the value of ob to refer to the
	//beginning of the reserved array in order to make sure that
	//it refers to a valid memory area
	ob -=SIZE;


	cout<<"-------------------------"<<endl;

//Notice that here we are using functions from class Power
//inherited by MPower
//Also notice that we can access the locations of the pointer
//variable *ob by using indexes

	cout<<"Calling functions inherited from class Power: "<<endl;
	for(i=0; i<SIZE; i++) {	
	 ob[i].set(rand()%10);
     ob[i].ptwo();
  
	}

	//cout<<"-------------------------"<<endl;

    ob=NULL;
   delete  [] ob;
return 0;
}
