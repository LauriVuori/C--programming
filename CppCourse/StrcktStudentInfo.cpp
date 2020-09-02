// A program in which you define a struct for student information, 
// which includes the following fields: name (an array of char), 
// id (unsigned int) and grade (unsigned int). Define an array of 5 locations, 
// which includes student information. First, sort the content of the array 
// in ascending order according to student grade and then print out the content of the array.

#include <iostream>
using namespace std;

struct StudentInfo {
  char name[25];
  unsigned int id;
  unsigned int grade;
};

void AddNames(struct Info);

int main(void){

    struct StudentInfo test[5] =    {
                                    {{'A','a','p','e','e'}, 2304, 0},
                                    {{'K','a','l','l','e'}, 1324, 0},
                                    {{'V','i','l','l','e'}, 5023, 0},
                                    {{'J','u','l','l','e'}, 1233, 0},
                                    {{'P','e','r','t','t'}, 6565, 0}           
                                    };
    

}

