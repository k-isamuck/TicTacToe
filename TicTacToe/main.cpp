#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class TicTacToe {

public:

/* Constructor*/
    TicTacToe(){
/* Initialize defaults here */
    }
/* This is your game board*/
    vector<vector<char>> gameBoard
            {
                    {'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}
            };
/* This prints your game board*/
    void printGameBoard()
    {
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                cout << gameBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
/* This method modifies the game board*/
    void modifyGameBoard(char player, int position)
    {
        // casts position to char
        char positionValue = position + '0';
        // search for position within vector
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                // replace number with player char
                if(positionValue == gameBoard[i][j])
                {
                    gameBoard[i][j] = player;
                }
            }
        }
        printGameBoard();
    }

    // check winner
    bool checkWin(char player){
        for (int i = 0; i < gameBoard.size(); i++)
        {
            // checks horizontal
            if((gameBoard[i][0] == gameBoard[i][1]) && (gameBoard[i][1] == gameBoard[i][2])){
                cout << "Player " << player << " Wins !!!" << endl;
                return true;
            // checks vertical
            }else if((gameBoard[0][i] == gameBoard[1][i]) && (gameBoard[1][i] == gameBoard[2][i])){
                cout << "Player " << player << " Wins !!!" << endl;
                return true;
            }
        }
        // checks from top left to bottom right
        if((gameBoard[0][0] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[2][2])){ // checks diagonals top left to bottom right
            cout << "Player " << player << " Wins !!!" << endl;
            return true;
        }
        // checks from bottom left to top right
        if((gameBoard[2][0] == gameBoard[1][1]) && (gameBoard[1][1] == gameBoard[0][2])){ // checks diagonals top right to bottom left
            cout << "Player " << player << " Wins !!!" << endl;
            return true;
        }
        // returns false if no win is found
        return false;
    }

    // returns current player char
    char getPlayer(int player) {
        // uses turn number to get player char
        if(player%2 == 0){
            return 'X';
        }else{
            return 'O';
        }
    }

    // checks if space is within range and not taken
    bool checkValidPosition(int position){
        if(!(position >= 1 && position <= 9)){
            return false;
        }
        // casts position to char
        char validPosition = position + '0';
        for (int i = 0; i < gameBoard.size(); i++)
        {
            for (int j = 0; j < gameBoard[i].size(); j++)
            {
                // searches if position char is still available
                if(validPosition == gameBoard[i][j])
                {
                    return true;
                }
            }
        }
        return false;
    }

    int getPosition() {
        int position = -1;
        bool done = false;
        // continues until valid position is found
        while (!done) {
            // checks if input is an int
            while (!(cin >> position)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input an integer." << endl;
            }
            // stops if valid position criteria is met
            if(checkValidPosition(position)){
                done = true;
            } else {
                cout << "Pick a unused position within range." << endl;
            }
        }
        return position;
    }

    // runs game
    void startGame(){
        int playerCounter = -1;
        int position;
        char player;
        printGameBoard();
        // continues until a player wins
        do{
            // checks for tied game after 9 turns
            if(playerCounter == 8){
                cout << "Tied game." << endl;
                break;
            }
            playerCounter++;
            player = getPlayer(playerCounter);
            cout << "Player " << player << " Enter Position :" << endl;
            position = getPosition();
            modifyGameBoard(player, position);
        } while(!checkWin(getPlayer(playerCounter)));
    }

};


int main() {

    TicTacToe newGame = TicTacToe();
    newGame.startGame();

    return 0;
}

