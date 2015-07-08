/*
Author: Maartje ter Hoeve

Class that constructs the board.

*/

#include <iostream>
#include "block.h"
#include "board.h"

using namespace std;


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

Board::Board()
{
    width = 12;
    height = 12;
}

Board::Board(int a, int b)
{
    width = a;
    height = b;
}

// Returns a pointer to a pointer to an array --> ultimately creating a pointer to a 2D array?
Block** Board::constructBoard(int width, int height)
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
}

/*
void Board::makeBoard(int width, int height)
{
    Block board[width][height];
    cout << board;
} */


/*

STILL TO BE DONE:   Test whether this really works

*/
int main()
{
    Board board;
   // board.makeBoard(12, 12);
    Block** boardArray = board.constructBoard(12,12);


    for (int i=0; i<12; i++)
    {
        for (int j=0; j<12; j++)
        {
            Block test(1);
            boardArray[i][j] = test;
        }
    }

    //cout << boardArray[5][5];
}



