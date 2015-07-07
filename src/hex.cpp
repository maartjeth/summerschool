#include <iostream>
#include <array>

class hexBoard
/* Initialize a board for the game Hex. */
{
public:
    void InitBoard(int nRows, int nCols)
    {
        char board[nRows][nCols];

        for (int i = 0; i < nRows; i++)
        {
            for (int j = 0; j < nCols; j++)
            {
                board[i][j] = '_';
            }
        }
        for (int k = 0; k < nRows; k++)
        {
            for (int m = 0; m < nCols; m++)
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
    board.InitBoard(11,11);

}
