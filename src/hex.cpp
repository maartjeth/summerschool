#include <iostream>
#include <array>

class hexBoard
/* Initialize a board for the game Hex. */
{
public:
    void InitBoard(int nRows = 11, int nCols = 11)
    {
        /*
        The board is wider than the amount of coloms because of the staggered
        nature of the playing board.
        */
        int width = 4 * nCols;
        char board[nRows][width];

        /* The board is populated.*/
        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < 2 * nCols; j+=2)
            {
                board[i][j] = '_';
                board[i][j+1] = ' ';
            }
        }
        /* The board is printed. */
        for (int k = 0; k < nRows; k++)
        {
            for (int m = 0; m < width; m++)
            {
                std::cout << board[k][m];
            }
            std::cout << std::endl;
        }
    }
};

/* Initialize the Hex board with default size 11 x 11. */
// hexBoard::PrintBoard()
// {
//     nRows = 11;
//     nCols = 11;
// }

class chooseLocation
{
public:
    void choose_place()
    {
        std::string location;
        std::cout << "At which location do you want to place a stone?";
        std::cin >> location;
        std::cout << location;

    }
};

int main()
{
    hexBoard board;
    board.InitBoard(13,13);

}
