/*
Author: Maartje ter Hoeve

Class that constructs the board.

*/

#include <iostream>
#include "block.h"
#include "board.h"
#include "vector"

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

void Board::makeBoard(int width, int height)
{
//    Block board[width][height];
    vector<vector<Block> > board(height);
    for ( int i = 0 ; i < height ; i++ )
        board[i].resize(width);
//    Block board = matrix;

}

int main()
{
    Board board;
    board.makeBoard(12, 12);
    cout << "hallooooo";
}



