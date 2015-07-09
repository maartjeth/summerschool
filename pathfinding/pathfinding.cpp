// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>

// TODO: THROW EVERYTHING IN HEADER FILES?
// FIXME: SOLVE SOME NODES BEING VISITED MULTIPLE TIMES. IT STILL WORKS?!?

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
    // Nodes to reach.
    std::list<int> endNodes;

    bool isVisited(int position)
    // Check whether a position has been visited.
    {
        if (find(visited.begin(), visited.end(), position) != visited.end())
        {
            return true;
        }
        return false;
    }

    bool isValidNeighbour(int position, int player, int arr [], int nArrElements)
    {
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
    bool dfs(int arr [], int nRows, int nCols, int player)
    {
        // Number of array elements.
        int nArrElements = nCols * nRows;

        // Add the starting nodes on the stack, depending on the player.
        // Player 1 plays left to right.
        if (player == 1)
        {
            // Add the starting nodes on the stack.
            for (int k = 0; k < nArrElements; k += nCols)
            {
                // If the position is claimed by the current player, add to stack.
                if (arr[k] == 1)
                {
                    nodes.push(k);
                }
            }
            for (int p = nCols - 1; p < nArrElements; p+= nCols)
            {
                endNodes.insert(endNodes.end(), p);
            }
        }
        // Player -1 plays top to bottom.
        else if (player == -1)
        {
            // Add the starting nodes on the stack.
            for (int k = 0; k < nRows; k++)
            {
                // If the position is claimed by the current player, add to stack.
                if (arr[k] == -1)
                {
                    nodes.push(k);
                }
            }
            for (int p = nArrElements - nCols; p < nArrElements; p++)
            {
                endNodes.insert(endNodes.end(), p);
            }
        }

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
                if (find(endNodes.begin(), endNodes.end(), top) != endNodes.end())
                {
                    std::cout << "A path was found." << std::endl;
                    // Clear the stack and list for the next round.
                    visited.clear();
                    endNodes.clear();
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
                        if (isValidNeighbour(neighbours[i], player, arr, nArrElements))
                        {
                            // Add valid neighbours of top to the stack.
                            nodes.push(neighbours[i]);
                        }
                    }
                }
            }
        }
        // No valid paths have been found.
        std::cout << "There is no valid path!" << std::endl;
        // Clear the stack and list for the next round.
        visited.clear();
        endNodes.clear();
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
                            -1, -1, -1, -1, -1, -1, -1, 0, 1, 1, 1,
                            1, 1, 0, -1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, -1, -1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, -1, -1, -1, 0, 1, 1, 1,
                            1, -1, 0, 1, 1, -1, -1, 0, 1, 1, 1,
                            1, 1, -1, 0, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 0, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, 0, 1, 1, 1,
                            1, 1, 1, 1, 1, 1, -1, -1,-1, -1, -1, -1};
    int nRows3 = 5;
    int nCols3 = 5;
    int boardarray3 [] = {1,0,0,0,0,
                        1,1,1,0,0,
                        0,0,1,1,1,
                        0,0,0,0,1,
                        0,0,0,0,1};

    pathfinding finder;
    finder.dfs(boardarray, nRows, nCols, 1);
    std::cout << std::endl;
    finder.dfs(boardarray2, nRows, nCols, -1);
    std::cout << std::endl;
    finder.dfs(boardarray3, nRows3, nCols3, 1);
    std::cout << std::endl;
    finder.dfs(boardarray3, nRows3, nCols3, 0);
}
