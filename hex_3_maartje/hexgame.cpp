/*
* Authors: Jaco & Tom
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
        if(((arr[i])) == 1){
            cout<< "o  ";}//symbool voor speler 1
        else if(((arr[i])) == -1){
            cout << "x  ";}//symbool voor speler -1
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
}


void test(vector<int> arr, int arrayLen)
{
    cout << "Size of board " << arr.size() << endl;
    for (int i=0; i<arrayLen; i++)
    {
       cout << i << ": ";
       cout << ((arr[i])) << endl;
    }
}

/* --------------- GAME LOOP ------------------- */

vector<int> constructBoard(int arrayLength)
{
    vector<int> blockArray(arrayLength, 0);
    return blockArray;
}


// other function that adds items to the array

// Creates board with block objects, all player values are set to zero
vector<int> initializeGame(int nRows, int nCols)
{
    int arrayLength = nRows*nCols;

    vector<int> blockArray = constructBoard(arrayLength);

    // test(blockArray, arrayLength);
    drawBoard(blockArray, arrayLength, nRows, nCols);
    // cout << endl;
    return blockArray;
}

// This is where the game starts running
void runGame(int nRows, int nCols, bool gameRunning){
    vector<int> board = initializeGame(nRows, nCols);
    int turn;
    // while (gameRunning == true) {
    //     cout << "Turn " << turn << endl;
    //
    // }
    cout << "The game is running!\n";
    board[4] = 1;
    board[6] = -1;
    int arrayLength = nRows * nCols;
    drawBoard(board, arrayLength, nRows, nCols);

    //gameLoop();
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
        cout << "Type '?' to check if game is running; type 'exit' to shut down. \n";
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

//  If the user starts the game using 'y', the game will run (i.e. runGame();).
//  The user can check if the game is still running with '?' and can quit the game with 'exit'.
    while (gameRunning){
        getline (cin, mystr);
        if (mystr == "exit"){
            gameRunning = false;
            cout << "The game will shut down.\n";
        }
        else if(mystr == "?"){
            gameRunning = true;
            cout << "Game still running \n";
            //runGame();
            // << Here the actual game should be implemented (possibly instead of checking if the game still runs). >>
        }
        else{
            gameRunning = true;
            cout << "Command unknown \n";
            //runGame(nRows, nCols);
        }

    }
	return 0;
}
