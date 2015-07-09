/*
* Authors: Jaco & Tom
* This is the introduction to the game Hex. Running this file will start the game.
*
* !! This code is not finished yet; game should be implemented in While loop.
*/


#include <iostream>
#include <string>
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

/* --------------- GAME LOOP ------------------- */

// Creates board with block objects, all player values are set to zero
void initializeGame(int arrayLength)
{
    Block blockArray[arrayLength];
    for(int i = 0; i < arrayLength; i++){
        blockArray[i].setPlayer(0);//Alles is bezet door speler 1
        int testValue = blockArray[i].getPlayer();
        cout << testValue;
    }
}

// This is where the game starts running
void runGame(int arrayLength){
    initializeGame(arrayLength);
    gameLoop();
}


int main (){

    int width, height, dim;

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
        stringstream(mystr) >> width;
        cout << "Please specify the height of the board: ";
        getline (cin, mystr);
        stringstream(mystr) >> height;
        dim = width*height;

        gameRunning = true;
        cout << "Type '?' to check if game is running; type 'exit' to shut down. \n";
        rungame(dim);
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
