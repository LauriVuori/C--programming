// CPP program to demonstrate multithreading 
// using three different callables. 
#include <iostream> 
#include <thread> 
#include <cstring>

#define MAXLEN 25
using namespace std; 
class employee{
private:
    char name[MAXLEN];
    char id[MAXLEN];
    char job[MAXLEN];
    float salary;
public:
    void set_values(char* , char*, char*, float);
};

void employee::set_values(char* name, char* id, char* job, float salary){
    strcpy(this->name, name);
    strcpy(this->id, id);
    strcpy(this->job, job);
    this->salary = salary;
}

int main(void){
    employee test;
    test.set_values("", "1", "autokauppias", 500);
}