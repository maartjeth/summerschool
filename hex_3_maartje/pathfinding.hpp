// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#ifndef PATHFINDING
#define PATHFINDING

#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Pathfinding
{
    /*
    Find a route through a board represented as an integer array by using
    Depth First Search.
    */

private:
    // List of nodes that have been visited.
    std::list<int> visited;
    /*
    Stack of nodes still to visit. Sometimes nodes are added multiple times to
    the stack. This is because nodes have multiple neighbours. This is so
    because there is no check to see whether a node is already on the stack.
    */
    std::stack<int> nodes;
    // Nodes to reach.
    std::list<int> endNodes;

    bool isVisited(int);
    bool isValidNeighbour(int, int, std::vector<int>, int, int, int);
    void populateNodes(std::vector<int> , int, int, int, int);

    // NOTE: DEBUG TO SEE WHAT IS ON THE STACK.
    // void print(std::stack<int> &s)
    // {
    //     if(s.empty())
    //     {
    //         std::cout << std::endl;
    //         return;
    //     }
    //     int x= s.top();
    //     s.pop();
    //     print(s);
    //     s.push(x);
    //     std::cout << x << " ";
    // }

public:
    bool dfs(std::vector<int>, int, int, int);
};

#endif
