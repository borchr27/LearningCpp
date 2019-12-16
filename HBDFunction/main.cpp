//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>

using namespace std;

// function prototypes
void printHBD();
int printHBD(string);

int main(){
    int myAge;
    // calling functions
    printHBD();
    printHBD();
    cout << "Happy Birthday dear user\n";
    cout << printHBD("Sarah") << endl;
    
    myAge = printHBD("MB");

}

// function header
void printHBD(){
    cout << "Happy Birthday to you\n";
}

//this is not a void function any longer bc we are retunrning an integer
int printHBD(string name){
    int age;
    cout << "Happy Birthday to " << name << endl;
    cout << "Enter your age \n";
    cin >> age;
    return age;
}