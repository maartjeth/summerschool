/*

Header file for the board.cpp file

*/

class Board
{
    int width;
    int height;
    Block board[12][12];

    public:
        Board();
        Board(int, int);
        // void makeBoard(int, int); // this might have to return an array (which is not allowed in c++)
        Block ** constructBoard(int, int);

};
