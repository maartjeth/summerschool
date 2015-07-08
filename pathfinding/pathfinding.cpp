// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>

class intArray
{
public:
    int board[169];
    int sizearray = sizeof(board)/sizeof(*board);

    void popArray ()
    {
        for (int i = 0; i < sizearray; i++)
        {
            board[i] = 0;
        }
        for (int j = 0; j < sizearray; j++)
        {
            std::cout << board[j];
            if ((j+1) % 13 ==0) {
                std::cout << std::endl;
            }
        }
    }

};

class pathfinding
{
    /*
    Find a route through a board represented as an integer array by using
    Depth First Search
    */

public:
    float dfs(int arr [], int startnode)
    {
        // List of nodes that have been visited.
        std::list<int> visited;
        // Stack of nodes still to visit.
        std::stack<int> nodes;
        // Add first node to the stack.
        nodes.push(startnode);

        // While there are still nodes to be visited.
        while (!nodes.empty())
        {
            // Find the top of the stack.
            int top;
            top = nodes.top();
            nodes.pop();
            std::cout << top << std::endl;
            // If the top has not been visited.
            if (find( visited.begin(), visited.end(), top) == visited.end())
            {
                // If we have come to the edge of the graph.
                if ((top+1)%13 == 0)
                {
                    break;
                }
                else
                {
                    // Top has been visited.
                    visited.insert(visited.end(), top);
                    // Add neighbours of top to the stack.
                    nodes.push(top-1);
                    nodes.push(top+1);


                }
            }
        }

    }


};


int main()
{
    // intArray board;
    // board.popArray();

    int boardarray [] = {  1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};

    pathfinding finder;
    float firstnode = finder.dfs(boardarray, 120);
}
