// A program, which reads values related to the activity of a number 
// of students and prints whether student has passed the course and 
// also his/her grade to the standard output. In this program you define a struct, whose elements are:
// name (an array of char)
// the student's activeness for taking part into lectures and exercises (double),
// whether the project work is done (Boolean),
// the percentage of points got from the exam (double)
// whether the course has been passed or not (bit-field)
// course final grade between 0 and 5 (bit-field) 

#include <iostream>

using namespace std;

struct StudentInfo{
    char name[15] = {"Paavo"};
    double activeness = 57.54;
    bool project = 1;
    unsigned int passing : 1 = 1;
    unsigned int grade : 3 = 5;
};

int main(void){
    struct StudentInfo Student;
    cout << boolalpha << "Student: "<< Student.name <<" Activity: "<< Student.activeness << "%" << " Project: "
    << Student.project << " Passed: " << Student.passing << " Grade: " << Student.grade << endl;
}