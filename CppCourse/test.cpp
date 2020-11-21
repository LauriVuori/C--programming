#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define PI 3.14159265
#define LEN 20
//This is the definition for class Triangle
class Triangle {
 const char* object_name;
//Here we declare ordinary non-static variables
   float side1, side2, angle;
   //Here we define a private static variable
   int static object_counter;
 public:
   //Here we declare static variable type, which has public access specifier
     static const char* type;
   	   //This is the class constructor
	 Triangle(const char*, float, float, float);
	 Triangle(const char*);
	 void set_type(const char*);
     void print_string();
};
//Here we declare static variable type again
const char* Triangle::type;
//Here we declare static variable object_counter again
int Triangle::object_counter;
//Here we access the static variable through the name of the class.
Triangle:: Triangle(const char* object_name, float side1, float side2, float angle)
{
		 //Here we increment the object counter
		 Triangle::object_counter++;
		 this->object_name=object_name;
		 this->side1=side1;
		 this->side2=side2;
		 this->angle=angle;
}
Triangle::Triangle(const char* object_name)
{
		 //Here we increment the object counter
		 Triangle::object_counter++;
		 this->object_name=object_name;
		 //Here we initialise numerical values to zero
		 this->side1=this->side2=this->angle=0;
}
void Triangle::set_type(const char* type) {
	this->type=type;
}
void Triangle::print_string(){
	cout<<"object_name="<<object_name<<" object_count="<<object_counter<<" type="<<type<<" side1="<<side1<<" side2="<<side2<<" angle="<<angle<<endl;
}
int main() {
  //Here we initialise class static variable type through the name of the class.
 //We don't need to create any object to initialise a static attribute
  Triangle::type="Scalene";
  //Here we access the static attribute type through the name of the class
   cout<<"The value of Triangle::type: "<<Triangle::type<<endl;
 //Here we initialise triangle_1 object
  Triangle triangle_1("triangle_1", 10, 8, 38);
  //Here we print the contents of the object as text
   triangle_1.print_string();
   ////Here we define a new Triangle object, but we do not initialise the value for
   //type attribute. Since type attribute is static, it has the value initialised earlier
    Triangle triangle_2("triangle_2", 12, 12, 60);
    //Here we print the contents of the object as text
     triangle_2.print_string();
    //Here we define a new Triangle object with default constructor
     Triangle triangle_3("triangle_3", 10,10, 30);
     //Here we print the contents of the object as text
          triangle_3.print_string();
          //Here we set the type for triangle_3. Since attribute type is static, the new value
        //will be set for all objects of class Triangle;
         triangle_3.set_type("Isosceles");
         cout<<endl;
  cout<<"Printing Triangle objects as text after setting type attribute through triangle_3:"<<endl;
  //Here we print the contents of the object as text
       triangle_3.print_string();
       //Here we print the contents of the object as text
            triangle_2.print_string();
            //Here we print the contents of the object as text
                 triangle_1.print_string();
return 0;
}