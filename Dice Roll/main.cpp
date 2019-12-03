//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <ctime>
 #include <cstdlib>
using namespace std;

int main(){

    int dice = 0;
    //seed the rand num generator
    srand(time(0));

    dice = (rand() % 6)+1;
    cout << "You rolled a " << dice << "\n" << endl;

    switch (dice){  //switch is for true and false conditions not comparisons than
        case 1: //if its a 1 do this
            cout << "One \n";
            break;
        case 2: 
            cout << "Two \n";
            break;
        case 3: 
            cout << "Three \n";
            break;
        case 4: 
            cout << "Four \n";
            break;
        case 5:
            cout << "Five \n";
            break;
        case 6:
            cout << "Six \n";
            break;
        default:
            cout << "Invalid \n";
            break;             
    }
    return 0;
}