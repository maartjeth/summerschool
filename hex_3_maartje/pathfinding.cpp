// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include <stack>
#include <list>
#include <stack>
#include <algorithm>
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

bool Pathfinding::isValidNeighbour(int neighbour, int player, std::vector<int> arr, int nArrElements, int nCols, int position)
{
    // Check whether the position is on the board.
    if ((neighbour < nArrElements) && (neighbour >= 0))
    {
        // Check whether the position has already been visited.
        if (!isVisited(neighbour))
        {
            // Check whether the position is occupied by the current player.
            if (arr[neighbour] == player)
            {
                // When position is at end of row (right side of board) and
                // neighbour is on next row and at left side of board, it is
                // not a valid neighbour. (top + 1)
                if (((position+1)%nCols == 0) && (neighbour == position + 1))
                {
                    return false;
                }
                // When position is at beginning of row (left side of board) and
                // neighbour is on previous row and at right side of board, it is
                // not a valid neighbour. (top - 1)
                else if ((position%nCols == 0) && (neighbour == position -1))
                {
                    return false;
                }
                // FIXME: Points on opposite ends of a row are seen as neighbours.
                // // (top - nCols + 1)
                // else if (((position - nCols + 1) == neighbour) && ((position + 1)%nCols == 0))
                // {
                //     return false;
                // }
                //
                // // (top + nCols - 1)
                // else if (((position + nCols - 1) == neighbour) && ((neighbour + 1)%nCols ==0)
                // {
                //     return false;
                // }
                else {return true;}
            }
        }
    }
    return false;
}

void Pathfinding::populateNodes(std::vector<int> arr, int player, int nArrElements, int nCols, int nRows)
{
    // Adds the starting nodes on the stack, depending on the player.
    // Player 1 plays left to right.
    if (player == 1)
    {
        // Adds the starting nodes on the stack.
        for (int k = 0; k < nArrElements; k += nCols)
        {
            // If the position is claimed by the current player, adds to stack.
            if (arr[k] == 1)
            {
                // std::cout << "Found a starting node: " << k << std::endl; // NOTE: DEBUG
                nodes.push(k);
            }
        }
        // If the position is claimed by the current player, adds to list.
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
        // Adds the starting nodes on the stack.
        for (int k = 0; k < nRows; k++)
        {
            // If the position is claimed by the current player, adds to stack.
            if (arr[k] == -1)
            {
                // std::cout << "Found a starting node: " << k << std::endl; // NOTE: DEBUG
                nodes.push(k);
            }
        }
        for (int p = nArrElements - nCols; p < nArrElements; p++)
        {
            // If the position is claimed by the current player, adds to list.
            if (arr[p] == -1)
            {
                endNodes.insert(endNodes.end(), p);
            }
        }
    }
}

bool Pathfinding::dfs(std::vector<int> arr, int nRows, int nCols, int player)
{
    // Number of array elements.
    int nArrElements = nCols * nRows;

    // Determine the start and end nodes.
    populateNodes(arr, player, nArrElements, nCols, nRows);

    // NOTE: DEBUG TO SEE WHICH END NODES HAVE BEEN FOUND.
    // for( std::list<int>::iterator i = endNodes.begin(); i != endNodes.end(); ++i)
    //     {std::cout << "End nodes" << *i << std::endl;}

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
                    if (isValidNeighbour(neighbours[i], player, arr, nArrElements, nCols, top))
                    {
                        // Adds valid neighbours of top to the stack.
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
