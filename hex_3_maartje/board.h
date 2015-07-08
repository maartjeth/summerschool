/*

Header file for the board.cpp file

*/

/*class Board
{
    int width;
    int height;
    //Block board[12][12];

    public:
        Board();
        //Board(int, int);
        Board(int);
        // void makeBoard(int, int); // this might have to return an array (which is not allowed in c++)
        // Block ** constructBoard(int, int);
        Block* constructBoard(int);

};
*/

// NEW CODE STARTING FROM THIS POINT

class Block;

class Board
{

    Block* boardPointer[];
    public:
        Board();
        //Board();
        Board(int);
        //getBoard....
};
