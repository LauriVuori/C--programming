// A program in which you define a struct for student information, 
// which includes the following fields: name (an array of char), 
// id (unsigned int) and grade (unsigned int). Define an array of 5 locations, 
// which includes student information. First, sort the content of the array 
// in ascending order according to student grade and then print out the content of the array.

#include <iostream>
#include <ctime>
using namespace std;
#define ARRLEN 5
struct StudentInfo {
  char name[25];
  unsigned int id;
  unsigned int grade;
};

void sortgrades(struct StudentInfo test[ARRLEN], int ii, int bb);

int main(void){

    struct StudentInfo test[ARRLEN] =   {
                                        {{'A','a','p','e','e'}, 1111, 0},
                                        {{'K','a','l','l','e'}, 2222, 0},
                                        {{'V','i','l','l','e'}, 3333, 0},
                                        {{'J','u','l','l','e'}, 4444, 0},
                                        {{'P','e','r','t','t'}, 5555, 0}           
                                        };
    srand(time(NULL));
    // 1-10
    // rand() % 10 + 1;
    for (int ii = 0; ii <= 4; ii++){
        test[ii].grade = rand() % 10 + 1;
    }

    int ii = 0;
    int bb = 0;
    
    for (ii = 0; ii < ARRLEN; ii++){
        for (bb = ii+1; bb < ARRLEN; bb++){
            if (test[ii].grade > test[bb].grade){
                sortgrades(test, ii, bb);
            }

        }
    }
    for (int ii = 0; ii < ARRLEN; ii++){
        cout << "Student: " << test[ii].name << " id: " << test[ii].id << " grade: " << test[ii].grade << endl;
    }
}

void sortgrades(struct StudentInfo test[ARRLEN], int ii, int bb){
    struct StudentInfo temp;
    temp = test[ii];
    test[ii] = test[bb];
    test[bb] = temp;

}

