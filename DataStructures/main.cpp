//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>

using namespace std;

struct students{
    string name;
    float gpa;
};

int main(){
    students Teacher;
    Teacher.name = "Dr. Colvin";
    students firstPeriod[10];
    firstPeriod[0].name = "Tom";
    firstPeriod[0].gpa = 3.0;

    cout << firstPeriod[0].name << " " << firstPeriod[0].gpa << endl;


}

