//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <ctime>
 #include <cstdlib>

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
int main(){

    bool player1Turn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipsTaken = 0;
    int maxChipDraw = 0;
    int randChipsTaken = 0;

    //allows player to enter names for player one and player two
    string playerNames[2];
    cout << "Player 1, please enter your name: \n";
    cin >> playerNames[0];
    cout << "Player 2, please enter your name: \n";
    cin >> playerNames[1];

    //seed the rand num generator
    srand(time(0));

    chipsInPile = (rand() % MAX_CHIPS)+1;
    maxChipDraw = chipsInPile * MAX_TURN;
    cout << "This round will start with " << chipsInPile << " chips in the pile \n" << endl;
    if (player1Turn){
        cout << playerNames[0] << ", how many chips would you like?\n";
    }
    else{
        cout << playerNames[1] << ", how many chips would you like?\n";
    }

    cout << "You can only take a max of " << maxChipDraw << " chips" << endl;
    cin >> chipsTaken;

    
    //randChipsTaken = (rand() % maxChipDraw)+1;
    //cout << "Number Taken: " << randChipsTaken << endl;
 

    return 0;



}