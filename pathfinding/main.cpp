// A pathfinding algorithm to find a connected path in an integer array.
// author: Teun Zwart

#include <iostream>
#include "pathfinding.hpp"

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

    Pathfinding finder;
    finder.dfs(boardarray, nRows, nCols, 1);
    std::cout << std::endl;
    finder.dfs(boardarray2, nRows, nCols, -1);
    std::cout << std::endl;
    finder.dfs(boardarray3, nRows3, nCols3, 1);
    std::cout << std::endl;
    finder.dfs(boardarray3, nRows3, nCols3, 0);
}
