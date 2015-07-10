/*
* Authors: Jaco & Tom & Teun & Maartje
* This is the introduction to the game Hex. Running this file will start the game.
*
* !! This code is not finished yet; game should be implemented in While loop.
*/


#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "pathfinding.hpp"

using namespace std;

/* --------------- PRINT BOARD ------------------- */

//Deze functie print het aantal spaties dat gelijk is aan het rijnummer
void indent(int row){
    for(int i = 0; i <row; i++){
        cout << " ";
    }
}

void drawBoard(vector<int> arr, int size, int nRows, int nCol){
    int currRow = 0;
    int currCol = 0;
    cout << "    ";//het eerste kolomnummer wordt met 4 spaties ingesprongen
    for (int i = 0; i < nCol; i++){//de kolomnummers worden boven de kolommen geplaatst
        cout << i << "  ";
    }
    cout << "\n\n" << currRow << "   ";//het eerste rij nummer wordt geprint

    for (int i = 0; i<size; i++){
        int row = (i+1)/(nCol);
        if(((arr[i])) == 1){cout<< "o  ";}//symbool voor speler 1
        else if(((arr[i])) == -1){cout << "x  ";}//symbool voor speler -1
        else if(((arr[i])) == 0){cout << "-  ";}
        //als row groter is dan currRow moet een nieuwe rij begonnen worden
        if (row > currRow){
            currRow = row;
            cout << "\n\n";
            indent(row);
            if (currRow < nRows){
                 if (currRow <10){//10 heeft twee tekens, dus een spatie minder
                    cout<< currRow << "   ";
                 }
                 else {
                    cout<< currRow << "  ";
                 }
            }
        }
    }
    cout << endl;
}


/* --------------- GAME LOOP ------------------- */

vector<int> constructBoard(int arrayLength)
{
    vector<int> blockArray(arrayLength, 0);
    return blockArray;
}


// Creates board with block objects, all player values are set to zero
vector<int> initializeGame(int nRows, int nCols)
{
    int arrayLength = nRows*nCols;
    vector<int> blockArray = constructBoard(arrayLength);

    return blockArray;
}

// This is where the game starts running
void runGame(int nRows, int nCols, bool gameRunning){
    vector<int> board = initializeGame(nRows, nCols);
    int turn = 1;
    int player = 1;
    while (gameRunning == true) {
        cout << endl << "------------------- TURN: " << turn << " -------------------" << endl << endl;
        cout << "Player: " << player << endl << endl;
        //cout << "Turn " << turn << endl << endl;
        int arrayLength = nRows * nCols;
        drawBoard(board, arrayLength, nRows, nCols);
        string position;
        cout << "Please specify the position you want to put a stone on \nor type 'exit' to end the game. " << endl;
        getline (cin, position);

        if (position == "exit"){
            gameRunning = false;
            cout << "Thanks for playing! The game will shut down.\n";
            break;
        }

newposition:
        istringstream buffer(position);
        int positionint;
        buffer >> positionint;

        // check whether position is taken

        if (board[positionint] == 0){
          board[positionint] = player;
        } else {
            cout << "This position is already taken! Please specify the position again. " << endl;
            getline(cin, position);
            goto newposition;
        }
        Pathfinding path;
        bool isWinningMove = path.dfs(board, nRows, nCols, player);
        if (isWinningMove == true)
        {
            cout << "You won!" << endl;
            drawBoard(board, arrayLength, nRows, nCols);
            break;
        }
        // When the board is full, end the game.
        if (turn >=arrayLength)
        {
            cout << "That's a draw." << endl;
            drawBoard(board, arrayLength, nRows, nCols);
            break;
        }
        turn += 1;
        player *= -1;


    }
}


int main (){

    int nRows, nCols;

//  The user can choose to start with 'y' or quit with 'n'. Any other command will ask again to start the game.
    cout << "Welcome to Hex! \n";
start:
    cout << "Do you want to start a new game? (y/n) ";
    string mystr;
    bool gameRunning;
    getline (cin, mystr);

    if (mystr == "y"){
        cout << "Please specify the width of the board: ";
        getline (cin, mystr);
        stringstream(mystr) >> nCols;
        cout << "Please specify the height of the board: ";
        getline (cin, mystr);
        stringstream(mystr) >> nRows;

        gameRunning = true;
        cout << "Type 'exit' to shut down. \n";
        runGame(nRows, nCols, gameRunning);
    }

    else if(mystr == "n"){
        gameRunning = false;
        cout << "Too bad...";
    }

    else{
        cout << "Command unknown; please use 'y' or 'n'... \n";
        goto start;
    }

    return 0;
}
