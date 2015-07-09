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
#include "block.h"
#include "board.h"

using namespace std;


/* --------------- CLASS BLOCK ------------------- */

Block::Block()
{
    player = -1;
}

// Constructor: Set player to a
Block::Block(int a)
{
    try
    {
        if ((a == 1) || (a == -1) || (a == 0))
        {
            player = a;
        }
        else
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "This is not valid input.\n";
    }
}

// Setter to change player's value if needed
void Block::setPlayer(int a)
{
    try
    {
        if ((a == 1) || (a == -1) || (a == 0))
        {
            player = a;
        }
        else
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "This is not valid input.\n";
    }
}

// Getter to get the player's value
int Block::getPlayer(void)
{
    return player;
}


/* --------------- CLASS BOARD ------------------- */

Board::Board()
{
    cout << "blablabla";
}

Board::Board(int arrayLength)
{
    cout << "test";
}


/* --------------- PRINT BOARD ------------------- */

//Deze functie print het aantal spaties dat gelijk is aan het rijnummer
void indent(int row){
    for(int i = 0; i <row; i++){
            cout << " ";
    }
}

void drawBoard(Block* arr, int size, int nRows, int nCol){
    int row, col;
    int currRow = 0;
    int currCol = 0;
    cout << "    ";//het eerste kolomnummer wordt met 4 spaties ingesprongen
    for (int i = 0; i < nCol; i++){//de kolomnummers worden boven de kolommen geplaatst
        cout << i << "  ";
    }
    cout << "\n\n" << currRow << "   ";//het eerste rij nummer wordt geprint

    for (int i = 0; i<size; i++){
            row = (i+1)/(nCol);
            if((*(arr+i)).getPlayer() == 1){
                cout<< "o  ";//symbool voor speler 1
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
            else if((*(arr+i)).getPlayer() == -1){
                cout << "x  ";//symbool voor speler -1
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
            else if ((*(arr+i)).getPlayer() == 0){
                cout << "-  ";
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
}

void test(Block* arr, int arrayLen)
{
    //cout << (*arr).getPlayer();
    for (int i=0; i<arrayLen; i++)
    {
       cout << i << ": ";
       cout << ((arr+i)).getPlayer() << endl;
    }
}

/* --------------- GAME LOOP ------------------- */

Block* constructBoard(int arrayLength)
{
    //Block* emptyBoard = new Block[arrayLength];
    Block blockArray[arrayLength];

    for (int i=0; i<arrayLength; i++)
    {
        blockArray[i].setPlayer(0);
    }

    /*// check whether array is correct
    int nRows = 5;
    int nCol = 5;
    drawBoard(blockArray, arrayLength, nRows, nCol); */


    return blockArray;
}


// other function that adds items to the array

// Creates board with block objects, all player values are set to zero
void initializeGame(int nRows, int nCol)
{
    int arrayLength = nRows*nCol;

    /*Block* blockArray

    Block blockArray[arrayLength];
    for(int i = 0; i < arrayLength; i++){
        blockArray[i].setPlayer(0);//Alles is bezet door speler 1
    } */

    Block* blockArrayPointer;

    blockArrayPointer = constructBoard(arrayLength);

    test(blockArrayPointer, arrayLength);
    //drawBoard(blockArrayPointer, arrayLength, nRows, nCol);
    cout << endl;
}

// This is where the game starts running
void runGame(int nRows, int nCols){
    initializeGame(nRows, nCols);
    //gameLoop();
}


int main (){

    int nRows, nCols;

//  The user can choose to start with 'y' or quit with 'n'. Any other command will ask again to start the game.
    cout << "Welcome to Hex! \n";
start:
    cout << "Do you want to start a new game? (y/n) \n";
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
        runGame(nRows, nCols);
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
            cout << "The game will shut down.";
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
            //runGame();
        }

    }
	return 0;
}
