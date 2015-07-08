/*
Author: Maartje ter Hoeve

Class that constructs the board.

*/

#include <iostream>
#include <stdexcept>
#include "block.h"
#include "board.h"


using namespace std;

//CLASS BLOCK
Block::Block()
{
    player = -1;
}

// Constructor: Set player to a
Block::Block(int a)
{
    try
    {
        if ((a == 1) || (a == -1))
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
    // if (!((a == 1) || (a == -1)))
    // {
    //     throw invalid_argument("Value should be set to 1 or -1!");
    //     //player = a;
    // }
    // else
    // {
    //     player = a;
    //     //throw invalid_argument("Value should be set to 1 or -1.");
    // }

}

// Setter to change player's value if needed
void Block::setPlayer(int a)
{
    try
    {
        if ((a == 1) || (a == -1))
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

/*class Board
{
    Block* boardPointer;
    public:
        Board();
        Board(int);
        //getBoard....
}; */

//CLASS BOARD
Board::Board()
{
    cout << "blablabla";
}

Board::Board(int arrayLength)
{
    //Block boardArray[arrayLength];
    //boardPointer = &

    //boardPointer = new Block[arrayLength];
    //Block test[arrayLength];

    cout << "test";
}

int main()
{
    cout << "hey there!";
    Block blockArray[12];
    for(int i = 0; i < 12; i++){
        blockArray[i].setPlayer(1);//Alles is bezet door speler 1
        int testValue = blockArray[i].getPlayer();
        cout << testValue;
    }


    //Board board1;
    //Board board1(12);
    //Block block1(-1);
    return 0;
}

// OLD CODE STARTING FROM THIS POINT

/*class Board
{
    int width;
    int height;
    Block[] board;

    public:
        Board();
        Board(int, int);
        void makeBoard(int, int); // this might have to return an array (which is not allowed in c++)

}; */

/*Board::Board()
{
    width = 12;
    height = 12;
}

Board::Board(int a, int b)
{
    width = a;
    height = b;
}

Block* Board::constructBoard(int arrayLength)
{
    Block board[arrayLength];
    return board;
}

// Returns a pointer to a pointer to an array --> ultimately creating a pointer to a 2D array?
/*Block** Board::constructBoard(int width, int height)
{
    // creating a 2D array
    Block **board;
    board = new Block*[width];

    for (int i=0; i<width; i++)
    {
        board[i] = new Block[height]; // each i-th pointer is now pointing to a dynamic array (size 10) of block values --> 2D array created
    }

    //static Block board[12][12]; // needs to be static as c++ does not advocate to return the address of a local variable to outside of the function
    return board;
} */

/*
void Board::makeBoard(int width, int height)
{
    Block board[width][height];
    cout << board;
} */


/*

STILL TO BE DONE:   Test whether this really works

*/
/*
int main()
{
    Board board;
    board.constructBoard(10);
   // board.makeBoard(12, 12);
    //Block** boardArray = board.constructBoard(12,12);


    /*for (int i=0; i<12; i++)
    {
        for (int j=0; j<12; j++)
        {
            Block test(1);
            boardArray[i][j] = test;
        }
    } *;

    //cout << boardArray[5][5]; */
//}



