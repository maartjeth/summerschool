/* Author: Maartje ter Hoeve

Class to generate a block, which can be placed on the board.
Players are defined by 0 or 1: cross = -1 and circle = 1.

*/

#include <iostream>
#include <stdexcept>
using namespace std;

class Block
{
    int player;
    public:
        Block();
        Block(int);
        void setPlayer(int);
        int getPlayer(void);
};

// Constructor: If no player has been defined, set default to -1
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
    if ((a == 1 || a == -1))
    {
        player = a;
    }
    else
    {
        throw invalid_argument("Value should be set to 1 or -1.");
    }
}

// Getter to get the player's value
int Block::getPlayer(void)
{
    return player;
}

// Main function to test the code
int main()
{
    int turn;
    Block block1(1);
    turn = block1.getPlayer();
    cout << "Player's turn: " << turn;
    //block1.setPlayer(0);
    //turn = block1.getPlayer();
    //cout << "Player's turn: " << turn;
    return 0;
}
