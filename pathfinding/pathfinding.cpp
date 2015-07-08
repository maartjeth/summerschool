// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>

class pathfinding
{
    /*
    Find a route through a board represented as an integer array by using
    Depth First Search.
    */

public:
    // List of nodes that have been visited.
    std::list<int> visited;
    // Stack of nodes still to visit.
    std::stack<int> nodes;

    bool isVisited()
    {

    }

    bool isValidNeighbour(int position, int player, std::list<int> visitednode, int nCols, int nRows)
    {
        // Number of array elements.
        int nArrElements;
        nArrElements = nCols * nRows;

        // Check whether the position is valid.
        if (position < nArrElements)
        {
            if (position >= 0)
            {
                return true;
            }
        }
        return false;
    }

    void dfs(int arr [], int startnode, int nRow, int nCols)
    {
        // Add first node to the stack.
        nodes.push(startnode);

        // Current player.
        int player;
        player = 1;

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
                // TODO:FIX THE FINAL VALUE.
                if ((top == 24) && (arr[top] == 1))
                {
                    std::cout << "A path was found." << std::endl;
                    break;
                }
                else
                {
                    // Top has been visited.
                    visited.insert(visited.end(), top);

                    // Add valid neighbours of top to the stack.
                    // TODO: MAKE SURE ALREADY VISITED NODES ARE NOT READDED.
                    if (isValidNeighbour(top-1, player, visited, nCols, nRow))
                    {
                        nodes.push(top-1);
                    }
                    if (isValidNeighbour(top+1, player, visited, nCols, nRow))
                    {
                        nodes.push(top+1);
                    }
                    if (isValidNeighbour(top+nCols, player, visited, nCols, nRow))
                    {
                        nodes.push(top+nCols);
                    }
                    if (isValidNeighbour(top + nCols - 1, player, visited, nCols, nRow))
                    {
                        nodes.push(top + nCols - 1);
                    }
                    if (isValidNeighbour(top - nCols, player, visited, nCols, nRow))
                    {
                        nodes.push(top - nCols);
                    }
                    if (isValidNeighbour(top - nCols + 1, player, visited, nCols, nRow))
                    {
                        nodes.push(top - nCols + 1);
                    }
                }
            }
        }
    }
};


int main()
{
    // intArray board;
    // board.popArray();
    int nRows, nCols;
    // nRows = 11;
    // nCols = 11;
    // int boardarray [] = {  1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 0, -1, 1, 1, 1, 1, 1, 1, 1, 1,
    //                         1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};
    nRows = 5;
    nCols = 5;
    int boardarray [] = {1,0,0,0,0,
                        1,1,1,0,0,
                        0,0,1,1,1,
                        0,0,0,0,1,
                        0,0,0,0,1};

    pathfinding finder;
    finder.dfs(boardarray, 0, nRows, nCols);
}
