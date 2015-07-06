#include <iostream>
#include <vector>

class hexBoard
{
public:
    char line1[5] = {'*',' ','*',' ','*'};
    char line2[5] = {'  ','*',' ','*',' '};

    void print_board()
    {
        for(int i = 0; i < 6; i++)
        {
            std::cout << line1 << std::endl << line2 << std::endl << line1;
        }
        std::cout << std::endl;
    }
};

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
    board.print_board();

}
