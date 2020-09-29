#include <iostream>
using namespace std;

#define ARSIZE 50

void allocateMem(int *);

int main(void) {
   int * testi;

allocateMem(testi);
}

void allocateMem(int * test){
   int i = 5;
   test = &i;
   cout << *test << endl;
}