// A program, which reads values related to the activity of a number 
// of students and prints whether student has passed the course and 
// also his/her grade to the standard output. In this program you define a struct, whose elements are:
// name (an array of char)
// the student's activeness for taking part into lectures and exercises (double),
// whether the project work is done (Boolean),
// the percentage of points got from the exam (double)
// whether the course has been passed or not (bit-field)
// course final grade between 0 and 5 (bit-field) 

// The student passes the course if he/she has got at least 40% of the exam scores, 
// and has done the project work. Each extra 15% of total points will increase the grade by one. 
// If the activity is more than 0.5, the student will get one extra grade. 
// Otherwise, activity does not affect the final grade. The bit-field value 
// for whether the course has been passed or not, is set based on the total values of other variables.

#include <iostream>

using namespace std;

struct StudentInfo{
    char name[15] = {"Paavo"};
    double activeness = 57.54;
    bool project = 1;
    double exampoints = 65.45;
    unsigned int passing : 1;
    unsigned int grade : 3;
};

int main(void){
    struct StudentInfo Student;
    char choice;

    cout << "Do you want give student info y/n:" << endl;
    cin >> choice;

    if (choice == 'y' || choice == 'Y'){
        cout << "Give student name: "<< endl;
        cin >> Student.name;
        cout << "Student activity(double): " << endl;
        cin >> Student.activeness;
        cout << "Does student have done project (1/0): " << endl;
        cin >> Student.project;
        cout << "Give exam points: " << endl;
        cin >> Student.exampoints;
    }
    if (Student.exampoints >= 40.0 && Student.project == 1){
        Student.passing = 1;
        Student.grade = 1;
        if (Student.exampoints >= 55.0 && Student.exampoints < 70.0){
            Student.grade = 2;
        }
        else if (Student.exampoints >= 70.0 && Student.exampoints < 85.0){
            Student.grade = 3;
        }
        else if (Student.exampoints >= 85.0){
            Student.grade = 4;
        }
        if (Student.activeness >= 50.0){
            Student.grade += 1;
        }
    }
    cout << boolalpha << "Student: "<< Student.name << " Students exam points: " << Student.exampoints << "%"
    <<" Activity: "<< Student.activeness << "%" << " Project: "
    << Student.project << " Passed: " << Student.passing << " Grade: " << Student.grade << endl;
}