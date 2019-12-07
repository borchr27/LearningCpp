//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <ctime>
 #include <cstdlib>
using namespace std;

/* Loop Example
int main(){

    for (int h = 0; h < 24; h++){
        for (int m = 0; m < 60; m++){
            for (int s = 0; s < 60; s++){
                cout << h << ":" << m << ":" << s << endl;
            }
        }
    }
}
*/

// Do While Loop Example
int main(){
    int userChoice = 0;
    do{
        cout << "Hello welcome to my menu\n";
        cout << "Please choose one of the following options \n";
        cout << "1. continue ya filthy animal\n";
        cout << "2. quit\n";
        cin >> userChoice;
    }while(userChoice == 1);
}

