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
private:
    // List of nodes that have been visited.
    std::list<int> visited;
    // Stack of nodes still to visit.
    std::stack<int> nodes;

    bool isVisited(int position)
    // Check whether a position ahs been visited.
    {
        if (find(visited.begin(), visited.end(), position) == visited.end())
        {
            return true;
        }
        return false;
    }

    bool isValidNeighbour(int position, int player, int nCols, int nRows, int arr [])
    {
        // Number of array elements.
        int nArrElements;
        nArrElements = nCols * nRows;

        // Check whether the position is valid.
        if (position < nArrElements)
        {
            if (position >= 0)
            {
                // Check whether the position has already been visited.
                if (isVisited(position))
                {
                    // Check whether the position is occupied by the current player.
                    if (arr[position] == player)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

public:
    void dfs(int arr [], int startnode, int nRows, int nCols, int player)
    {
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
            if (isVisited(top))
            {
                // If we have come to the edge of the graph.
                // TODO:FIX THE FINAL VALUE.
                if (top == 120)
                {
                    std::cout << "A path was found." << std::endl;
                    break;
                }
                else
                {
                    std::cout << "No path was found." << std::endl;
                    
                    // Top has been visited.
                    visited.insert(visited.end(), top);

                    // Add valid neighbours of top to the stack.
                    if (isValidNeighbour(top-1, player, nCols, nRows, arr))
                    {
                        nodes.push(top-1);
                    }
                    if (isValidNeighbour(top+1, player, nCols, nRows, arr))
                    {
                        nodes.push(top+1);
                    }
                    if (isValidNeighbour(top+nCols, player, nCols, nRows, arr))
                    {
                        nodes.push(top+nCols);
                    }
                    if (isValidNeighbour(top + nCols - 1, player, nCols, nRows, arr))
                    {
                        nodes.push(top + nCols - 1);
                    }
                    if (isValidNeighbour(top - nCols, player, nCols, nRows, arr))
                    {
                        nodes.push(top - nCols);
                    }
                    if (isValidNeighbour(top - nCols + 1, player, nCols, nRows, arr))
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
    int nRows, nCols;

    nRows = 11;
    nCols = 11;

    int boardarray [] = {  1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};

    // int boardarray [] = {  -1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 0, -1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 0, -1, -1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 1, 1, -1, 1, -1, 0, 1, 1, 1,
    //                         1, -1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
    //                         1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 0, -1, 1, 1, 1, 1, 1, 1, 1, 1,
    //                         1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
    //                         1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};
    // nRows = 5;
    // nCols = 5;
    // int boardarray [] = {1,0,0,0,0,
    //                     1,1,1,0,0,
    //                     0,0,1,1,1,
    //                     0,0,0,0,1,
    //                     0,0,0,0,1};

    pathfinding finder;
    finder.dfs(boardarray, 0, nRows, nCols, 1);
}
