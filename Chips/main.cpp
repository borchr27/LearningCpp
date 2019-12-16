//Hello World
//Mitchell B
// link to helpful video: https://www.youtube.com/watch?v=DIw02CaEusY
// linkedin learning link https://www.linkedin.com/learning/learning-c-plus-plus-3/using-functions-in-our-program

// need to save code crtl-s, build code, crtl-shft-b, then execute with .\a.exe
#include <iostream>
 #include <ctime>
 #include <cstdlib>

using namespace std;

const int MAX_CHIPS = 100;
const float MAX_TURN = .5;

string FindPlayerName(string names[], bool playerTurn);
void getUserNames(string players[]);
int askMove(bool player1Turn, int chipsInPile, string names[]);

int main()
{

    bool player1Turn = true;
    bool gameOver = false;
    int chipsTaken = 0;
    int chipsInPile = 0;
    int maxChipDraw = 0;
    int randChipsTaken = 0;
    char playAgain = '0';

    //allows player to enter names for player one and player two
    string playerNames[2];
    getUserNames(playerNames);

    do{
        if (gameOver == true){
            cout << "Would you like to play again? Type (Y/N)\n";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            if (playAgain =='Y'){
                gameOver = false;
            }
            else if (playAgain =='N'){
                //dont want to play again
                gameOver = true;
                cout << "THANKS FOR PLAYING\n";
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
            chipsTaken = askMove(player1Turn, chipsInPile, playerNames);
            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " chip(s) left in the pile\n";

            if (chipsInPile == 0){
                gameOver = true;
                cout << FindPlayerName(playerNames, player1Turn) << ", congratulations you won\n";
            }
            else{
                player1Turn = !player1Turn;
            }
        }
    }while (gameOver == true);
    return 0;
}

string FindPlayerName(string names[], bool playerTurn){
    if (playerTurn == true){
        return names[0];
    }
    else{
        return names[1];    
    }    
}

void getUserNames(string players[]){
    //allows player to enter names for player one and player two
    cout << "Player 1, please enter your name: \n";
    cin >> players[0];
    cout << "Player 2, please enter your name: \n(If you wish to play against the computer type AI)\n";
    cin >> players[1];
}

int askMove(bool player1Turn, int chipsInPile, string names[]){
    int chipsTaken;
    int maxPerTurn = MAX_TURN * chipsInPile;
    do{
        cout << FindPlayerName(names, player1Turn) << ", how many chips would you like?\n";
        cout << "You can take up to: ";            
        if (maxPerTurn == 0){
            cout << "1 chip\n";
        }
        else{
            cout << maxPerTurn << " chip(s)" << endl;                
        }
        if(FindPlayerName(names,player1Turn) == "AI"){
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