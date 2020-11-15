#include <iostream>

using namespace std;

class rectangle{
private:
    int static object_counter;
    const char* object_name;
    int widht;
    int height;
public:
    //static vairable type
    static const char* type;
    // constructor
    rectangle(const char* object_name, int widht, int width);
    rectangle(const char* object_name);
    rectangle();
    void set_type(const char* type);
    void print_values();
};

const char* rectangle::type;
int rectangle::object_counter;

rectangle::rectangle(const char* object_name, int widht, int height){
    rectangle::object_counter++;
    this->object_name = object_name;
    this->widht = widht;
    this->height = height;

}

rectangle::rectangle(const char* object_name){
    rectangle::object_counter++;
    this->object_name = object_name;
    this->height=this->widht=0;
}

rectangle::rectangle(){
    rectangle::object_counter++;
    this->object_name = "Not known";
    this->height=this->widht=0;
}

void rectangle::set_type(const char* type) {
	this->type=type;
}

void rectangle::print_values(){
    cout << "Object type:" << type << " Object name:" << object_name << " Object widht" << widht << " object height " << height << endl;  
    cout << "Object counter: " << object_counter << endl;
}

int main(void){
    rectangle::type = "<Box static>";
    cout << "Type of rectangles are: " << rectangle::type << endl;

    rectangle rectangle_1("rectangle_1", 10, 15);
    rectangle_1.print_values();
    rectangle rectangle_2("rectangle_2", 12, 17);
    rectangle_2.print_values();

    // dont work as intended, not incrementing counter for each object
    rectangle* rectangleArr = new rectangle[3];
    for (int i = 0; i < 3; i++){
        rectangleArr[i].print_values();
    }


}