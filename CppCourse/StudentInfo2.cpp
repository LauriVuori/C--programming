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
#define ARLLEN 3
using namespace std;

struct StudentInfo{
    char name[15];
    double activeness;
    bool project;
    double exampoints;
    unsigned int passing : 1;
    unsigned int grade : 3;
};

int main(void){
    struct StudentInfo Student[ARLLEN] = {
                                     {{"Ville"}, 57.54, 1, 65.45},
                                     {{"Aapeli"}, 85.55, 1, 45.22}
                                     };

    cout << "Give one student info: " << endl;
    cout << "Give student name: "<< endl;
    cin >> Student[2].name;
    cout << "Student activity(double0-100.0): " << endl;
    cin >> Student[2].activeness;
    cout << "Does student have done project (1/0): " << endl;
    cin >> Student[2].project;
    cout << "Give exam points(double 0-100.): " << endl;
    cin >> Student[2].exampoints;
    for (int i = 0; i < ARLLEN; i++){
        if (Student[i].exampoints >= 40.0 && Student[i].project == 1){
            Student[i].passing = 1;
            Student[i].grade = 1;
            if (Student[i].exampoints >= 55.0 && Student[i].exampoints < 70.0){
                Student[i].grade = 2;
            }
            else if (Student[i].exampoints >= 70.0 && Student[i].exampoints < 85.0){
                Student[i].grade = 3;
            }
            else if (Student[i].exampoints >= 85.0){
                Student[i].grade = 4;
            }
            if (Student[i].activeness >= 50.0){
                Student[i].grade += 1;
            }
        }
    }
    cout << "Student grades: " << endl;
    for (int i = 0; i < ARLLEN; i++){
        cout << boolalpha << "Student: "<< Student[i].name << " Students exam points: " << Student[i].exampoints << "%"
        <<" Activity: "<< Student[i].activeness << "%" << " Project: "
        << Student[i].project << " Passed: " << Student[i].passing << " Grade: " << Student[i].grade << endl;
    cout << "\n" << endl;
    }
}