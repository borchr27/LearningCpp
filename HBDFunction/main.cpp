//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>

using namespace std;

void printHBD();
void printHBD(string);
int main(){
    printHBD();
    printHBD();
    cout << "Happy Birthday dear user\n";
    printHBD("Sarah!");
}

void printHBD(){
    cout << "Happy Birthday to you\n";
}

void printHBD(string name){
    cout << "Happy Birthday to " << name;
}