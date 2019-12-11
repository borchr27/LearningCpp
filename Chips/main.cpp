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
int main()
{

    bool player1Turn = true;
    bool gameOver = false;
    int chipsInPile = 0;
    int chipsTaken = 0;
    int maxChipDraw = 0;
    int randChipsTaken = 0;
    int playAgain = 0;

    //allows player to enter names for player one and player two
    string playerNames[2];
    cout << "Player 1, please enter your name: \n";
    cin >> playerNames[0];
    cout << "Player 2, please enter your name: \n";
    cin >> playerNames[1];

    do{
        if (gameOver == true){
            cout << "Would you like to play again, type 1 for yes or 0 for no?\n";
            cin >> playAgain;
            if (playAgain == 1){
                gameOver == false;
            }
            else if (playAgain == 0){
                //dont want to play again
                gameOver == true;
                break;
            }
            else{
                cout << "Please type a 1 or a 0";
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
        
        while (gameOver == false)
        {
            do
            {
                if (player1Turn){
                    cout << playerNames[0] << ", how many chips would you like?\n";
                }
                else{
                    cout << playerNames[1] << ", how many chips would you like?\n";                
                }
                cout << "You can take up to: ";            
                if (static_cast<int>(MAX_TURN * chipsInPile) == 0){
                    cout << "1 chip\n" ;
                }
                else{
                    cout << static_cast<int>(MAX_TURN * chipsInPile) << " chip(s)" << endl;                
                }            
                cin >> chipsTaken;                
            } while (chipsTaken > (static_cast<int>(MAX_TURN * chipsInPile)) && (chipsInPile > 1));

            chipsInPile = chipsInPile - chipsTaken;
            cout << "There are " << chipsInPile << " chip(s) left in the pile\n";
            if (chipsInPile == 0){
                gameOver == true;
                if (player1Turn){
                    cout << playerNames[1] << ", congratulations you won\n";
                    return gameOver;
                }
                else{
                    cout <<  playerNames[0] << ", congratulations you won\n";
                    return gameOver;
                }
            }
            else{
                player1Turn = !player1Turn;
            }
        }

    }while (gameOver == true);

    return 0;
}