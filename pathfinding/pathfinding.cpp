// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>
#include "pathfinding.hpp"

bool Pathfinding::isVisited(int position)
{
    // Check whether a position has been visited.
    if (find(visited.begin(), visited.end(), position) != visited.end())
    {
        return true;
    }
    return false;
}

bool Pathfinding::isValidNeighbour(int position, int player, int arr [], int nArrElements)
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

void Pathfinding::populateNodes(int arr [], int player, int nArrElements, int nCols, int nRows)
{
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
                // std::cout << "Found a starting node: " << k << std::endl; // NOTE: DEBUG
                nodes.push(k);
            }
        }
        // If the position is claimed by the current player, add to list.
        for (int p = nCols - 1; p < nArrElements; p+= nCols)
        {
            if (arr[p] == 1)
            {
                endNodes.insert(endNodes.end(), p);
            }
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
                // std::cout << "Found a starting node: " << k << std::endl; // NOTE: DEBUG
                nodes.push(k);
            }
        }
        for (int p = nArrElements - nCols; p < nArrElements; p++)
        {
            // If the position is claimed by the current player, add to list.
            if (arr[p] == -1)
            {
                endNodes.insert(endNodes.end(), p);
            }
        }
    }
}

bool Pathfinding::dfs(int arr [], int nRows, int nCols, int player)
{
    // Number of array elements.
    int nArrElements = nCols * nRows;

    // Determine the start and end nodes.
    populateNodes(arr, player, nArrElements, nCols, nRows);

    // NOTE: DEBUG TO SEE WHICH END NODES HAVE BEEN FOUND.
    // for( std::list<int>::iterator i = endNodes.begin(); i != endNodes.end(); ++i)
    //     {std::cout << *i << std::endl;}

    // While there are still nodes to be visited.
    while (!nodes.empty())
    {
        // print(nodes); // NOTE: DEBUG

        // Find the top of the stack.
        int top = nodes.top();
        // Remove the current value on the stack (otherwise infinite recursion!).
        nodes.pop();
        // std::cout << "Top: " << top << std::endl; // NOTE: DEBUG
        // If the top has not been visited.
        if (!isVisited(top))
        {
            // If we have come to the edge of the graph.
            if (find(endNodes.begin(), endNodes.end(), top) != endNodes.end())
            {
                // std::cout << "A path was found." << std::endl; // NOTE: DEBUG
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
    // No valid paths have been found. Clear the stack and list for the next round.
    // std::cout << "There is no valid path!" << std::endl; // NOTE: DEBUG
    visited.clear();
    endNodes.clear();
    while (!nodes.empty()) {nodes.pop();}
    return false;
}
