//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>

using namespace std;

// function prototypes
void printHBD();
void printHBD(string, int&);

int main(){
    int myAge;
    // calling functions
    printHBD();
    printHBD();
    cout << "Happy Birthday dear user\n";

    cout << "\nEnter your age \n";
    cin >> myAge;
    cout << "1. My age is: " << myAge << endl;
    printHBD("Sarah", myAge);
    cout << "2. My age is: " << myAge << endl;
}

// function header
void printHBD(){
    cout << "Happy Birthday to you\n";
}

void printHBD(string name, int& age){
    cout << "Happy Birthday to " << name << endl;
    age = age + 10;
}