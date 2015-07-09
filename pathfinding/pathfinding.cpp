// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>

// TODO: THROW EVERYTHING IN HEADER FILES?

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
    // Check whether a position has been visited.
    {
        if (find(visited.begin(), visited.end(), position) != visited.end())
        {
            return true;
        }
        return false;
    }

    bool isValidNeighbour(int position, int player, int nCols, int nRows, int arr [])
    {
        // Number of array elements.
        int nArrElements = nCols * nRows;

        // Check whether the position is on the board.
        if ((position < nArrElements) && (position >= 0))
        {
            // Check whether the position has already been visited.
            if (!isVisited(position))
            {
                // Check whether the position is occupied by the current player.
                if (arr[position] == player)
                {
                    return true;
                }
            }
        }
        return false;
    }


public:
    bool dfs(int arr [], int startnode, int nRows, int nCols, int player)
    {
        // Add first node to the stack.
        nodes.push(startnode);

        // While there are still nodes to be visited.
        while (!nodes.empty())
        {
            // Find the top of the stack.
            int top = nodes.top();
            // Remove the current value on the stack (otherwise infinite recursion!).
            nodes.pop();
            std::cout << "Top: " << top << std::endl; // NOTE: DEBUG
            // If the top has not been visited.
            if (!isVisited(top))
            {
                // If we have come to the edge of the graph.
                // TODO: FIX THE FINAL VALUE.
                if (top == 120)
                {
                    std::cout << "A path was found." << std::endl;
                    // Clear the stack and list for the next round.
                    visited.clear();
                    while (!nodes.empty()) {nodes.pop();}
                    return true;
                }
                else
                {
                    // Top has been visited.
                    visited.insert(visited.end(), top);

                    // Get a list of neighbours.
                    int neighbours[6] = {top-1,top+1,top+nCols,top+nCols-1,top-nCols,top-nCols+1};

                    for (int i = 0; i < 6; i++)
                    {
                        if (isValidNeighbour(neighbours[i], player, nCols, nRows, arr))
                        {
                            // Add valid neighbours of top to the stack.
                            nodes.push(neighbours[i]);
                        }
                    }
                }
            }
        }
        // No valid paths have been found
        std::cout << "There is no valid path!" << std::endl; // NOTE: DEBUG
        // Clear the stack and list for the next round.
        visited.clear();
        while (!nodes.empty()) {nodes.pop();}
        return false;
    }
};


int main()
{
    int nRows = 11;
    int nCols = 11;

    int boardarray [] = {  1, -1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, -1, -1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, -1, -1, 0, 1, 1, 1};

    int boardarray2 [] = {  -1, -1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            -1, -1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, -1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, -1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, -1, 1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1};
    int nRows3 = 5;
    int nCols3 = 5;
    int boardarray3 [] = {1,0,0,0,0,
                        1,1,1,0,0,
                        0,0,1,1,1,
                        0,0,0,0,1,
                        0,0,0,0,1};

    pathfinding finder;
    finder.dfs(boardarray, 0, nRows, nCols, 1);
    std::cout << std::endl;
    finder.dfs(boardarray2, 0, nRows, nCols, -1);
    std::cout << std::endl;
    finder.dfs(boardarray3, 0, nRows3, nCols3, 1);
}
