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
    void dfs(int arr [], int startnode, int nRow, int nCols)
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
                TODO:FIX THE FINAL VALUE.
                if ((top == 24) && (arr[top] == 1))
                {
                    std::cout << "A path was found." << std::endl;
                    break;
                }
                else
                {
                    // Top has been visited.
                    visited.insert(visited.end(), top);
                    /*
                    Add neighbours of top to the stack if they are taken by
                    the current player.
                    The position has to be in the array.
                    TODO: MAKE SURE ALREADY VISITED NODES ARE NOT READDED.
                    */
                    if ((arr[top-1] == 1) && (top-1 > 0)) {
                        nodes.push(top-1);
                    }
                    if ((arr[top+1] == 1) && (top+1 > 0)) {
                        nodes.push(top+1);
                    }
                    if ((arr[top+nCols] == 1) && (top+nCols > 0)) {
                        nodes.push(top+nCols);
                    }
                    if ((arr[top + nCols - 1] == 1) && (top + nCols -1 > 0)) {
                        nodes.push(top + nCols - 1);
                    }
                    if ((arr[top - nCols] == 1)  && (top - nCols > 0)){
                        nodes.push(top - nCols);
                    }
                    if ((arr[top - nCols + 1] == 1) && (top - nCols + 1 > 0)) {
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
