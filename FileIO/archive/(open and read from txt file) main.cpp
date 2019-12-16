//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY
// linkedin learning link https://www.linkedin.com/learning/learning-c-plus-plus-3/using-functions-in-our-program

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <fstream>
using namespace std;

int userGuess = 0;

int main()
{
    ifstream inStream;
    inStream.open("passphrase.txt");

    string passPhrase;
    if(!inStream.fail()){
        while(inStream >> passPhrase){
            cout << "The passphrase is: " << passPhrase << endl;
            cout << "What is your answer?\n";
            cin >> userGuess;
            if(userGuess == passPhrase.length()){
                cout << "Congrats\n";
            }
            else{
                cout << "Sorry try again later\n";
            }    
        }
    }
    inStream.close();

}