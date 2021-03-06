//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY
// linkedin learning link https://www.linkedin.com/learning/learning-c-plus-plus-3/using-functions-in-our-program

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <ctime>
 #include <cstdlib>
 #include <fstream>

using namespace std;

struct player{
    string name;
    int numWins;
};

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;
ofstream outStream;

string FindPlayerName(player[], bool playerTurn);
void getUserNames(player []);
int askMove(bool player1Turn, int chipsInPile, player[]);
void addWin(player[], bool);

int main()
{
    bool player1Turn = true;
    bool gameOver = false;
    int chipsTaken = 0;
    int chipsInPile = 0;
    int maxChipDraw = 0;
    int randChipsTaken = 0;
    char playAgain = '0';
    int moveCounter = 0;
    outStream.open("MoveCounterFile.txt",ios::app);

    //allows player to enter names for player one and player two (max two bc using bool)
    player Players[2];
    getUserNames(Players);

    do{
        if (gameOver == true){
            cout << "Would you like to play again? Type (Y/N)\n";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            if (playAgain =='Y'){
                gameOver = false;
                moveCounter = 0;
            }
            else if (playAgain =='N'){
                //dont want to play again
                gameOver = true;
                cout << "THANKS FOR PLAYING\n";
                cout << Players[0].name << " had " << Players[0].numWins << " total wins this round " << endl;
                cout << Players[1].name << " had " << Players[1].numWins << " total wins this round " << endl;
                outStream.close();
                break;
            }
            else{
                cout << "Please type Y/N \n";
                gameOver = true;
            }
        }
        else{
            gameOver == false;
            }
        
        //seed the rand num generator
        srand(time(0));
        chipsInPile = (rand() % MAX_CHIPS)+1;
        maxChipDraw = chipsInPile * MAX_TURN;
        cout << "This round will start with " << chipsInPile << " chips in the pile \n";

        while (gameOver == false){
            chipsTaken = askMove(player1Turn, chipsInPile, Players);

            moveCounter = moveCounter + 1;

            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " chip(s) left in the pile\n";

            if (chipsInPile == 0){
                gameOver = true;
                cout << FindPlayerName(Players, player1Turn) << ", congratulations you won\n";
                outStream << "Player " << FindPlayerName(Players, player1Turn) << " wins in " << moveCounter << " moves!" << endl;
                addWin(Players, player1Turn);
            }
            else{
                player1Turn = !player1Turn;
            }
        }
    }while (gameOver == true);
    return 0;
}


// FUNCTIONS
string FindPlayerName(player Players[], bool playerTurn){
    if (playerTurn == true){
        return Players[0].name;
    }
    else{
        return Players[1].name;    
    }    
}

void getUserNames(player Players[]){
    //allows player to enter names for player one and player two
    cout << "Player 1, please enter your name: \n";
    cin >> Players[0].name;
    cout << "Player 2, please enter your name: \n(If you wish to play against the computer type AI)\n";
    cin >> Players[1].name;
    Players[0].numWins = 0;
    Players[1].numWins = 0;
}

int askMove(bool player1Turn, int chipsInPile, player Players[]){
    int chipsTaken;
    int maxPerTurn = MAX_TURN * chipsInPile;
    
    do{
        cout << FindPlayerName(Players, player1Turn) << ", how many chips would you like?\n";
        cout << "You can take up to: ";            
        if (maxPerTurn == 0){
            cout << "1 chip\n";
        }
        else{
            cout << maxPerTurn << " chip(s)" << endl;                
        }
        if(FindPlayerName(Players, player1Turn) == "AI"){
            if(maxPerTurn == 0){
                chipsTaken = 1;
            }
            else{
                chipsTaken = (rand() % maxPerTurn) + 1;
                cout << "AI took " << chipsTaken << " chips\n";
            }
        }
        else{
            cin >> chipsTaken;
        }
    } while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));
    return chipsTaken;
}

void addWin(player Players[], bool player1Turn){
    if(player1Turn){
        Players[0].numWins++;
    }
    else{
        Players[1].numWins++;
    }
}