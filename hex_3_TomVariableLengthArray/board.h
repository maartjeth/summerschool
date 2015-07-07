/*

Header file for the board.cpp file

*/

class Board
{
    int width;
    int height;
    Block board[];

    public:
        Board();
        Board(int, int);
        void makeBoard(int, int); // this might have to return an array (which is not allowed in c++)

};
